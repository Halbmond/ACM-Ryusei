/*
��һ��n*m������(i,j)λ���ϵ�����LCM(i,j)��
���������ĺͣ�
n,m<=10^7����������
Crash�����ֱ���ǿ��
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 10010000
#define mod 100000009ll
using namespace std;
typedef long long ll;
ll pri[N>>3],tot;
ll g[N],sum[N];
bool vis[N];
void init()
{
	g[1]=sum[1]=1;
	for(ll i=2;i<N;i++)
	{
		if(!vis[i])
		{
			pri[++tot]=i;
			g[i]=((-(ll)(i-1)*i)%mod+mod)%mod;
		}
		for(ll j=1;j<=tot&&i*pri[j]<N;j++)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				g[i*pri[j]]=g[i]*pri[j]%mod;
				break;
			}
			g[i*pri[j]]=g[i]*g[pri[j]]%mod;
		}
		sum[i]=sum[i-1]+g[i];
	}		
}
ll F(ll x,ll y)
{
	return ((ll)(x+1)*x/2)%mod*(((ll)(y+1)*y/2)%mod)%mod;
}
int main()
{
	init();
	ll c,T,n,m,i,j,k;
	ll ans;
	scanf("%lld",&T);
	for(c=1;c<=T;c++)
	{
		scanf("%lld%lld",&n,&m);
		if(n>m)	swap(n,m);
		for(i=1,ans=0;i<=n;i=j+1)
		{
			j=min(n/(n/i),m/(m/i));
			ans+=F(n/i,m/i)*(sum[j]-sum[i-1]+mod)%mod;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
