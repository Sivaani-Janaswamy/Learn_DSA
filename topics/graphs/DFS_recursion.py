graph = [[0,1,1,0,0],
         [1,0,1,1,0],
         [1,1,0,0,1],
         [0,1,0,0,1],
         [0,0,1,1,0]]
global visited
visited = [0]*len(graph)

def DFS(graph,start):
     visited[start] = 1
     print(start,end=" ")
     for i in range(len(graph)):
          if graph[start][i]==1 and not visited[i]:
               DFS(graph,i)
     return 

DFS(graph,0)