class Plant:
    def __init__(self, name: str, height: float, age_days: int, growth: float = 0.8) -> None:
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
    
    def get_height(self)-> float:
        return self._height
    
    def get_age(self)-> int:
        return self._age_days
    
    def set_height(self, height: float, silent: bool = False) ->None:
        if height < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
            return
        self._height = round(float(height), 1)
        if not silent:
            print(f"Height updated: {int(height)}cm")

    def set_age(self, age_days: int, silent: bool = False) ->None:
        if age_days < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
            return
        self._age_days= age_days
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
    
    def bloom(self):
    
    def show(self)-> None:
        
class Tree(Plant):
    def __init__(self, name: str, height: float, age_days: int, trunk_diameter: int):
        super().__init__(name, height, age_days)
        self.trunk_diameter: int = trunk_diameter

    def produce_shade(self)

class Vegetable(Plant):
    def __init__(self, name: str, height: float, age_days: int, harvest_season: str, nutritional_value: int):
        super().__init__(name, height, age_days)
        self._harvest_season: str = harvest_season
        self._nutritional_value: int = 0
def main():
    print("=== Garden Security System ===")

    rose = Plant("Rose", 15.0, 10)
    rose.show()
    print()
    rose.set_height(25)
    rose.set_age(30)
    print()
    rose.set_height(-5)
    rose.set_age(-3)
    print()
    print(f"Current state: {rose}")

if __name__ == "__main__":
    main()

    

