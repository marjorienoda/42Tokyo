def ft_count_harvest_recursive()-> None:
    days = int(input("Days until harvest: "))

    def count_days(current_day: int, day: int)-> None:
        if current_day > day:
            return
        print(f"Day {current_day}")

        count_days(current_day + 1, day)
    count_days(1, days)
    print("Harvest time!")
