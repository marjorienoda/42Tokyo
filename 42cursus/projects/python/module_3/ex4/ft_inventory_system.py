import sys


class InventorySystem:
    def __init__(self) -> None:
        self.inventory: dict[str, int] = {}

    def add_item(self, name: str, quantity: int) -> None:
        self.inventory[name] = quantity

    def parse_args(self, args: list[str]) -> None:
        for arg in args:
            elements = arg.split(":")
            if len(elements) != 2:
                print(f"Error - invalid parameter '{arg}'")
                continue
            name, raw_quantity = elements
            if name in self.inventory:
                print(f"Redundant item '{name}' - discarding")
                continue
            try:
                quantity = int(raw_quantity)
            except ValueError as e:
                print(f"Quantity error for '{name}': {e}")
                continue
            self.add_item(name, quantity)

    def display(self, label: str = "Got inventory") -> None:
        print(f"{label}: {self.inventory}")

    def item_list(self) -> list[str]:
        return list(self.inventory.keys())

    def total_quantity(self) -> int:
        return sum(self.inventory.values())

    def percentages(self) -> None:
        total = self.total_quantity()
        for key in self.inventory.keys():
            percentage = round(self.inventory[key] / total * 100, 1)
            print(f"Item {key} represents {percentage}%")

    def most_abundant(self) -> str:
        items = list(self.inventory.keys())
        actual_item = items[0]
        for i in items:
            if self.inventory[i] > self.inventory[actual_item]:
                actual_item = i
        return actual_item

    def least_abundant(self) -> str:
        items = list(self.inventory.keys())
        actual_item = items[0]
        for i in items:
            if self.inventory[i] < self.inventory[actual_item]:
                actual_item = i
        return actual_item

    def update_item(self, name: str, quantity: int) -> None:
        self.inventory.update({name: quantity})


def main() -> None:
    print("=== Inventory System Analysis ===")
    system = InventorySystem()
    system.parse_args(sys.argv[1:])
    system.display()
    items = system.item_list()
    print(f"Item list: {items}")
    total = system.total_quantity()
    print(f"Total quantity of the {len(system.inventory)} items: {total}")
    system.percentages()
    most = system.most_abundant()
    print(f"Item most abundant: {most} with quantity {system.inventory[most]}")
    least = system.least_abundant()
    print(
        f"Item least abundant: {least}"
        f" with quantity {system.inventory[least]}"
    )
    system.update_item("magic_item", 1)
    system.display("Updated inventory")


if __name__ == "__main__":
    main()
