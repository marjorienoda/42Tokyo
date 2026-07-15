import typing
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self.content: list = []
        self.rank: int = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        return self.content.pop(0)


class NumericProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            return all(isinstance(item, (int, float)) for item in data)
        else:
            return False

    def ingest(self, data: (int | float) | list[int | float]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                items = data
            else:
                items = [data]
            for item in items:
                self.content.append((self.rank, str(item)))
                self.rank += 1
        else:
            raise TypeError("Improper numeric data")


class TextProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        else:
            return False

    def ingest(self, data: str | list[str]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                items = data
            else:
                items = [data]
            for item in items:
                self.content.append((self.rank, item))
                self.rank += 1
        else:
            raise TypeError("Improper text data")


class LogProcessor(DataProcessor):
    def is_valid_dict(self, data: dict[str, str]) -> bool:
        return all(
            isinstance(k, str) and
            isinstance(v, str) for k, v in data.items()
        )

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, dict):
            return self.is_valid_dict(data)
        elif isinstance(data, list):
            return all(
                isinstance(d, dict) and self.is_valid_dict(d) for d in data
            )
        else:
            return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                items = data
            else:
                items = [data]
            for item in items:
                d = ": ".join(item.values())
                self.content.append((self.rank, d))
                self.rank += 1
        else:
            raise TypeError("Improper log data")


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class CsvPlugin():
    def process_output(self, data: list[tuple[int, str]]) -> None:
        list_value: list = [value for rank, value in data]
        output_str: str = ",".join(list_value)
        print(f"CSV Output: {output_str}")


class JSONPlugin():
    def process_output(self, data: list[tuple[int, str]]) -> None:
        list_value: list = []
        for rank, value in data:
            list_value.append(f'"item_{rank}": "{value}"')
        output_str = ", ".join(list_value)
        print(f"JSON Output: {{{output_str}}}")


class DataStream():
    def __init__(self) -> None:
        self.processors: list = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for element in stream:
            processed: bool = False
            for proc in self.processors:
                if proc.validate(element):
                    proc.ingest(element)
                    processed = True
                    break
            if not processed:
                print(
                    f"DataStream error - "
                    f"Can't process element in stream: {element}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
        for proc in self.processors:
            raw_name = proc.__class__.__name__
            class_name: str = raw_name.replace("Processor", " Processor")
            print(
                f"{class_name}: total {proc.rank} items processed, "
                f"remaining {len(proc.content)} on processor"
            )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self.processors:
            batch: list = []
            for n in range(nb):
                if len(proc.content) > 0:
                    batch.append(proc.output())
                else:
                    break
            plugin.process_output(batch)


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===\n")

    print("Initialize Data Stream...")
    ds = DataStream()
    ds.print_processors_stats()

    print("\nRegistering Processors")
    np = NumericProcessor()
    tp = TextProcessor()
    lp = LogProcessor()
    ds.register_processor(np)
    ds.register_processor(tp)
    ds.register_processor(lp)

    batch: list[typing.Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead",
            },
            {
                "log_level": "INFO",
                "log_message": "User wil is connected",
            },
        ],
        42,
        ["Hi", "five"],
    ]

    print(f"Send first batch of data on stream: {batch}")
    ds.process_stream(batch)
    ds.print_processors_stats()

    csv_plugin = CsvPlugin()
    json_plugin = JSONPlugin()
    print("\nSend 3 processed data from each processor to a CSV plugin:")
    ds.output_pipeline(3, csv_plugin)

    ds.print_processors_stats()

    batch2: list[typing.Any] = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {
                "log_level": "ERROR",
                "log_message": "500 server crash",
            },
            {
                "log_level": "NOTICE",
                "log_message": "Certificate expires in 10 days",
            },
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello",
    ]

    print(f"Send another batch of data: {batch2}")
    ds.process_stream(batch2)
    ds.print_processors_stats()

    print("Send 5 processed data from each processor to a JSON plugin:")
    ds.output_pipeline(5, json_plugin)
    ds.print_processors_stats()


if __name__ == "__main__":
    main()
