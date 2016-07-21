//ЙЄве
#include<cstdio>
#include<iostream>
#include<algorithm>
#define re(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MXN=300009;

int minr(int s[],int n){
	int i,j,k,t;
	for(i=0,j=1,k=0;i<n&&j<n&&k<n;){
		t=s[(i+k)%n]-s[(j+k)%n];
		if (!t) k++;else{
			t>0?i+=k+1:j+=k+1;
			j+=i==j;
			k=0;
		}
	}
	return min(i,j);
}

int N;
int a[MXN];

int main(){
	scanf("%d",&N);
	re(i,N) scanf("%d",a+i);
	int p=minr(a,N);
	re(i,N) printf("%d%c",a[(i+p)%N],i<N-1?' ':'\n');
	return 0;
}
