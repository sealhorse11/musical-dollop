'''
only passed subtask 1
'''

N, K = int(input().rstrip().split())

ans = 3000000000
idx = 0

for i in range(N):
    w, v, t = map(int, input().rstrip().split())
    if ans > w + v + t:
        ans = w + v + t
        idx = i

print(ans)
print(idx + 1)