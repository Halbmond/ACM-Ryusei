//Moving Pebbles
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
typedef unsigned long long ll;
const int MXN=100001;
int N;

map<string,int>M;

char a[10000];
int main(){
	while (cin>>N){
		M.clear();
		int tot=0;
		rep(i,1,N){
			scanf("%s",a);
			if (++M[a]&1) tot++;
			else tot--;
		}
		puts(N&1||tot?"first player":"second player");
	}
	return 0;
}
/*
给定n堆石子，每次可以选择一堆石子，拿走任意个，然后将堆中剩余石子移动任意个到任意一些堆里，不能操作者为输。

不同游戏之间会互相影响，不能用sg。

必败状态为：n为偶数，且将石子数相同的堆两两配对可以配成n/2对。 

证明：
如果初始有奇数堆石子，那么先手可以将最小的堆和第二小的堆配对，第三小的堆和第四小的堆配对，...，然后用最大的堆填补差值，显然一定能填补上； 
如果初始有偶数堆石子，那么先手可以将最大的堆和最小的堆配对，第二小的堆和第三小的堆配对，第四小的堆和第五小的堆配对，...，用最大的堆多出来的部分填补差值，显然也一定能填补上。 
*/
