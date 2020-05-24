class Node:
    def __init__(self, item):
        self.next=None
        self.item=item
class List:
    def __init__(self):
        self.cur=0
        self.head=None
        self.tail=None
        self.size=0
    
    def add(self, item):
        new = Node(item)
        if self.size == 0:
            self.head = new
            self.tail = new
        else :
            self.tail.next = new
            self.tail = new
        self.cur+=1
        self.size+=1
    
    def l(self):
        if self.cur>0:
            self.cur-=1
    def d(self):
        if self.cur<self.size:
            self.cur+=1

    def insert(self, item):
        
        new = Node(item)
        self.size+=1
        if self.cur==0:
            new.next = self.head
            self.head = new
        
        else:
            p=self.head
            i=0

            while i<self.cur-1:
                p=p.next
                i+=1

            new.next = p.next
            p.next = new
        
        self.d()

    def delete(self):
        
        if self.cur == 0:
            return
        if self.cur == 1:
            self.head = self.head.next
            self.l()
            self.size-=1
            return

        p=self.head
        prev = p
        i=0

        while i<self.cur-1:
            prev = p
            p = p.next
            i+=1
        prev.next = p.next
        
        if self.cur==self.size:
            self.tail = prev       
        self.l() 
        self.size-=1
    
    
    def print_list(self):
        p = self.head
        while p:
            print(p.item, end="")
            p=p.next
        #print(" ",self.cur)
        
        

arr=list(input())
n=int(input())
li = List()

for i in arr:
    li.add(i)

for i in range(n):
    d=input()
    if len(d)>1:
        a,b=d.split(" ")
    else :
        a=d
    if a=='P':
        li.insert(b)
        
    if a=='B':
        li.delete()

    if a=='L':
        li.l()

    if a=='D':
        li.d()
    #li.print_list()

li.print_list()

