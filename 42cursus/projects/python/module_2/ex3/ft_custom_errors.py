class GardenError(Exception):
    def __init__(self, message_error: str = "Unknown plant error") -> None:
        super().__init__(f"{message_error}")


class PlantError(GardenError):
    def __init__(self, message_error: str = " Unknown plant error") -> None:
        super().__init__(f"{message_error}")


class WaterError(GardenError):
    def __init__(self, message_error: str = "Unknown plant error") -> None:
        super().__init__(f"{message_error}")


def check_plant_status(is_wilting: bool) -> None:
    if is_wilting:
        raise PlantError("The tomato plant is wilting!")
    else:
        print("Plant is ok!")


def check_water_tank(volume: int) -> None:
    if volume < 2:
        raise WaterError(" Not enough water in the tank!")
    else:
        print("Tank volume is ok!")


def test_custom_errors() -> None:
    print("=== Custom Garden Errors Demo ===\n")
    try:
        print("Testing PlantError...")
        check_plant_status(is_wilting=True)
    except PlantError as e:
        print(f"Caught PlantError: {e}\n")
    try:
        print("Testing WaterError...")
        check_water_tank(volume=1)
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    try:
        print("Testing catching all garden errors...")
        check_plant_status(is_wilting=True)
    except GardenError as e:
        print(f"Caught GardenError: {e}\n")
    try:
        check_water_tank(volume=1)
    except GardenError as e:
        print(f"Caught GardenError: {e}\n")
    print("All custom error types work correctly!")
