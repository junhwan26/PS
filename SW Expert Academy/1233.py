

def search(a, tree):
    
    if len(tree[a]) ==1:
        if '0' <= tree[a][0] and tree[a][0] <= '9':
            return True
        return False
    elif len(tree[a]) == 2:
        return False
    elif len(tree[a]) == 3:
        if '0' <= tree[a][0] and tree[a][0] <= '9':
            return False
        return search(tree[a][1], tree) and search(tree[a][2], tree)

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
