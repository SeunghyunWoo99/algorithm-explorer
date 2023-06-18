import sys
sys.setrecursionlimit(10000) 

def dfs(y, x, cnt):
    d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    graph[y][x] = 0
    for dy, dx in d:
        Y, X = y+dy, x+dx
        if (0 <= Y < N) and (0 <= X < M) and graph[Y][X] == 1:
            cnt = dfs(Y, X, cnt+1)
    return cnt
            
N, M, K = map(int, input().split())
graph = [[0]*M for _ in range(N)]
for _ in range(K):
    y, x = map(int, input().split())
    graph[y-1][x-1] = 1
res = []
for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            res.append(dfs(i, j, 1))
print(max(res))
