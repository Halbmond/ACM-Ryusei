//costflow
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
#define tr(p) for(edge*lk=p;lk;lk=lk->next)
#define su lk->t
#define op (epool+((pre[u]-epool)^1))
using namespace std;
const int MXN=101,MXM=501,inf=~0U>>2;

int N,M;

struct edge{
	int t,c,w;edge*next;
}epool[MXM<<1],*ecnt=epool;

edge*e[MXN];

void add(int x,int y,int c,int w){
	*ecnt=(edge){y,c,w,e[x]},e[x]=ecnt++;
	*ecnt=(edge){x,0,-w,e[y]},e[y]=ecnt++;
}

void init(){
	scanf("%d %d",&N,&M);
	int x,y,c,w;
	rep(i,1,M){
		scanf("%d %d %d %d",&x,&y,&c,&w);
		add(x,y,c,w);
	}
}

/*
#define op(p) (epool+((p-epool)^1))
int exp(int u,int m,int vt){
	if (u==vt) return m;
	flag[u]=1;
	int l=m;
	tr(e[u])if (!flag[su]&&lk->c&&dis[su]==dis[u]+lk->w){
		int t=exp(su,min(l,lk->c),vt);
		lk->c-=t,op(lk)->c+=t,l-=t,cost+=t*lk->w;
	}
	return m-l;
}
*/

int flow,cost;
int q[MXN],dis[MXN],flag[MXN],t,w;
edge*pre[MXN];
bool aug(int vs,int vt){
	rep(i,1,N)dis[i]=inf,flag[i]=0;
	t=w=0;q[w++]=vs;dis[vs]=0,flag[vs]=1;
	int u;
	while (t<w){
		u=q[t++];
		tr(e[u])if (lk->c&&dis[su]>dis[u]+lk->w){
			dis[su]=dis[u]+lk->w;pre[su]=lk;
			if (!flag[su]){
				flag[su]=1;q[w++]=su;
			}
		}
		flag[u]=0;
	}
	if (dis[vt]==inf) return 0;
	//rep(i,1,N)db(dis[i]),el;
	int t=inf;
	for(u=vt;u!=vs;u=op->t)t=min(t,pre[u]->c);
	for(u=vt;u!=vs;u=op->t)pre[u]->c-=t,op->c+=t,cost+=t*pre[u]->w;
	//for(int t;memset(flag,0,sizeof(flag)),t=exp(vs,inf,vt),t;flow+=t);
	return 1;
}

void solve(){
	for(flow=cost=0;aug(1,N););
	cout<<flow<<" "<<cost<<endl;
}

int main(){
	freopen("costflow.in","r",stdin);
	freopen("costflow.out","w",stdout);
	init();
	solve();
	return 0;
}
