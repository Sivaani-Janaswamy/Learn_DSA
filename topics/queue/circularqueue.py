class Queue:
    max = 5
    def __init__(self):
        self.arr = []
        self.front = -1
        self.rear = -1
    def isEmpty(self):
        if(self.front == -1):
            return True
        return False
    def isFull(self):
        if(self.rear == max-1):
            return True
        return False
    def enqueue(self,val):
        if(self.isFull):
            print("Queue is Full, Cannot Enqueue!")
            return
        if(self.isEmpty):
            self.front = 0
        self.rear += 1
        self.arr[self.rear] = val
    def dequeue(self):
        if(self.isEmpty):
            print("Queue is Empty, Cannot Dequeue!")
    
            
