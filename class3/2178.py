import sys

input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().rstrip().split())
board = [[0] * m for _ in range(n)]
visited = [[False] * m for _ in range(n)]

for row in range(n):
    line = input().rstrip()
    for col, letter in enumerate(line):
        board[row][col] = ord(letter) - ord('0')

queue = [(0, 0)]
time = 0
direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]
visited[0][0] = True

def safe(pos: tuple[int, int]) -> bool:
    return ((0 <= pos[0] < n) and (0 <= pos[1] < m))

is_searching = True

while is_searching:
    time += 1
    prev_queue = queue
    queue = []
    while prev_queue:
        top = prev_queue.pop(0)

        if top == (n-1, m-1):
            is_searching = False
            break
        
        for dir in direction:
            next_pos = (top[0] + dir[0], top[1] + dir[1])
            if safe(next_pos) and board[next_pos[0]][next_pos[1]] == 1 and not visited[next_pos[0]][next_pos[1]]:
                queue.append(next_pos)
                visited[next_pos[0]][next_pos[1]] = True

print(str(time))