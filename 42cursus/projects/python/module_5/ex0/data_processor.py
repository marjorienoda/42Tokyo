from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.content: list = []
        self.rank: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        return self.content.pop(0)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
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
    def validate(self, data: Any) -> bool:
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

    def validate(self, data: Any) -> bool:
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


def main() -> None:
    print("=== Code Nexus - Data Processor ===\n")

    test_numeric = 42
    numeric_data: list[int | float] = [1, 2, 3, 4, 5]
    test_str = "Hello"

    print("Testing Numeric Processor...")
    np = NumericProcessor()
    print(
        f"Trying to validate input '{test_numeric}': "
        f"{np.validate(test_numeric)}"
    )
    print(
        f"Trying to validate input '{test_str}': "
        f"{np.validate(test_str)}"
    )

    print(
        f"Test invalid ingestion of string '{test_str}' "
        f"without prior validation:"
    )
    try:
        np.ingest(test_str)
    except TypeError as e:
        print(f"Got exception: {e}")

    print(f"Processing data: {numeric_data}")
    np.ingest(numeric_data)
    print("Extracting 3 values...")
    for i in range(3):
        rank, content = np.output()
        print(f"Numeric value {i}: {content}")

    print("\nTesting Text Processor...")
    tp = TextProcessor()
    text_data = ["Hello", "Nexus", "World"]

    print(
        f"Trying to validate input '{test_numeric}': "
        f"{tp.validate(test_numeric)}"
    )
    print(
        f"Trying to validate input '{test_str}': "
        f"{tp.validate(test_str)}"
    )
    print(
        f"Test invalid ingestion of int '{test_numeric}' "
        f"without prior validation:"
    )
    try:
        tp.ingest(test_numeric)
    except TypeError as e:
        print(f"Got exception: {e}")

    print(f"Processing data: {text_data}")
    tp.ingest(text_data)
    print("Extracting 1 value...")
    rank, value = tp.output()
    print(f"Text value 0: {value}")

    # --- Log Processor ---
    print("\nTesting Log Processor...")
    lp = LogProcessor()
    log_data = [
        {"log_level": "NOTICE", "log_message": "Connection to server"},
        {"log_level": "ERROR", "log_message": "Unauthorized access!!"},
    ]
    print(f"Trying to validate input '{test_str}': {lp.validate(test_str)}")
    print(f"Trying to validate input '{log_data}': {lp.validate(log_data)}")

    invalid_log_ingest = {"log_level": "INFO", "log_message": 42}
    print(
        "Test invalid ingestion of dict with non-string value "
        "without prior validation:"
    )
    try:
        lp.ingest(invalid_log_ingest)
    except TypeError as e:
        print(f"Got exception: {e}")

    print(f"Processing data: {log_data}")
    lp.ingest(log_data)
    print("Extracting 2 values...")
    for i in range(2):
        rank, value = lp.output()
        print(f"Log entry {i}: {value}")


if __name__ == "__main__":
    main()
