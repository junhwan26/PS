

def inorder(a, tree):
    # print(tree[a])
    if(len(tree[a]))>1:
        inorder(tree[a][1], tree)
    print(tree[a][0],end="")
    if(len(tree[a]))>2:    
        inorder(tree[a][2], tree)

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
    inorder('1',tree)
    print()

