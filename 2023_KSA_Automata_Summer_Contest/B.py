import sys

import math

input = sys.stdin.readline

n = int(input().rstrip())

visible_set = set()

for _ in range(n):
    a, b = map(int, input().rstrip().split())
    _a, _b = abs(a), abs(b)
    k = math.gcd(_a, _b)
    visible_set.add((a // k ,b // k))

print(len(visible_set))