T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, M, L = map(int, input().split())
    arr = list(map(int, input().split()))
    for i in range(M):
        tmp = input().split()

        if tmp[0] == 'D':
            del arr[int(tmp[1])]
        elif tmp[0] == 'I':
            arr.insert(int(tmp[1]),int(tmp[2]))

        elif tmp[0] == 'C':
            arr[int(tmp[1])] = int(tmp[2])
    print("#"+str(test_case)+" ", end = "")
    if(len(arr) <= L):
        print(-1)
    else :
        print(arr[L])


