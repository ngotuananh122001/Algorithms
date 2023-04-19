class MyStack:
    def __init__(self):
        self.stack_list = []
        self.stack_size = 0

    def is_empty(self):
        return self.stack_size == 0

    def peek(self):
        if self.is_empty():
            return None
        return self.stack_list[-1]

    def size(self):
        return self.stack_size
    
    def push(self, value):
        self.stack_size += 1
        self.stack_list.append(value)

    def pop(self):
        if self.is_empty():
            return None
        self.stack_size -= 1
        return self.stack_list.pop()



from Stack import MyStack
# Push Function => stack.push(int)  //Inserts the element at top
# Pop Function => stack.pop()       //Removes and returns the element at top
# Top/Peek Function => stack.get_top()  //Returns top element
# Helper Functions => stack.is_empty() & stack.isFull() //returns boolean


class NewQueue:
    def __init__(self):
        self.main_stack = MyStack()
        # Write your code here


    # Inserts Element in the Queue
    def enqueue(self, value):
        self.main_stack.push(value)
        self.main_stack.stack_size += 1


    # Removes Element From Queue
    def dequeue(self):
        if self.main_stack.is_empty():
            return None
        
        tmp_stack = MyStack()

        while not self.main_stack.is_empty():
            tmp_stack.push(self.main_stack.pop())
            self.main_stack.stack_size -= 1

        ans = tmp_stack.pop()

        while not tmp_stack.is_empty():
            self.main_stack.push(tmp_stack.pop())
            self.main_stack.stack_size += 1

        return ans