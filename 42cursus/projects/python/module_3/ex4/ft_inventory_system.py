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
            name, quantity = elements
            if name in self.inventory:
                print(f"Redundant item '{name}' - discarding")
                continue
            try:
                quantity = int(quantity)
            except ValueError as e:
                print(f"Quantity error for '{name}': {e}")
                continue
            self.add_item(name, quantity)

    def display(self) -> None:
        print(f"Got inventory: {self.inventory}")

    # def item_list(self) -> list[str]:
    #     #return list of keys
    
    # def total_quantity(self) -> int:
    #     # sum of values
    
    # def percentages(self) -> None:
    #     # for each item, quantity / total * 100

    # def most_abundant(self) -> str:
    #     # item with the highest quantity

    # def least_abundant(self) -> str:

    # def update_item(self, name: str, quantity: int) -> None:
    #     # use dict.update()

def main():
    system = InventorySystem()
    system.parse_args(sys.argv[1:])
    system.display()
if __name__ == "__main__":
    main()