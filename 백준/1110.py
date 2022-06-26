
a=input()

if len(a)==1:
    a="0"+a
b=a
cnt=0
while a!=b or cnt==0 :
    a=a[-1]+str(int(a[0])+int(a[1]))[-1]
    cnt+=1


print(cnt)