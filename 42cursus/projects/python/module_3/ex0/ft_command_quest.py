import sys


def main() -> None:
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    total = len(sys.argv)
    arguments = sys.argv[1:]
    counter = 1
    if total == 1:
        print("No arguments provided!")
    else:

        for arg in arguments:
            print(f"Argument: {counter}: {arg}")
            counter += 1
    print(f"Total arguments: {total}")
