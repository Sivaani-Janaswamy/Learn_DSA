class Stacks:
    def __init__(self, max=5):
        self.stack = []          
        self.max = max           

    def isFull(self):
        return len(self.stack) == self.max

    def isEmpty(self):
        return len(self.stack) == 0

    def push(self, ele):
        if self.isFull():
            print("Stack is Full. Cannot Push.")
        else:
            self.stack.append(ele)
            print(f"Pushed: {ele}")

    def pop(self):
        if self.isEmpty():
            print("Stack is Empty. Cannot Pop.")
            return None
        return self.stack.pop()

    def peek(self):
        if self.isEmpty():
            print("Stack is Empty. Cannot Peek.")
        else:
            print(f"Top Element: {self.stack[-1]}")

    def display(self):
        if self.isEmpty():
            print("Stack is Empty. Nothing to display.")
        else:
            print("Stack Contents:", *self.stack)


if __name__ == "__main__":  
    my_stack = Stacks(5)    

    while True:
        print("\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            value = input("Enter element to push: ")
            my_stack.push(value)

        elif choice == "2":
            popped_value = my_stack.pop()
            if popped_value is not None:
                print(f"Popped: {popped_value}")

        elif choice == "3":
            my_stack.peek()

        elif choice == "4":
            print("Stack is empty!" if my_stack.isEmpty() else "Stack is NOT empty.")

        elif choice == "5":
            print("Stack is full!" if my_stack.isFull() else "Stack is NOT full.")

        elif choice == "6":
            my_stack.display()

        elif choice == "7":
            print("Exiting...")
            break

        else:
            print("Invalid choice. Try again!")
