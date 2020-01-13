#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int A[500000],B[500000];
vector<int> C;
bool comp(int bl, int br)
{
	return bl>br;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		B[i]=A[i];
		C.push_back(A[i]);	
	}	
	sort(A,A+n);
	for(int i=0;i<n;i++)	printf("%d ",A[i]); printf("\n");
	sort(B,B+n,comp);
	for(int i=0;i<n;i++)	printf("%d ",B[i]);	printf("\n");
	sort(C.begin(),C.end());
	for(int i=0;i<n;i++)	printf("%d ",C[i]);	printf("\n");	
}
