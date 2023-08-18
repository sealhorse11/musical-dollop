import sys

def get_xor_section(section:list)->int:
    res = section[0]
    for elem in section[1:]:
        res ^= elem
    return res

input = sys.stdin.readline

N = int(input().rstrip())
A = list(map(int, input().rstrip().split()))

dp = [[0 for __ in range(N)] for _ in range(5)]

if N == 1:
    print(A[0])
    exit(0)
elif N == 2:
    print(A[0] ^ A[1])
    exit(0)
elif N == 3:
    print(max((A[0]^ A[1]) + A[2], A[0] + (A[1] ^ A[2])))
    exit(0)

dp[1][0] = A[0]
dp[2][1] = A[0] ^ A[1]
dp[3][2] = A[0] ^ A[1] ^ A[2]
dp[4][3] = A[0] ^ A[1] ^ A[2] ^ A[3]

for i in range(1, N):
    for length in range(1, 5):  # length of section 1, 2, 3, 4
        if dp[length][i] == 0 and i >= length:
            curr_section = get_xor_section(A[i-length+1:i+1])
            # previous length of section
            for prev_length in range(1, 5):
                if length == prev_length:
                    continue
                if dp[prev_length][i - length] != 0 and dp[length][i] < dp[prev_length][i - length] + curr_section:
                    dp[length][i] = dp[prev_length][i-length] + curr_section

print(max(dp[1][N-1], dp[2][N-1], dp[3][N-1], dp[4][N-1]))