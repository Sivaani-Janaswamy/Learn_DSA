class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.prev = temp

    def prepend(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def delete(self, data):
        temp = self.head
        while temp:
            if temp.data == data:
                if temp.prev:
                    temp.prev.next = temp.next
                if temp.next:
                    temp.next.prev = temp.prev
                if temp == self.head:
                    self.head = temp.next
                temp = None
                return
            temp = temp.next

    def search(self, key):
        temp = self.head
        while temp:
            if temp.data == key:
                return True
            temp = temp.next
        return False

    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" <-> ")
            temp = temp.next
        print("None")

# User menu
if __name__ == "__main__":
    dll = DoublyLinkedList()
    while True:
        print("\nOperations:")
        print("1. Append")
        print("2. Prepend")
        print("3. Delete")
        print("4. Search")
        print("5. Display")
        print("6. Exit")
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            data = int(input("Enter value to append: "))
            dll.append(data)
        elif choice == 2:
            data = int(input("Enter value to prepend: "))
            dll.prepend(data)
        elif choice == 3:
            data = int(input("Enter value to delete: "))
            dll.delete(data)
        elif choice == 4:
            data = int(input("Enter value to search: "))
            print("Found" if dll.search(data) else "Not found")
        elif choice == 5:
            dll.display()
        elif choice == 6:
            break
        else:
            print("Invalid choice. Try again.")
