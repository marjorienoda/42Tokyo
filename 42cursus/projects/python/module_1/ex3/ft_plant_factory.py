class Plant:
    def __init__(self, name: str, height: float, age_days: int, growth: float = 0.8) -> None:
        self.name: str = name
        self.height: float = height
        self.age_days: int = age_days
        self.growth: float = growth

    def grow(self) -> None:
        self.height = round(self.height + self.growth, 1)
    
    def age(self) -> None:
        self.age_days += 1
    
    def show(self) -> None:
        print(f"Created: {self}")

    def __str__(self) -> str:
        return f"{self.name}: {self.height}cm, {self.age_days} days old"
    
def main() -> None:
    plants = [
        Plant("Rose", 25.0, 30),
        Plant("Oak", 200.0, 365),
        Plant("Cactus", 5.0, 90),
        Plant("Sunflower", 80.0, 45),
        Plant("Fern", 15.0, 120)
    ]

    print("=== Plant Factory Output ===")
    for plant in plants:
        plant.show()

if __name__ == "__main__":
    main()

    

