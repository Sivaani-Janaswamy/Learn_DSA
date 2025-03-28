class Stack:
    def __init__(self):
        self.items = []
    def push(self,ele):
        self.items.append(ele)
    def pop(self):
        if not self.isEmpty():
          return self.items.pop()
        return None
    def isEmpty(self):
        return len(self.items)==0
    
def DFS(graph,start):
    stack = Stack()
    visited = [0]*len(graph)
    visited[start] = 1
    stack.push(start)
    while not stack.isEmpty():
        current = stack.pop()
        print(current, end = " ")
        for i in range(len(graph)-1,-1,-1):
            if graph[current][i] == 1 and not visited[i]:
                stack.push(i)
                visited[i] = 1

graph = [[0,1,1,0,0],
         [1,0,1,1,0],
         [1,1,0,0,1],
         [0,1,0,0,1],
         [0,0,1,1,0]]
DFS(graph,0)