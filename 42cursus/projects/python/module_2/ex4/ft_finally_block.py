class GardenError(Exception):
    def __init__(self, message_error: str = "Unknown plant error") -> None:
        super().__init__(f"{message_error}")


class PlantError(GardenError):
    def __init__(self, message_error: str = " Unknown plant error") -> None:
        super().__init__(f"{message_error}")


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("=== Garden Watering System ===\n")

    try:
        print("Testing valid plants..")
        print("Opening watering system")
        valid_plants = ["Tomato", "Lettuce", "Carrots"]
        try:
            for plant in valid_plants:
                water_plant(plant)
        except PlantError as e:
            print(f"Caught PlantError: {e}")
            print(".. ending tests and returning to main")
            return
        finally:
            print("Closing watering system\n")

        print("Testing invalid plants..")
        print("Opening watering system")
        valid_plants = ["Tomato", "lettuce", "Carrots"]
        try:
            for plant in valid_plants:
                water_plant(plant)
        except PlantError as e:
            print(f"Caught PlantError: {e}")
            print(".. ending tests and returning to main")
            return
        finally:
            print("Closing watering system\n")
    finally:
        print("Cleanup always happens, even with errors!")
