class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        return None

    def is_empty(self):
        return len(self.items) == 0
    
    def display(self):
        if(self.is_empty()):
            print("Cannot Display! Queue is empty!\n")
            return
        print(*self.items,sep= " ")
        print()


    def peek(self):
        if not self.is_empty():
            return self.items[0]
        return None

    def size(self):
        return len(self.items)


q = Queue()
print("Simple Queue \n -------------- \n")
while(True):
    print("1. Enqueue \n2. Dequeue \n3. Display \n4. Peek \n5. Size \n6. Exit \n")
    print("Enter your choice: ")
    ch = int(input())
    print()
    if(ch==1):
        print("Enter Element: ")
        ele = int(input())
        q.enqueue(ele)
    elif(ch==2):
        q.dequeue()
    elif(ch==3):
        q.display()
    elif(ch==4):
        print(q.peek())
        print()
    elif(ch==5):
        print(q.size())
        print()
    elif(ch==6):
        break
    else:
        print("Invalid choice \n")
