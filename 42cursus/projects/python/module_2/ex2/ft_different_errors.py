def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        1/0
    elif operation_number == 2:
        open("/non/existent/file", "r")
    elif operation_number == 3:
        "hello" + 3
    else:
        return


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    operation_numbers = [0, 1, 2, 3, 4]
    for i in operation_numbers:
        try:
            print(f"Testing operation {i}...")
            garden_operations(i)
            print("Operation completed successfully\n")
        except (ValueError, ZeroDivisionError, FileNotFoundError,
                TypeError) as e:
            error_name = e.__class__.__name__
            print(f"Caught {error_name}: {e}")
    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
