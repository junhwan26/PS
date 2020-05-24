
class ArrayQueue:
  def __init__(self):
    self.data = []
  
  def size(self):
    return len(self.data)

  def isEmpty(self):
    return self.size()==0

  def enqueue(self, item):
    self.data.append(item)

  def dequeue(self):
    if self.isEmpty():
      print("빈 큐임")
    else:
      return self.data.pop(0)

  def peek(self):
    if self.isEmpty():
      print("빈 큐임")
    else:
      return self.data[0]
#프린터 큐

n = int(input())

for i in range(n):
    q = ArrayQueue()
    m,k=input().split(" ")
    m=int(m)
    k=int(k)

    tmp=input().split(" ")
    tmp=list(map(int, tmp))
    
    p=sorted(tmp)
    p.reverse()

    for i in range(len(tmp)) :
        q.enqueue((i,tmp[i]))
    i=1
    while not q.isEmpty():
        #print(q.data)
        d=q.dequeue()
        if d[1] < p[i-1]:
            q.enqueue(d)
        else :
            if d[0] == k :
                print(i)
                break
            i+=1