class Plant:
    def __init__(self, name: str, height: float, age_days: int, growth: float = 0.8) -> None:
        self._name: str = name
        self._height: float = 0.0
        self._age_days: int = 0
        self._growth: float = growth
        self.set_height(height, silent=True)
        self.set_age(age_days, silent=True)
        self._stats = Plant.Stats()

    class Stats:
        def __init__(self):
            self._growth_count: int = 0
            self._age_count: int = 0
            self._show_count: int = 0
        
        def growth_call(self) -> None:
            self._growth_count += 1
        
        def age_call(self)-> None:
            self._age_count += 1
        
        def show_call(self)-> None:
            self._show_count += 1
        
        def display(self)-> None:
            print(f"Stats: {self._growth_count} grow, {self._age_count} age, {self._show_count} show")
    
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
        print(self)

class Flower(Plant):
    def __init__(self, name: str, height: float, age_days: int, color: str, growth: float = 0.8):
        super().__init__(name, height, age_days, growth)
        self._color: str = color
        self._bloomed: bool = False

    def show(self)-> None:
        print(self)
        print(f" Color: {self._color}")
        if self._bloomed:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")

    def bloom(self)-> None:
        self._bloomed = True
        self.show()
        
class Seed(Flower):
    def __init__(self, name: str, height: float, age_days: int, color: str, growth: float = 0.8):
        super().__init__(name, height, age_days, color, growth)
        self.seeds_nb: int = 0

    def show(self)-> None:
        super().show()
        print(f"Seeds: {self.seeds_nb}")
    
    def bloom(self, seeds_nb: int)-> None:
        self.seeds_nb = seeds_nb
        super().bloom()
    
class Tree(Plant):
    def __init__(self, name: str, height: float, age_days: int, trunk_diameter: float):
        super().__init__(name, height, age_days)
        self._trunk_diameter: float = trunk_diameter

    def show(self)-> None:
        print(self)
        print(f" Trunk diameter: {self._trunk_diameter}cm")
    
    def produce_shade(self)-> None:
        print(f"Tree {self._name} now produces a shade of {self._height}cm long and {self._trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age_days: int, harvest_season: str, growth: float = 0.8):
        super().__init__(name, height, age_days, growth)
        self._harvest_season: str = harvest_season
        self._nutritional_value: int = 0
    
    def grow(self) -> None:
        super().grow()

    def age(self) -> None:
        super().age()
        self._nutritional_value += 1

    def show(self)-> None:
        print(self)
        print(f" Harvest season: {self._harvest_season}\n Nutritional value: {self._nutritional_value}")

def display_statitics(plant: Plant)-> None:
    print(f"[statistics for {plant._name}]")
    plant._stats.display()

def main():
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    display_statitics(rose)
    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print("[oak to produce shade]")
    oak.produce_shade()
    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow", 1.5)
    sunflower.show()
    print("[asking the sunflower to grow, age and bloom]cd")
    for day in range(20):
        sunflower.grow()
        sunflower.age()
    sunflower.bloom(42)


if __name__ == "__main__":
    main()

    

