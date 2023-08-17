import sys
input = sys.stdin.readline
n, m = map(int, input().rstrip().split())

edges = [[] for _ in range(n)]

for _ in range(m):
    curr_edges = list(map(int, input().rstrip().split()))
    for i, vertex in enumerate(curr_edges[1:-1]):
        edges[vertex - 1].append(curr_edges[i+2] - 1)

condition = [0 for _ in range(n)]
for curr_vertex, curr_vertex_edges in enumerate(edges):
    for curr_edge in curr_vertex_edges:
        condition[curr_edge] += 1

visited = [False for _ in range(n)]
q = []
ans = []
for i, val in enumerate(condition):
    if val == 0:
        visited[i] = True
        q.append(i)

while True:
    if not q:
        break
    
    for curr_vertex in q:
        ans.append(curr_vertex)
        
        for next_vertex in edges[curr_vertex]:
            condition[next_vertex] -= 1
    q.clear()
    
    for i, val in enumerate(condition):
        if val == 0 and not visited[i]:
            visited[i] = True
            q.append(i)

if False in visited:
    print(0)
else:
    for v in ans:
        print(v+1)
    
print(edges)
