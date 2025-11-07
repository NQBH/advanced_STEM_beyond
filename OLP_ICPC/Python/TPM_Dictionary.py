import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = input()
    key = {
        'a': 1,
        'b': 2,
        'c': 3,
        'd': 4,
        'e': 5,
        'f': 6,
        'g': 7,
        'h': 8,
        'i': 9,
        'j': 10,
        'k': 11,
        'l': 12,
        'm': 13,
        'n': 14,
        'o': 15,
        'p': 16,
        'q': 17,
        'r': 18,
        's': 19,
        't': 20,
        'u': 21,
        'v': 22,
        'w': 23,
        'x': 24,
        'y': 25,
        'z': 26
    }
    if key[n[0]] < key[n[1]]: print(25 * (key[n[0]] - 1) + key[n[1]] - 1)
    else: print(25 * (key[n[0]] - 1) + key[n[1]])