import sys

input = sys.stdin.readline

n = int(input().rstrip())
scores = list(map(int, input().rstrip().split()))

dp = [-1e15 for _ in range(n + 1)]

dp[0] = (0, 0) # me 0 enemy 0

for i, score in enumerate(scores):
    prev_best = dp[i]
    if prev_best[0] >= prev_best[1] + score:
        dp[i+1] = (prev_best[0], prev_best[1] + score)
    else:
        dp[i+1] = (prev_best[1] + score, prev_best[0])

print(dp[n][0])