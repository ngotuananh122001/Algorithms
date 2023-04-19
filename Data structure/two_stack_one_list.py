class TwoStacks:
    # Initialize the two stacks here
    def __init__(self, size):
        self.items = [None for i in range(size)]
        self.size = size
        self.top1 = 0
        self.top2 = self.size - 1

    # Insert Value in First Stack
    def push1(self, value):
        self.top1 += 1
        self.items[self.top1] = value

    # Insert Value in Second Stack
    def push2(self, value):
        self.top2 -= 1
        self.items[self.top2] = value

    # Return and remove top Value from First Stack
    def pop1(self):
        ans = self.items[self.top1]
        self.items[self.top1] = None
        self.top1 -= 1

        return ans

    # Return and remove top Value from Second Stack
    def pop2(self):
        ans = self.items[self.top2];
        self.items[self.top2] = None
        self.top2 += 1

        return ans
