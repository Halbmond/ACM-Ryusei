const int MXN=510;

int n;
struct gauss{
	double a[MXN];
	void print(){
		rep(i,0,n) printf("%.2lf ",a[i]);el;
	}
}X[MXN];

int N,M;
int G[MXN][MXN]={},od[MXN]={};

void init(){
	scanf("%d%d",&N,&M);
	rep(i,1,M){
		static int x,y;
		scanf("%d%d",&x,&y),G[x][y]=G[y][x]=1,od[x]++,od[y]++;
	}
	n=N-1;
	rep(i,1,N-1){
		X[i-1].a[i-1]=1.0;
		X[i-1].a[i-1]=1.0;
		rep(j,1,N-1)if (G[i][j]) X[i-1].a[j-1]=-1.0/od[j];
		X[i-1].a[n]=i==1?1.0:0.0;
	}
}

namespace solve{
	void Gauss(){
		re(no,n){
			int mx=no;
			rep(k,no+1,n)if (fabs(X[mx].a[no])<fabs(X[k].a[no])) mx=k;
			swap(X[mx],X[no]);
			rep(j,no+1,n) X[no].a[j]/=X[no].a[no];X[no].a[no]=1;
			re(i,n)if (i!=no){
				rep(j,no+1,n) X[i].a[j]-=X[no].a[j]*X[i].a[no];
				X[i].a[no]=0;
			}
		}
	}
	
	double sq[MXN*MXN];int top=0;
	double answer=0;
	void solve(){
		Gauss();
		//re(i,n) printf("%d %.2lf\n",i+1,X[i].a[n]);return;
		X[n].a[n]=0;
		rep(i,1,N)
		rep(j,i+1,N)if (G[i][j]){
			sq[++top]=X[i-1].a[n]/od[i]+X[j-1].a[n]/od[j];
		}
		sort(sq+1,sq+top+1);
		rep(i,1,top) answer+=(top+1-i)*sq[i];
		printf("%.3lf\n",answer);
	}
}

int main(){
	freopen("BZOJ-3143.in","r",stdin);
	freopen("BZOJ-3143.out","w",stdout);
	init();
	solve::solve();
	return 0;
}

//Guass-Xor
//[Sdoi2010]
const int MXN=1010,MXM=2010;

int n,M;
bitset<MXN> X[MXN],B;int tot=0;

int main(){
	scanf("%d%d",&n,&M);
	rep(tim,1,M){
		rep(i,0,n){
			static char ch;
			while (!isdigit(ch=getchar()));B[i]=ch=='1';
		}
		re(i,n)if (B[i]){
			if (X[i][i]){
				B^=X[i];
			}else{
				X[i]=B;tot++;
				break;
			}
		}
		if (tot==n){
			printf("%d\n",tim);
			red(i,n-1,0)
			rep(j,i+1,n-1)if (X[i][j]){
				X[i][j]=0;X[i][n]=X[i][n]^X[j][n];
			}
			re(i,n) puts(X[i][n]?"?y7M#":"Earth");
			return;
		}
	}
	puts("Cannot Determine");
	return 0;
}