const int MXN=400010;double pi=3.1415926535897932384626;

struct cpx{
	double r,i;
	cpx operator +(const cpx&a){return(cpx){r+a.r,i+a.i};}
	cpx operator -(const cpx&a){return(cpx){r-a.r,i-a.i};}
	cpx operator *(const cpx&a){return(cpx){r*a.r-i*a.i,r*a.i+a.r*i};}
}A[MXN],B[MXN];

int N,n;

void init(){
	scanf("%d",&N);
	re(i,N)scanf("%lf%lf",&A[N-i-1].r,&B[i].r);
}

namespace solve{
	int n;
	void fft(cpx a[],int fl=1){
		for(int i=0,j=0;i<n;i++){
			if(i<j)swap(a[i],a[j]);
			for(int s=n;j^=s>>=1,~j&s;);
		}
		for(int m=1;m*2<=n;m<<=1){
			cpx b=(cpx){cos(fl*pi/m),sin(fl*pi/m)};
			for(int k=0;k<n;k+=m*2){
				cpx t=(cpx){1,0};
				rep(i,k,k+m-1){
					cpx x=a[i],y=t*a[i+m];
					a[i]=x+y,a[i+m]=x-y;
					t=t*b;
				}
			}
		}
	}
	void solve(){
		for(n=1;n<2*N;n<<=1);
		fft(A);fft(B);re(i,n)A[i]=A[i]*B[i];fft(A,-1);
		re(i,N)printf("%d\n",(int)round(A[N-1-i].r/n));
	}
}
