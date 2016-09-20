//Ditch
#include<cstdio>
#include<iostream>
#include<algorithm>
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
#define tr(p) for(edge*lk=p;lk;lk=lk->next)
#define su lk->t
#define op(p) (epool+(((p)-epool)^1))
using namespace std;
const int MXN=210,MXM=210,inf=~0U>>1;

struct edge
{
	int t,c;edge*next;
}epool[MXN<<1],*ecnt=epool;

int N,M;
edge *E[MXN];


void init()
{
	for(int i=1;i<=N;i++)E[i]=0;ecnt=epool;
	for(int i=1;i<=M;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		*ecnt=(edge){y,c,E[x]},E[x]=ecnt++;
		*ecnt=(edge){x,0,E[y]},E[y]=ecnt++;
	}
}

namespace solve
{
	int vs,vt,flow;
	int q[MXN],t,w,depth[MXN];
	int bfs()
	{
		for(int i=1;i<=N;i++)depth[i]=0;
		q[t=w=0]=vs;depth[vs]=1;
		while(t<=w)
		{
			int u=q[t++];
			tr(E[u])if(lk->c&&!depth[su])
			{
				depth[su]=depth[u]+1;q[++w]=su;
			}
		}
		//for(int i=1;i<=N;i++)db(depth[i]),el;el;
		return depth[vt];
	}
	int dinic(int u,int f)
	{
		if(u==vt) return f;
		int m=f;
		tr(E[u])if(lk->c&&depth[su]==depth[u]+1)
		{
			int l=dinic(su,min(m,lk->c));
			if(!l) depth[su]=0;
			m-=l,lk->c-=l,op(lk)->c+=l;
			if(!m) break;
		}
		return f-m;
	}
	void solve()
	{
		vs=1,vt=N;
		flow=0;
		for(int l;bfs();)while(l=dinic(vs,inf))flow+=l;
		printf("%d\n",flow);
	}
}

int main()
{
	freopen("dinic.in","r",stdin);
	freopen("dinic.out","w",stdout);
	while(scanf("%d%d",&M,&N)!=-1)
	{
		init();
		solve::solve();
	}
	return 0;
}
