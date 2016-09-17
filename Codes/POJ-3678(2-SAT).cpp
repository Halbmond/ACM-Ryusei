//Katu Puzzle
#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define red(i,r,l) for(int i=r;i>=l;i--)
#define re(i,n) for(int i=0;i<n;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
#define tr(p) for(edge*lk=p;lk;lk=lk->next)
#define su lk->t
using namespace std;
const int MXN=1010,MXM=1000010;

struct edge{
	int t;edge*next;
}epool[MXM*4],*ecnt=epool;

int N,M;
edge *E[MXN];

void addedge(int x,int y){
	*ecnt=(edge){y,E[x]},E[x]=ecnt++;
	if(x^y^1) *ecnt=(edge){x^1,E[y^1]},E[y^1]=ecnt++;
}

char buf[9];
void init()
{
	rep(i,1,M)
	{
		int x,y,c;
		scanf("%d %d %d %s",&x,&y,&c,buf);
		if(buf[0]=='A')
		{
			if(c==1)
			{
				addedge(x*2,x*2+1);
				addedge(y*2,y*2+1);
			}else
			{
				addedge(x*2+1,y*2);
			}
		}
		if(buf[0]=='O')
		{
			if(c==0)
			{
				addedge(x*2+1,x*2);
				addedge(y*2+1,y*2);
			}else
			{
				addedge(x*2,y*2+1);
			}
		}
		if(buf[0]=='X')
		{
			if(c==0)
			{
				addedge(x*2,y*2);
				addedge(y*2,x*2);
			}else
			{
				addedge(x*2,y*2+1);
				addedge(y*2+1,x*2);
			}
		}
	}
}


namespace solve
{
	int flag[MXN],dfn[MXN],low[MXN],num,q[MXN],top,scc[MXN],siz[MXN],nscc;
	void tarjan(int u)
	{
		flag[u]=1;
		dfn[u]=low[u]=++num;q[++top]=u;
		tr(E[u])
		{
			if(flag[su]==0) tarjan(su),low[u]=min(low[u],low[su]);
			else if(flag[su]==1) low[u]=min(low[u],dfn[su]);
		}
		if(dfn[u]==low[u])
		{
			nscc++;siz[nscc]=0;
			do{
				siz[scc[q[top]]=nscc]++;flag[q[top]]=2;
			}while(q[top--]!=u);
		}
	}
	void solve()
	{
		num=top=nscc=0;
		re(i,N+N)flag[i]=0;
		re(i,N+N)if(!flag[i])
		{
			tarjan(i);
		}
		//re(i,N+N)db(scc[i]);el;
		re(i,N)if(scc[i*2]==scc[i*2+1])
		{
			puts("NO");return;
		}
		puts("YES");
	}
}

int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		init();
		solve::solve();
	}
	return 0;
}
