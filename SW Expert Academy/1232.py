
def calc(a , b, c):
    if c == "+":
        return int(a) + int(b)
    if c == "-":
        return int(a) - int(b)
    if c == "*":
        return int(a) * int(b)
    if c == "/":
        return int(a) / int(b)

def search(a, tree):
    
    if len(tree[a]) ==1:
        return int(tree[a][0])
    elif len(tree[a]) == 3:
        return calc(search(tree[a][1], tree), search(tree[a][2],tree), tree[a][0])

T = 10
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    tree = {}
    N = int(input())
    for i in range(N):
        tmp = input().split()
        tree[tmp[0]] = tmp[1:]
    #print(tree)
    print("#"+str(test_case)+" ",end = "")
    print(int(search('1',tree)))

