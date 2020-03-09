n=int(input())

dels="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.-@0123456789"
delim=list(dels)

for j in range(n):
    flag=0
    s=input()
    slist=list(s)
    #print(slist)
    email = s.split("@")
    #print(email)
    if len(email)!=2 or email[0]==""or email[1]=="":
        print("No\n")
        flag=1
        continue
    for i in slist:
        if i not in delim:
            #print(i,end=" ")
            print("No\n")
            flag=1
            break

    if flag==0:
        print("Yes\n")