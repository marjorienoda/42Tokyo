import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        try:
            user_input = input(
                "Enter new coordinates as floats in format 'x,y,z': "
            )
            x, y, z = [p.strip() for p in user_input.split(",")]
        except ValueError:
            print("Invalid syntax")
            continue

        coordinates_list = []
        for i in (x, y, z):
            try:
                coordinates_list.append(float(i))
            except ValueError:
                print(
                    f"Error on parameter '{i}': "
                    f"could not convert string to float: '{i}'"
                )
                break
        else:
            return (
                coordinates_list[0],
                coordinates_list[1],
                coordinates_list[2]
            )


def distance(pos1: tuple[float, float, float],
             pos2: tuple[float, float, float]) -> float:
    return math.sqrt(
        (pos1[0] - pos2[0]) ** 2
        + (pos1[1] - pos2[1]) ** 2
        + (pos1[2] - pos2[2]) ** 2
    )


def main() -> None:
    print("=== Game Coordinate System ===\n")

    center_pos = (0.0, 0.0, 0.0)
    print("Get a first set of coordinates")
    player1_pos = get_player_pos()
    print(f"Got a first tuple: {player1_pos}")
    print(
        f"It includes: X={player1_pos[0]}, "
        f"Y={player1_pos[1]}, Z={player1_pos[2]}"
    )
    distance_center = round(distance(player1_pos, center_pos), 4)
    print(f"Distance to center: {distance_center}\n")

    print("Get a second set of coordinates")
    player2_pos = get_player_pos()
    distance_players = round(distance(player1_pos, player2_pos), 4)
    print(f"Distance between the 2 sets of coordinates: {distance_players}\n")


if __name__ == "__main__":
    main()
