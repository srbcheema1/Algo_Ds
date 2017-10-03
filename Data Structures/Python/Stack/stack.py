
#Make a class Stack
class Stack:
   def __init__(self):
	         self.items = []
	
	  def isEmpty(self):
	         return self.items == []
	
    def push(self, item):
	         self.items.insert(0,item)
	
	   def pop(self):
	         return self.items.pop(0)
	
     def peek(self):
	         return self.items[0]
           
      def size(self):
	         return len(self.items)
	
	#Calling Object of class Stack
  s = Stack()
	
  #Calling the function
  s.push('hello')
	s.push('true')
	print(s.pop())
