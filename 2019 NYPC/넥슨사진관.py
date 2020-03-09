def search(person):
    for i in person:
        if person.count(i) %2 ==1:
            print(i)
            break
    
    #print("검색끝")


n,m=input().split()
n=int(n)
m=int(m)
In=input().split()
#print(In)
#In=list(In)

for o in range(m):
    k,l,m=input().split()
    #print(a,b,c)
    if k=='2':
        l=int(l)
        m=int(m)
        p=In[l-1:m]
        search(p)
    elif k=='1':
        l=int(l)
        #print(l,In[l])
        In[l-1]=m
       # print(In)
