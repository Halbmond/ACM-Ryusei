//[Sdoi2011]À¹½Øµ¼µ¯
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define re(i,n) for(int i=0;i<n;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
#define PII pair<int,int>
#define PID pair<int,double>
#define c0 first
#define c1 second
using namespace std;
typedef unsigned ui;
typedef long long ll;
const int MXN=50010, inf=~0U>>1, mol=(1<<24)-3, SIZ=1<<24;

int N;ui n=0,m=0;
PII A[MXN],B[MXN];

int sa[MXN];
void init(){
	scanf("%d",&N);
	rep(i,1,N) scanf("%d%d",&A[i].c0,&A[i].c1);
	rep(i,1,N) sa[++n]=A[i].c0;
	sort(sa+1,sa+n+1);n=unique(sa+1,sa+n+1)-sa-1;
	rep(i,1,N) A[i].c0=lower_bound(sa+1,sa+n+1,A[i].c0)-sa;
	rep(i,1,N) sa[++m]=A[i].c1;
	sort(sa+1,sa+m+1);m=unique(sa+1,sa+m+1)-sa-1;
	rep(i,1,N) A[i].c1=lower_bound(sa+1,sa+m+1,A[i].c1)-sa;
}

void print(PID x){cout<<x.c0<<" "<<x.c1<<endl;}

int e[mol]={},next[mol],tot=0;PID I[SIZ];ui ori[SIZ];

inline void upd(PID&x,const PID&y){
	if (x.c0<y.c0){
		x=y;
	}else
	if (x.c0==y.c0){
		x.c1+=y.c1;
	}
}

int chuo=0;
PID ifo;
inline void ins(ui ori){
	ui p=ori-(ori>>24)*mol;
	for(int i=e[p];i>chuo;i=next[i])if (::ori[i]==ori){
		upd(I[i],ifo);return;
	}
	next[++tot]=e[p];e[p]=tot;::ori[tot]=ori;I[tot]=ifo;
}
inline void sel(ui ori){
	for(int i=e[ori-(ori>>24)*mol];i>chuo;i=next[i])if (::ori[i]==ori){
		ifo=I[i];return;
	}
}

void dstr(PII A[],PID f[]){
	rep(i,1,N){
		f[i]=PID(1,1);
		for(ui x=A[i].c0;x;x-=x&-x)
		for(ui y=A[i].c1;y;y-=y&-y){
			ifo=PID(0,0);sel(x*m+y);ifo.c0++;
			upd(f[i],ifo);
		}
		ifo=f[i];
		for(ui x=A[i].c0;x<=n;x+=x&-x)
		for(ui y=A[i].c1;y<=m;y+=y&-y) ins(x*m+y);
	}
}

PID u[MXN],d[MXN],LIS=PID(0,0);
double ans[MXN];
void solve(){
	rep(i,1,N) B[i]=PII(n+1-A[i].c0,m+1-A[i].c1);
	dstr(B,u);
	rep(i,1,N) upd(LIS,u[i]);
	reverse(A+1,A+N+1);
	chuo=tot;
	dstr(A,d);
	reverse(d+1,d+N+1);
	rep(i,1,N)if (u[i].c0+d[i].c0-1==LIS.c0){
		ans[i]=u[i].c1*d[i].c1/LIS.c1;
	}
	printf("%d\n",LIS.c0);
	rep(i,1,N)printf("%.7lf%c",ans[i],i<N?' ':'\n');
}

int cas;
int main(){
	init();
	solve();
	return 0;
}
