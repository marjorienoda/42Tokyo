import sys
import typing


def read_file(file: typing.IO) -> None:
    print("---")
    print(file.read(), end="")
    print("---")
    file.close()
    print(f"File '{file.name}' closed")


def main() -> None:
    print("=== Cyber Archives Recovery ===")
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return
    for name in sys.argv[1:]:
        try:
            print(f"Accessing file '{name}'")
            file = open(name, "r")
        except OSError as e:
            print(f"Error opening file '{name}': {e}")
        else:
            read_file(file)


if __name__ == "__main__":
    main()
