import sys
import typing


def read_file(file: typing.IO[str]) -> str:
    content = file.read()
    print("---")
    print(content.rstrip)
    print("---")
    return content


def transform_data(content: str) -> str:
    new_line = ""
    print("Transform data:")
    print("---")
    for line in content.split("\n"):
        if line:
            new_line += line + "#\n"
            print(line + "#")
    print("---")
    return new_line


def save_file(new_line: str) -> None:
    new_file_name = input("Enter new file name (or empty): ")
    if not new_file_name:
        print("Not saving data.")
        return
    else:
        try:
            file: typing.IO[str] = open(new_file_name, "w")
        except OSError as e:
            print(f"Error saving file '{new_file_name}': {e}")
            return
        file.write(new_line)
        print(f"Saving data to '{new_file_name}'")
        file.close()
        print(f"Data saved in file '{new_file_name}'.")


def main() -> None:
    print("=== Cyber Archives Recovery & Preservation ===")
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
            content = read_file(file)
            file.close()
            print(f"File '{file.name}' closed.")
            new_file = transform_data(content)
            save_file(new_file)


if __name__ == "__main__":
    main()
