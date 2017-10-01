#List Based Implementation Of Queue in Python.


#Defining a python Class named Queue.

# isEmpty -> Returns True or False.
# enqueue -> Enter the element in Queue.
# dequeue -> Remove the element from Queue.
# size    -> Returns the size of Queue

class Queue:
	
   def __init__(self):
	    self.items = []
	
   def isEmpty(self):
	    return self.items == []
	
   def enqueue(self, item):
	    self.items.insert(0,item)
	
   def dequeue(self):
        return self.items.pop()
	
   def size(self):
        return len(self.items)
	

q=Queue()
#Create an object of Class Queue
#Calling the functions

q.enqueue(4)
q.enqueue('dog')
q.enqueue(True)
print(q.size())
