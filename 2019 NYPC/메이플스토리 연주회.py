n=int(input())
parts = []
for i in range(n):
    parts.append(input())
#print(parts)
string=input()
#print(string)

hubo=[]
size=len(parts)

def getpartialmatch(N):
    m = len(N)
    pi = [0]*m
    begin = 1; matched = 0
    while begin + matched < m:
        if N[begin + matched] == N[matched]:
            matched += 1
            pi[begin+matched-1] = matched
        else:
            if matched == 0:
                begin += 1
            else:
                begin += matched - pi[matched-1]
                matched = pi[matched-1]
    return pi
 
def kmp(H,N):
    n = len(H); m = len(N)
    ret = []
    pi = getpartialmatch(N)
    begin = 0; matched = 0
    while begin <= n-m:
        if matched < m and H[begin + matched] == N[matched]:
            matched += 1
            if matched == m:
                ret.append(begin)
        else:
            if matched==0:
                begin += 1
            else:
                begin += matched - pi[matched-1]
                matched = pi[matched-1]
    return ret
 
print (kmp('ababbaba','aba'))


'''
for i in range(size):
    tmp=string.replace(parts[i],"")
    if string==tmp:
        continue
    print("+"+tmp)
    tmp1=tmp
    for j in range(i+1,size):
        '''
        
        
                