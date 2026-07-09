def secure_archive(
    file_name: str,
    action: str = "r",
    content: str = ""
) -> tuple[bool, str]:
    try:
        if action == "r":
            with open(file_name, action) as file:
                content = file.read()
                return (True, content)
        elif action == "w":
            with open(file_name, action) as file:
                file.write(content)
                return (True, "Content successfully written to file")
        else:
            raise ValueError(f"Invalid mode: '{action}'")
    except (OSError, ValueError) as e:
        return (False, str(e))


def main() -> None:
    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("file"))
    print()

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("test.txt"))
    print()

    print("Using 'secure_archive' to read from a regular file:")
    success, content = secure_archive("ancient_fragment.txt")
    print(f"{(success, content)}")
    print()

    success, msg = secure_archive("new_file.txt", "w", content)
    print(
        f"Using 'secure_archive' to write previous content "
        f"to a new file: {(success, msg)}"
    )


if __name__ == "__main__":
    main()
