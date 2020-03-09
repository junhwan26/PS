
n,m=input().split()
n=int(n)
m=int(m)
In=input().split()
#print(In)
#In=list(In)

for o in range(m):
    comp1=[]
    comp2=[]
    flag=0
    a,b,c,d=input().split()
    a=int(a)
    b=int(b)
    c=int(c)
    d=int(d)
    str1=In[a-1:b]
    str2=In[c-1:d]
    for i in str1:
        if i not in comp1:
            comp1.append(i)
    for i in str2:
        if i not in comp2:
            comp2.append(i)
    if set(comp1)==set(comp2):
        print("YES\n")
    else:
        print("NO\n");
