import sys


def main() -> None:
    print("=== Player Score Analytics ===")

    if len(sys.argv) == 1:
        print(
            "No scores provided. "
            "Usage: python3 ft_score_analytics.py <score1> <score2> ..."
        )
        return

    scores_processed_list: list[int] = []
    arguments = sys.argv[1:]
    for arg in arguments:
        try:
            score = int(arg)
            scores_processed_list.append(score)
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
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
