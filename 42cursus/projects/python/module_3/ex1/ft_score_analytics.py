import sys


def parse_score(arg: str) -> int | None:
    try:
        return int(arg)
    except ValueError:
        print(f"Invalid parameter: '{arg}'")
        return None


def main() -> None:
    print("=== Player Score Analytics ===")

    if len(sys.argv) == 1:
        print(
            "No scores provided. "
            "Usage: python3 ft_score_analytics.py <score1> <score2> ..."
        )
        return

    arguments = sys.argv[1:]
    parsed = [parse_score(arg) for arg in arguments]
    scores_processed_list = [score for score in parsed if score is not None]
    if len(scores_processed_list) == 0:
        print(
            "No scores provided. "
            "Usage: python3 ft_score_analytics.py <score1> <score2> ..."
        )
        return

    total_players = len(scores_processed_list)
    total_score = sum(scores_processed_list)
    max_score = max(scores_processed_list)
    min_score = min(scores_processed_list)
    avg_score = total_score / total_players
    range_score = max_score - min_score

    print(f"Scores processed: {scores_processed_list}")
    print(f"Total players: {total_players}")
    print(f"Total score: {total_score}")
    print(f"Average score: {avg_score}")
    print(f"High score: {max_score}")
    print(f"Low score: {min_score}")
    print(f"Score range: {range_score}")


if __name__ == "__main__":
    main()
