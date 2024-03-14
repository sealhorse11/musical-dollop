import sys

input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().rstrip().split())

MAX_DISTANCE = 100
matrix_of_distance = [[MAX_DISTANCE] * n for _ in range(n)]

for _ in range(m):
    friend1, friend2 = map(int, input().rstrip().split())
    matrix_of_distance[friend1 - 1][friend2 - 1] = 1
    matrix_of_distance[friend2 - 1][friend1 - 1] = 1

min_kevin_bacon = MAX_DISTANCE ** 2
idx_of_min_kevin_bacon = 0

for start in range(n):
    for middle in range(n):
        for end in range(n):
            prev_distance = matrix_of_distance[start][end]
            through_distance = matrix_of_distance[start][middle] + matrix_of_distance[middle][end]
            if prev_distance > through_distance:
                matrix_of_distance[start][end] = matrix_of_distance[end][start] = through_distance

for start in range(n):
    kevin_bacon = 0
    for index_of_friend in range(n):
        if index_of_friend == start:
            continue
        
        kevin_bacon += matrix_of_distance[start][index_of_friend]
    
    if min_kevin_bacon > kevin_bacon:
        min_kevin_bacon = kevin_bacon
        idx_of_min_kevin_bacon = start + 1

print(str(idx_of_min_kevin_bacon))