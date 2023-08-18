'''
only passed subtask1
'''

import sys

input = sys.stdin.readline

N = int(input().rstrip())
for _ in range(N - 1):
    a, b = map(int, input().rstrip().split())

if N == 2:
    print(1)
else:
    print(N - 2)
