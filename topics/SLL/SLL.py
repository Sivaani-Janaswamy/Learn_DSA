class Node:
    def __init__(self,val):
        self.val = val
        self.next = None
class SLL:
    def __init__(self):
        self.head = None

    def insertAtBegin(self,ele):
        newnode = Node(ele)
        newnode.next = self.head
        self.head = newnode 
        
    def insertAtEnd(self,ele):
        newnode = Node(ele)
        if self.head is None:
            self.head = newnode
            return
        temp = self.head
        while(temp.next):
            temp = temp.next
        temp.next = newnode
    
    def insertAtPos(self,ele,pos):
        if pos < 0:
            print("Invalid position!")
            return
        newnode = Node(ele)
        if pos == 0:  
            newnode.next = self.head
            self.head = newnode
            return
        temp = self.head
        i = 0
        while temp is not None and i < pos - 1:
            temp = temp.next
            i += 1
        if temp is None:
            print("Position out of bounds!")
            return
        newnode.next = temp.next
        temp.next = newnode

    def traversal(self):
        temp = self.head
        while(temp):
            print(temp.val,end=" -> ")
            temp = temp.next
        print("NULL\n")

    def search(self,ele):
        temp = self.head
        while(temp):
            if(temp.val == ele):
                return True
        return False
    def deleteAtBegin(self):
        if self.head is None:
            return
        self.head = self.head.next  

    def deleteAtEnd(self):
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None  

    def deleteAtPos(self, pos):
        if self.head is None:
            return
        if pos == 0:
            self.head = self.head.next
            return
        temp = self.head
        i = 0
        while temp is not None and i < pos - 1:
            temp = temp.next
            i += 1
        if temp is None or temp.next is None:
            return
        temp.next = temp.next.next  
        

    
slist = SLL()
slist.insertAtBegin(10)
slist.insertAtEnd(20)
slist.insertAtPos(40,2)
slist.traversal()
slist.deleteAtBegin()
slist.traversal()