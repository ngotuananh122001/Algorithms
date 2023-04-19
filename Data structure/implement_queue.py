# Is_Empty()
# Enqueue()
# Dequeue()
# Size()
# Front()
# Rear()

class Node:
    def __init__(self, data):
        self.data = data 
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def get_head(self):
        if self.head is None:
            return None
        return self.head.data

    def insert_tail(self, data):
        new_node = Node(data)
        if self.head is None:
           self.head = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail

        self.tail = new_node
        self.length += 1
        return new_node


    def remove_head(self):
        if self.head is None:
            return None
    
        removed_node = self.head
        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.head = removed_node.next
            self.head.prev = None
            removed_node.next = None

        self.length -= 1    
        return removed_node.data
    
    def is_empty(self):
        return self.length == 0
    
    def size(self):
        return self.length

    def get_tail(self):
        if self.tail is None:
            return None
        return self.tail.data

    def __str__(self):
        val=""
        head = self.head
        if head is not None:
            val += str(head.data)
            head = head.next
        
        while head is not None:
            val += ", " + str(head.data)
            head = head.next

        val += "]"
        return val

class Queue:
    def __init__(self):
        self.items = DoublyLinkedList()

    def is_empty(self):
        return self.items.is_empty()

    def size(self):
        return self.items.size()
    
    def front(self):
        return self.items.get_head()
    
    def rear(self):
        return self.items.get_tail()
    
    def enqueue(self, data):
        return self.items.insert_tail(data)
    
    def dequeue(self):
        return self.items.remove_head()
    
    def print_list(self):
        return self.items.__str__()
    

if __name__ == "__main__" :
    queue_obj = Queue()
    print("queue.enqueue(2);")
    queue_obj.enqueue(2)
    print("queue.enqueue(4);")
    queue_obj.enqueue(4)
    print("queue.enqueue(6);")
    queue_obj.enqueue(6)
    print("queue.enqueue(8);")
    queue_obj.enqueue(8)
    print("queue.enqueue(10);")
    queue_obj.enqueue(10)
    
    queue_obj.print_list()
    
    print("is_empty(): " + str(queue_obj.is_empty()))
    print("front(): " + str(queue_obj.front()))
    print("rear(): " + str(queue_obj.rear()))
    print("size(): " + str(queue_obj.size()))
    print("Dequeue(): " + str(queue_obj.dequeue()))
    print("Dequeue(): " + str(queue_obj.dequeue()))
    print("queue.enqueue(12);")
    queue_obj.enqueue(12)
    print("queue.enqueue(14);")
    queue_obj.enqueue(14)

while queue_obj.is_empty() is False:
    print("Dequeue(): " + str(queue_obj.dequeue()))

print("is_empty(): " + str(queue_obj.is_empty()))
        