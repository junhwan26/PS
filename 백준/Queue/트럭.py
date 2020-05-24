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

a=input().split(" ")

tmp = input().split(" ")

truck = ArrayQueue()
time=0
bridge = ArrayQueue()
birdsum=0

for i in tmp:
    truck.enqueue(int(i))
for i in range(int(a[1])):
    bridge.enqueue(0)

while not truck.isEmpty() or not bridge.isEmpty():
    
    if truck.isEmpty():
        bridge.dequeue()

    else:
        birdsum-=bridge.dequeue()

        if birdsum+truck.peek() <= int(a[2]):
            tmp=truck.dequeue()
            birdsum+=tmp
            bridge.enqueue(tmp)
        else :
            bridge.enqueue(0)
    time+=1
    #print("truck\n",truck.data)
    #print("bridge\n",bridge.data)

print(time)