class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        growth: float
    ) -> None:
        self.name: str = name
        self.height: float = height
        self.age_days: int = age_days
        self.growth: float = growth

    def grow(self) -> None:
        self.height = round(self.height + self.growth, 1)

    def age(self) -> None:
        self.age_days += 1

    def __str__(self) -> str:
        return f"{self.name}: {self.height}cm, {self.age_days} days old"


def main() -> None:
    plant1: Plant = Plant("Rose", 25.0, 30, 0.8)

    print("=== Garden Plant Growth ===")
    print(plant1)

    initial_height = plant1.height

    for day in range(1, 8):
        plant1.grow()
        plant1.age()
        print(f"=== Day {day} ===")
        print(plant1)

    weekly_growth = round(plant1.height - initial_height, 1)

    print(f"Growth this week: {weekly_growth}cm")


if __name__ == "__main__":
    main()
