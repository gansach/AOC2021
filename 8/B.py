str2num = {
    "abcefg": "0",
    "cf": "1",
    "acdeg": "2",
    "acdfg": "3",
    "bcdf": "4",
    "abdfg": "5",
    "abdefg": "6",
    "acf": "7",
    "abcdefg": "8",
    "abcdfg": "9",
}


def tranformStr(s, c2c):
    return "".join(sorted(map(lambda x: c2c[x], list(s))))


def char2char(inp):
    len2str = {}
    num2str = {}
    char2freq = {}
    for x in inp:
        if len(x) not in len2str:
            len2str[len(x)] = []
        len2str[len(x)].append(x)

        for c in x:
            if c not in char2freq:
                char2freq[c] = 0
            char2freq[c] += 1

    num2str[1], num2str[4] = str(len2str[2]), str(len2str[4])
    num2str[7], num2str[8] = str(len2str[3]), str(len2str[7])

    freq2char = {v: k for k, v in char2freq.items()}

    a = "".join(set(num2str[7]) - set(num2str[1]))
    b, e, f = freq2char[6], freq2char[4], freq2char[9]
    g = "".join(
        set.intersection(
            *[
                *list(map(lambda x: set(x), len2str[5])),
                *list(map(lambda x: set(x), len2str[6])),
            ]
        ).difference(a)
    )

    c, d = "", ""
    for k, v in char2freq.items():
        if v == 8 and k != a:
            c = k
        elif v == 7 and k != g:
            d = k

    return {a: "a", b: "b", c: "c", d: "d", e: "e", f: "f", g: "g"}


with open("input.txt", "r") as f:
    ans = 0
    for line in f:
        inp, out = line.split("|")
        c2c = char2char(inp.split())
        ans += int(
            "".join(
                map(
                    lambda t: str2num[t],
                    map(lambda s: tranformStr(s, c2c), out.split()),
                )
            )
        )
    print(ans)
