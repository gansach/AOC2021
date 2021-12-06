def num_fishes(fish, days):
    if days == 0:
        return 0

    if fish == 0:
        return 1 + num_fishes(6, days - 1) + num_fishes(8, days - 1)

    return num_fishes(fish - 1, days - 1)


with open("input.txt", "r") as f:
    fishes = list(map(int, f.read().split(',')))
    print(sum(map(lambda fish: num_fishes(fish, 80) + 1, fishes)))
