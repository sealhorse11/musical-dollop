import sys

input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())

good = dict()

for _ in range(n):
    _id, _pw = input().rstrip().split()
    good[_id] = _pw

for _ in range(m):
    _id = input().rstrip()
    print(good[_id] + '\n')