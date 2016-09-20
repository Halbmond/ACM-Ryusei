const int MAXN = 10000;
int match[MAXN];
int levelx[MAXN], levely[MAXN], link[MAXN]; 
int d[MAXN]; 
inline bool Bfs(void) { 
	int head = 1, tail = 0; 
	memset(levely, 0, sizeof levely); 
	for (int i = 1; i <= n; i++) { 
		if (!match[i]) d[++tail] = i; 
		levelx[i] = 0; 
	} 
	bool ret = false; 
	while (head <= tail) { 
		int now = d[head++]; 
		for (Edge *p = a[now]; p; p = p->next) if (levely[p->y] == 0) { 
			levely[p->y] = levelx[now] + 1; 
			if (link[p->y] == 0) ret = true; 
			else levelx[link[p->y]] = levely[p->y] + 1, d[++tail] = link[p->y]; 
		}
	}
	return ret;
} 
bool Find(int u) { 
	for (Edge *p = a[u]; p; p = p->next) if (levely[p->y] == levelx[u] + 1) { 
		levely[p->y] = 0; 
		if (link[p->y] == 0 || Find(link[p->y])) { 
			match[u] = p->y; link[p->y] = u; 
			return true; 
		}
	}
	return false; 
} 
inline void Match(void) { 
	while (Bfs()) 
		for (int i = 1; i <= n; i++) 
			if (!match[i]) Find(i); 
} 
inline void clear(void) {
	memset(match, 0, sizeof match);
	memset(link, 0, sizeof link);
	memset(levelx, 0, sizeof levelx);
	memset(levely, 0, sizeof levely);
}

/*
BZOJ-1891 丘比特的烦恼
给定一个有完备匹配的二分图G，问哪些边一定会出现在完备匹配中，哪些边一定不会出现在完备匹配中。
N<=200000，M<=600000

2010 莫涛 hw2

先求个最大匹配，再把无向边定向，匹配边由x集->y集，非匹配边由y集->x集，这样定向了之后，任意一条从x集出发y集结束的路径就对应了一条增广路。

求出这个图的强连通分量，如果一条边的两个端点处于同一个分量内，那这条边其实没什么影响力，删了这条边原图仍然存在完备匹配。

而如果这条边的两个端点不在一个分量内，那这条边如果是匹配边那就一定会被选，如果不是匹配边那就一定不会被选。
*/
