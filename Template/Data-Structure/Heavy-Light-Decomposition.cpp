const int MXN=100010;

struct edge{
	int t;edgenext;
}epool[MXN3],ecnt=epool;

int N,Q,I;
edgeE[MXN],G[MXN];

int fa[MXN],siz[MXN]={},dep[MXN]={},son[MXN]={},tp[MXN],dfn[MXN],num=0;
void dfs(int fu,int u){
	fa[u]=fu;siz[u]=1;dep[u]=dep[fu]+1;
	tr(E[u])if (su!=fu){
		dfs(u,su);siz[u]+=siz[su];
		if (siz[su]siz[son[u]]) son[u]=su;
	}
	tr(E[u])if (su!=fu&&su!=son[u]) Push(G[u],su);
	if (son[u])Push(G[u],son[u]);
}
void blt(int u,int top){
	tp[u]=top;dfn[u]=++num;
	tr(G[u])blt(su,su==son[u]topsu);
}
vectorints[MXN];
void put(int u,int v){
	s[dfn[u]].push_back(I);
	s[dfn[v]+1].push_back(-I);
}
void split(int u,int v){
	while (tp[u]!=tp[v]){
		if (dep[tp[u]]dep[tp[v]])swap(u,v);
		put(tp[u],u);u=fa[tp[u]];
	}
	if (dep[u]dep[v])swap(u,v);
	put(v,u);
}

int ans[MXN]={};
mapint,intT;
int main(){
	scanf(%d%d,&N,&Q);
	int x,y;
	rep(i,2,N)scanf(%d%d,&x,&y),Push(E[x],y),Push(E[y],x);
	dfs(0,1);
	blt(1,1);
	rep(i,1,Q)scanf(%d%d%d,&x,&y,&I),split(x,y);
	priority_queuePII Q;
	rep(i,1,N){
		re(k,s[i].size()){
			I=s[i][k];
			x=I0(++T[I])(I=-I,--T[I]);
			if (x)Q.push(PII(x,-I));
		}
		while (!Q.empty()&&Q.top().c0!=T[-Q.top().c1]) Q.pop();
		if (!Q.empty())ans[i]=-Q.top().c1;
	}
	rep(i,1,N)printf(%dn,ans[dfn[i]]);
	return 0;
}
