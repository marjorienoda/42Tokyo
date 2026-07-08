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
        self._stats = Plant.Stats()

    class Stats:
        def __init__(self) -> None:
            self._growth_count: int = 0
            self._age_count: int = 0
            self._show_count: int = 0

        def growth_call(self) -> None:
            self._growth_count += 1

        def age_call(self) -> None:
            self._age_count += 1

        def show_call(self) -> None:
            self._show_count += 1

        def display(self) -> None:
            stats = (f"Stats: {self._growth_count} grow, "
                     f"{self._age_count} age, {self._show_count} show")
            print(stats)

    def __str__(self) -> str:
        return f"{self._name}: {self._height}cm, {self._age_days} days old"

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown", 0.0, 0)

    @staticmethod
    def is_older_than_a_year(age_days: int) -> bool:
        return age_days > 365

    def grow(self) -> None:
        self._height = round(self._height + self._growth, 1)
        self._stats.growth_call()

    def age(self) -> None:
        self._age_days += 1
        self._stats.age_call()

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
        print(self)
        self._stats.show_call()


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        color: str,
        growth: float = 0.8
    ):
        super().__init__(name, height, age_days, growth)
        self._color: str = color
        self._bloomed: bool = False

    def show(self) -> None:
        super().show()
        print(f" Color: {self._color}")
        if self._bloomed:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")

    def bloom(self) -> None:
        self._bloomed = True
        self.show()


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        color: str,
        growth: float = 0.8
    ):
        super().__init__(name, height, age_days, color, growth)
        self.seeds_nb: int = 0

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seeds_nb}")

    def bloom(self, seeds_nb: int = 0) -> None:
        self.seeds_nb = seeds_nb
        super().bloom()


class Tree(Plant):
    class Stats(Plant.Stats):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count: int = 0

        def shade_call(self) -> None:
            self._shade_count += 1

        def display(self) -> None:
            super().display()
            print(f" {self._shade_count} shade")

    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        trunk_diameter: float
    ):
        super().__init__(name, height, age_days)
        self._trunk_diameter: float = trunk_diameter
        self._stats = Tree.Stats()

    def show(self) -> None:
        print(self)
        self._stats.show_call()
        print(f" Trunk diameter: {self._trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(
            f"Tree {self._name} now produces a shade of "
            f"{self._height}cm long and {self._trunk_diameter}cm wide."
        )
        assert isinstance(self._stats, Tree.Stats)
        self._stats.shade_call()


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
        self._stats.show_call()
        print(f" Harvest season: {self._harvest_season}")
        print(f" Nutritional value: {self._nutritional_value}")


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant._name}]")
    plant._stats.display()


def main() -> None:
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_a_year(30)}")
    result = Plant.is_older_than_a_year(400)
    print(f"Is 400 days more than a year? -> {result}")

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red", 8.0)
    rose.show()
    display_statistics(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    display_statistics(rose)

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_statistics(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_statistics(oak)

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow", 1.5)
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    for day in range(20):
        sunflower.grow()
        sunflower.age()
    sunflower.bloom(42)
    display_statistics(sunflower)

    print("\n=== Anonymous")
    unknown = Plant.anonymous()
    unknown.show()
    display_statistics(unknown)


if __name__ == "__main__":
    main()
