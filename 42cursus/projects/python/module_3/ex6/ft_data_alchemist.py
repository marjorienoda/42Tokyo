import random

PLAYERS = [
    "Alice",
    "bob",
    "Charlie",
    "dylan",
    "Emma",
    "Gregory",
    "john",
    "kevin",
    "Liam",
]


def main() -> None:
    print("=== Game Data Alchemist ===\n")
    print(f"Initial list of players: {PLAYERS}")

    capitalized = [player.capitalize() for player in PLAYERS]
    print(f"New list with all names capitalized: {capitalized}")
    only_capitalized = [player for player in PLAYERS if player.istitle()]
    print(f"New list of capitalized names only: {only_capitalized}")

    players_dict = {key: random.randint(0, 999) for key in capitalized}
    print(f"Score dict: {players_dict}")
    average_score = round(
        sum(players_dict[name] for name in players_dict) / len(players_dict),
        2
    )
    print(f"Score average is {average_score}")
    high_scores = {
        name: players_dict[name]
        for name in players_dict
        if players_dict[name] > average_score
    }
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()
