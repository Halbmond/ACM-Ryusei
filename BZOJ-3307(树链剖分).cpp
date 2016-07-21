//雨天的尾巴
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define re(i,n) for(int i=0;i<n;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
#define tr(p) for(edge*lk=p;lk;lk=lk->next)
#define su lk->t
#define Push(p,x) *ecnt=(edge){x,p},p=ecnt++
#define PII pair<int,int>
#define c0 first
#define c1 second
using namespace std;
const int MXN=100009;

struct edge{
	int t;edge*next;
}epool[MXN*3],*ecnt=epool;

int N,Q,I;
edge*E[MXN],*G[MXN];

int fa[MXN],siz[MXN]={},dep[MXN]={},son[MXN]={},tp[MXN],dfn[MXN],num=0;
void dfs(int fu,int u){
	fa[u]=fu;siz[u]=1;dep[u]=dep[fu]+1;
	tr(E[u])if (su!=fu){
		dfs(u,su);siz[u]+=siz[su];
		if (siz[su]>siz[son[u]]) son[u]=su;
	}
	tr(E[u])if (su!=fu&&su!=son[u]) Push(G[u],su);
	if (son[u])Push(G[u],son[u]);
}
void blt(int u,int top){
	tp[u]=top;dfn[u]=++num;
	tr(G[u])blt(su,su==son[u]?top:su);
}
vector<int>s[MXN];
void put(int u,int v){
	s[dfn[u]].push_back(I);
	s[dfn[v]+1].push_back(-I);
}
void split(int u,int v){
	while (tp[u]!=tp[v]){
		if (dep[tp[u]]<dep[tp[v]])swap(u,v);//Attention!! 是tp[u]不是u
		put(tp[u],u);u=fa[tp[u]];
	}
	if (dep[u]<dep[v])swap(u,v);
	put(v,u);
}

int ans[MXN]={};
map<int,int>T;
int main(){
	scanf("%d%d",&N,&Q);
	int x,y;
	rep(i,2,N)scanf("%d%d",&x,&y),Push(E[x],y),Push(E[y],x);
	dfs(0,1);
	blt(1,1);
	rep(i,1,Q)scanf("%d%d%d",&x,&y,&I),split(x,y);
	priority_queue<PII> Q;
	rep(i,1,N){
		re(k,s[i].size()){
			I=s[i][k];
			x=I>0?(++T[I]):(I=-I,--T[I]);
			if (x)Q.push(PII(x,-I));
		}
		while (!Q.empty()&&Q.top().c0!=T[-Q.top().c1]) Q.pop();
		if (!Q.empty())ans[i]=-Q.top().c1;
	}
	rep(i,1,N)printf("%d\n",ans[dfn[i]]);
	return 0;
}
