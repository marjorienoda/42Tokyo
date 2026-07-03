import random

ACHIEVEMENTS = [
    "Crafting Genius",
    "World Savior",
    "Master Explorer",
    "Collector Supreme",
    "Untouchable",
    "Boss Slayer",
    "Strategist",
    "Unstoppable",
    "Speed Runner",
    "Survivor",
    "Treasure Hunter",
    "First Steps",
    "Sharp Mind",
    "Hidden Path Finder",
    "Night Owl",
    "Iron Will",
    "Pathfinder",
    "Legendary Status",
]


def gen_player_achievements() -> set[str]:
    nb = random.randint(5, 10)
    return set(random.sample(ACHIEVEMENTS, nb))


def get_distinct_achievements(
    players: dict[str, set[str]],
    names: list[str]
) -> set[str]:
    distinct = players[names[0]]
    for name in names[1:]:
        distinct = distinct.union(players[name])
    return distinct


def get_common_achievements(
    players: dict[str, set[str]],
    names: list[str]
) -> set[str]:
    common = players[names[0]]
    for name in names[1:]:
        common = common.intersection(players[name])
    return common


def get_exclusive_achievements(
    players: dict[str, set[str]],
    names: list[str]
) -> None:
    for name in names:
        others: set[str] = set()
        for other in names:
            if other == name:
                continue
            others = others.union(players[other])
        exclusive = players[name].difference(others)
        print(f"Only {name} has: {exclusive}")


def get_missing_achievements(
    players: dict[str, set[str]],
    names: list[str],
    distinct: set[str]
) -> None:
    for name in names:
        missing = distinct.difference(players[name])
        print(f"{name} is missing: {missing}")


def main() -> None:
    print("=== Achievement Tracker System ===\n")

    names: list[str] = ["Alice", "Bob", "Charlie", "Dylan"]
    players: dict[str, set[str]] = {}
    for name in names:
        players[name] = gen_player_achievements()
    for name in names:
        print(f"Player {name}: {players[name]}")

    distinct = get_distinct_achievements(players, names)
    common = get_common_achievements(players, names)
    print(f"All distinct achievements: {distinct}")
    print(f"Common achievements: {common}")
    print()
    get_exclusive_achievements(players, names)
    print()
    get_missing_achievements(players, names, distinct)


if __name__ == "__main__":
    main()
