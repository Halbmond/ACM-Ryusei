//strongly connected components, directed graph
int nscc;
int own[MXN];
vector<int> vscc[MXN];
int flag[MXN],dfn[MXN],low[MXN],num,q[MXN],top;
void tarjan(int u){
	flag[u]=1;
	dfn[u]=low[u]=++num;q[++top]=u;
	tr(e[u]){
		if (flag[su]==0){
			tarjan(su);low[u]=min(low[u], low[su]);
		} else
		if (flag[su]==1){
			low[u]=min(low[u], dfn[su]);
		}
	}
	if (dfn[u] == low[u]){
		++nscc;
		do{
			flag[q[top]]=2;
			vscc[nvscc].push_back(q[top]);own[q[top]]=nscc;
		}while(q[top--]!=u);
	}
}
//Bridge, undirected graph (with possibly repeated edges)
void tarjan(int u, edge *b){
	dfn[u]=low[u]=++num;q[++top]=u;
	flag[u]=1;
	tr(e[u])if (lk!=b){
		if (flag[su]==0){
			tarjan(su, op(lk));low[u]=min(low[u],low[su]);
		}else
		if (flag[su]==1){
			low[u]=min(low[u],dfn[su]);
		}
	}
	if (dfn[u]<=low[u]){
		++nscc;
		do{
			flag[q[top]]=2;
			SCC[nscc].push_back(q[top]);own[q[top]]=nscc;
		}while (q[top--]!=u);
	}
}

//Cut, undirected graph, biconnect
//[Cerc2005]Knights of the Round Table
vector<int> SCC[MXN];
int isc[MXN],scc[MXM],vscc;
int flag[MXN],dfn[MXN],low[MXN],oud[MXN],num,q[MXM],top;
void tarjan(int u, edge * b){
	flag[u]=1;
	dfn[u]=low[u]=++num;
	tr(e[u])if (lk!=b){
		if (flag[su]==0){
			q[++top]=eid(lk);
			tarjan(su,op(lk)),low[u]=min(low[u],low[su]),oud[u]++;
			if (dfn[u]<=low[su]){
				isc[u]=1;vscc++;
				do{
					scc[q[top]]=vscc;
					SCC[vscc].push_back(q[top]);
				}while (q[top--]!=eid(lk));
			}
		}else
		if (flag[su]==1){
			q[++top]=eid(lk);
			low[u]=min(low[u],dfn[su]);
		}
	}
	flag[u]=2;
	if (!b) isc[u]=oud[u]>1;
}
