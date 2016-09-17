//Dynamic Rankings
const int MXN=10010,limit=1e9+10;

int N,Q;
int A[MXN];

void init(){
	scanf("%d%d",&N,&Q);
	rep(i,1,N) scanf("%d",A+i);
}


namespace solve{
	struct Seg{
		Seg*c[2];int sz;
	}tpool[MXN*999]={},*tcnt=tpool,*ro[MXN]={},*sp[MXN];int wei[MXN],tsp;
	
	int kk,result,value;
	void ins(Seg*&u,int x,int y){
		if (!u) u=tcnt++;
		u->sz+=value;
		if (x==y){
			return;
		}
		int mid=(x+y)>>1;
		if (kk<=mid) ins(u->c[0],x,mid);
		else ins(u->c[1],mid+1,y);
	}
	void sel(int x,int y){
		if (x==y){
			result=x;return;
		}
		int size=0;
		rep(i,1,tsp)if (sp[i]&&sp[i]->c[0]) size+=sp[i]->c[0]->sz*wei[i];
		int mid=(x+y)>>1;
		if (kk<=size){
			rep(i,1,tsp)if (sp[i]) sp[i]=sp[i]->c[0];sel(x,mid);
		}else{
			kk-=size;
			rep(i,1,tsp)if (sp[i]) sp[i]=sp[i]->c[1];sel(mid+1,y);
		}
	}
	
	void bins(int x,int k,int val){
		kk=k;value=val;
		for(;x<=N;x+=x&-x) ins(ro[x],0,limit);
	}
	void bsel(int x,int y,int k){
		kk=k;
		tsp=0;
		for(--x;x;x-=x&-x) sp[++tsp]=ro[x],wei[tsp]=-1;
		for(x=y;x;x-=x&-x) sp[++tsp]=ro[x],wei[tsp]=+1;
		sel(0,limit);
	}
	void solve(){
		//db(sizeof(tpool)/1024/1024),el;
		rep(i,1,N) bins(i,A[i],+1);
		
		rep(iq,1,Q){
			char ch;int x,y,k,val;
			while (!isalpha(ch=getchar()));
			if (ch=='C'){
				scanf("%d%d",&x,&val);
				bins(x,A[x],-1);
				bins(x,A[x]=val,+1);
			}else{
				scanf("%d%d%d",&x,&y,&k);
				bsel(x,y,k);
				printf("%d\n",result);
			}
		}
	}
}


int main(){
	init();
	solve::solve();
	return 0;
}
