import sys

def main():
    print("=== Player Score Analytics ===")

    if len(sys.argv) == 1:
        print("No scores provided.")
        print("Usage: python3 ft_score_analytics.py <score1> <score2> ...")
        return

    scores_processed_list: list[int] = []
    arguments = sys.agrv[1:]
    for arg in arguments:
        try:
            score = int(arg)
            scores_processed_list.append(score)
        except ValueError:
            print(f"Invalid parameter: {arg}")
    if len(scores_processed_list) == 0:
        print("No scores provided.")
        print("Usage: python3 ft_score_analytics.py <score1> <score2> ...")
        return

    total_playes = len(scores_processed_list)
    total_score = sum(scores_processed_list)
    