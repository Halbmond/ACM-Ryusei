

扩展欧几里得
void gcd(int a,int b,int &x,int &y){
	b?(gcd(b,a%b,y,c),y-=a/b*x):(x=1,y=0);
}



逆元
int inv(int n){
	int x,y;gcd(n,P,x,y);
	if(x<0)x+=P;return x;
}

inv[1]=1;
for(int i=2;i<=n;i++) inv[i]=inv[p%i]*(p-p/i)%p;




中国剩余定理
for(int i=0;i<n;i++) ans+=(M/m[i])*inv(M/m[i],m[i])*res[i];

