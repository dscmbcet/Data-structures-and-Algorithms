# Priority queue implementation using heap

import heapq

class PriorityQueue:
    def __init__ (self):
        self.pq = []

    def enqueue(self, priority, item):
        self.pq.append(((priority, item)))
        heapq._heapify_max(self.pq)

    def dequeue(self):
        if self.is_empty():
            return "Can't dequeue from an empty priority queue!"
        return f"Dequeued: {heapq._heappop_max(self.pq)[1]}"

    def is_empty (self):
        return len(self.pq) == 0
    
    def peek (self):
        return "Priority queue empty!" if self.is_empty() else f"Top element: {self.pq[0][1]}"

    def print_queue (self):
        return f"Priority Queue: {self.pq}"

pq = PriorityQueue()
print(pq.dequeue())
pq.enqueue(3, 45)
pq.enqueue(7, 23)
pq.enqueue(1, 25)
pq.enqueue(5, 15)
pq.enqueue(4, 35)
print(pq.peek())
print(pq.print_queue())
print(pq.dequeue())
print(pq.print_queue())
print(pq.dequeue())
print(pq.print_queue())