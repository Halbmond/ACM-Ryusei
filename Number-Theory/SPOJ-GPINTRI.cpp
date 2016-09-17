//Grid Points in a Triangle
#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define re(i,n) for(int i=0;i<n;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
typedef long long ll;
const int MXN=1000000000;

ll gp(ll n,ll a,ll d,ll m){
	if (d==0) return a/m*n;
	if (a>=m||d>=m) return a/m*n+d/m*n*(n-1)/2+gp(n,a%m,d%m,m);
	return gp((a+d*n)/m,(a+d*n)%m,m,d);
}

int N,A,B;
void solve(){
	scanf("%d %d %d",&N,&A,&B);
	printf("%lld\n",gp(N+1,0,A,B)+N+1);
}


int cas;
int main(){
	freopen("SPOJ-GPINTRI.in","r",stdin);
	freopen("SPOJ-GPINTRI.out","w",stdout);
	scanf("%d",&cas);
	for(;cas--;) solve();
	return 0;
}
