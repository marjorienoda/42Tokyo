class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        growth: float = 0.8
    ) -> None:
        self._name: str = name
        self._height: float = 0.0
        self._age_days: int = 0
        self._growth: float = growth
        self.set_height(height, silent=True)
        self.set_age(age_days, silent=True)

    def grow(self) -> None:
        self._height = round(self._height + self._growth, 1)

    def age(self) -> None:
        self._age_days += 1

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_days

    def set_height(self, height: float, silent: bool = False) -> None:
        if height < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
            return
        self._height = round(float(height), 1)
        if not silent:
            print(f"Height updated: {int(height)}cm")

    def set_age(self, age_days: int, silent: bool = False) -> None:
        if age_days < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
            return
        self._age_days = age_days
        if not silent:
            print(f"Age updated: {int(self._age_days)} days")

    def show(self) -> None:
        print(f"Plant created: {self}")

    def __str__(self) -> str:
        return f"{self._name}: {self._height}cm, {self._age_days} days old"


class Flower(Plant):
    def __init__(self, name: str, height: float, age_days: int, color: str):
        super().__init__(name, height, age_days)
        self._color: str = color
        self._bloomed: bool = False

    def show(self) -> None:
        print(self)
        print(f" Color: {self._color}")
        if self._bloomed:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")

    def bloom(self) -> None:
        self._bloomed = True
        self.show()


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        trunk_diameter: float
    ):
        super().__init__(name, height, age_days)
        self._trunk_diameter: float = trunk_diameter

    def show(self) -> None:
        print(self)
        print(f" Trunk diameter: {self._trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(
            f"Tree {self._name} now produces a shade of "
            f"{self._height}cm long and {self._trunk_diameter}cm wide."
        )


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        harvest_season: str,
        growth: float = 0.8
    ):
        super().__init__(name, height, age_days, growth)
        self._harvest_season: str = harvest_season
        self._nutritional_value: int = 0

    def grow(self) -> None:
        super().grow()

    def age(self) -> None:
        super().age()
        self._nutritional_value += 1

    def show(self) -> None:
        print(self)
        print(f" Harvest season: {self._harvest_season}")
        print(f" Nutritional value: {self._nutritional_value}")


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print("[oak to produce shade]")
    oak.produce_shade()
    print("\n=== Vegetable")
    tomato = Vegetable("Tomato", 5.0, 10, "April", 2.1)
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    for day in range(20):
        tomato.grow()
        tomato.age()
    tomato.show()


if __name__ == "__main__":
    main()
