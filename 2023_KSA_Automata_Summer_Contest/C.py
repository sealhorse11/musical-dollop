import sys    

input = sys.stdin.readline

N, M, K = map(int, input().rstrip().split())

sorted_strings = list()

for _ in range(N):
    s = list(input().rstrip())
    s.sort()
    sorted_strings.append(''.join(s))

sorted_strings.sort()
target_char = list(''.join(sorted_strings[:K]))
target_char.sort()

print(''.join(target_char))