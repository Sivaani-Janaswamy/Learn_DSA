class Queue:
    def __init__(self):
        self.items = []
    def enqueue(self,ele):
        self.items.append(ele)
    def dequeue(self):
        if not self.isEmpty():
          return self.items.pop(0)
        return None
    def isEmpty(self):
        return len(self.items)==0
    
def BFS(graph,start):
    q = Queue()
    visited = [0]*len(graph)
    visited[start] = 1
    q.enqueue(start)
    while not q.isEmpty():
        current = q.dequeue()
        print(current,end= " ")
        for i in range(0,5):
          if graph[current][i] == 1 and not visited[i]:
              q.enqueue(i)
              visited[i] = 1

graph = [[0,1,1,0,0],
         [1,0,1,1,0],
         [1,1,0,0,1],
         [0,1,0,0,1],
         [0,0,1,1,0]]
BFS(graph,0)