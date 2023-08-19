import sys

input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

board = [[0 for _ in range(M)] for _ in range(N)]

visited = set()

block_to_num = {
    '#': -1,
    '.': 0,
    'R': 0,
    'B': 0,
    'O': 3
}

goal = (0,0)
target = (0,0)
trash = (0,0)

for row in range(N):
    line = list(input().rstrip())
    for col, block in enumerate(line):
        board[row][col] = block_to_num[block]
        if board[row][col] == 3:
            goal = (row, col)
        elif block == 'R':
            target = (row, col)
        elif block == 'B':
            trash = (row, col)

moved = 0
queue = [(target, trash)]

unit_vector = [(0, -1), (0, 1), (1, 0), (-1, 0)]

succeed = False
failed = False

while moved < 10 and queue:
    next_queue = []
    
    
    for curr_pos in queue:
        red, blue = curr_pos
        
        for cur_v in unit_vector:
            succeed = False
            failed = False
            
            curr_red, curr_blue = red, blue
            collision = False
            while True:
                next_red = (curr_red[0] + cur_v[0], curr_red[1] + cur_v[1])
                if board[next_red[0]][next_red[1]] != -1:
                    curr_red = next_red
                else:
                    break
                
                if curr_red == blue:
                    collision = True
                if curr_red == goal:
                    succeed = True
                    curr_red = (-1, -1)
                    break
            
            if collision:
                curr_blue = curr_red
                if succeed:
                    failed = True
                curr_red = (curr_blue[0] - cur_v[0], curr_blue[1] - cur_v[1])
            else:
                while True:
                    next_blue = (curr_blue[0] + cur_v[0], curr_blue[1] + cur_v[1])
                    if board[next_blue[0]][next_blue[1]] != -1 and next_blue != curr_red:
                        curr_blue = next_blue
                    else:
                        break
                    if curr_blue == goal:
                        failed = True
                        break
            
            if failed:
                continue
            if succeed:
                break
            if (curr_red, curr_blue) not in visited:
                visited.add((curr_red, curr_blue))
                next_queue.append((curr_red, curr_blue))
        
        if not failed and succeed:
            break
        
    queue = next_queue
    moved += 1
    
    if not failed and succeed:
        break

if failed or not succeed:
    print(-1)
else:
    print(moved)