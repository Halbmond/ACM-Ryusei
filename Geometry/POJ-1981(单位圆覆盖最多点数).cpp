//Circle and Points
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define red(i,r,l) for(int i=r;i>=l;i--)
#define re(i,n) for(int i=0;i<n;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
const int MXN=310;double pi=3.1415926535897932384626;

inline double sqr(const double&x){return x*x;}

struct point{
	double x,y;
	void read(){scanf("%lf%lf",&x,&y);}
	void adj(){
		while(x<0)x+=2*pi;
		while(y<0)y+=2*pi;
		while(x>2*pi)x-=2*pi;
		while(y>2*pi)y-=2*pi;
	}
	point operator -(const point&a)const{return(point){x-a.x,y-a.y};}
	point operator +(const point&a)const{return(point){x+a.x,y+a.y};}
};
double dist(const point&a,const point&b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}

int N;
point P[MXN],A[MXN];

void init(){
	rep(i,1,N)P[i].read();
}

namespace solve{
	struct event{
		double x;int d;
		bool operator <(const event&a)const{return x<a.x||x==a.x&&d>a.d;}
	}eve[MXN*2];int teve;
	
	void solve(){
		int answer=0;
		rep(c,1,N){
			teve=0;
			int tot=0;
			rep(i,1,N)if(i!=c){
				double D=dist(P[c],P[i]);
				if(D<=2.0){
					double alpha=atan2(P[i].y-P[c].y,P[i].x-P[c].x),beta=acos(D/2);
					A[i]=(point){alpha-beta,alpha+beta};
					A[i].adj();
					if(A[i].x<=A[i].y){
						eve[++teve]=(event){A[i].x,+1};
						eve[++teve]=(event){A[i].y,-1};
					}else{
						tot++;
						eve[++teve]=(event){A[i].x,+1};
						eve[++teve]=(event){A[i].y,-1};
					}
				}
			}
			sort(eve+1,eve+teve+1);
			answer=max(answer,tot);
			rep(i,1,teve){
				tot+=eve[i].d;
				answer=max(answer,tot);
			}
		}
		printf("%d\n",answer+1);
	}
}

int main(){
	while(scanf("%d",&N)&&N){
		init();
		solve::solve();
	}
	return 0;
}
