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


def main() -> None:
    print("=== Code Nexus - Data Stream ===\n")

    print("Initialize Data Stream...")
    ds = DataStream()
    ds.print_processors_stats()

    print("\nRegistering Numeric Processor")
    np = NumericProcessor()
    ds.register_processor(np)

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

    print("\nRegistering other data processors")
    tp = TextProcessor()
    lp = LogProcessor()
    ds.register_processor(tp)
    ds.register_processor(lp)

    print("Send the same batch again")
    ds.process_stream(batch)
    ds.print_processors_stats()

    print(
        "\nConsume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )
    np.output()
    np.output()
    np.output()
    tp.output()
    tp.output()
    lp.output()
    ds.print_processors_stats()


if __name__ == "__main__":
    main()
