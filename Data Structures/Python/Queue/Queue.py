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
	
   def printing(self):
        print(self.items)
   
   def enqueue(self, item):
	    self.items.insert(0,item)
	
   def dequeue(self):
        return self.items.pop()
	
   def size(self):
        return len(self.items)
	
#Create an object of Class Queue
#Calling the functions

myQueue = Queue()
x = 1
print("Enter \n1 : enqueue \n2 : dequeue \n3 : exit")
while x != 3:
    x = int(input("Enter the option : "))
    if x == 1:
        a = int(input())
        myQueue.enqueue(a)
        myQueue.printing()
    elif x == 2:
        if myQueue.isEmpty():
            print("Queue is empty")
        else:
            myQueue.dequeue()
            myQueue.printing()
    elif x == 3:
        print("Exit")
        myQueue.printing()
    else:
        print("Incorrect option\nEnter again\n")
