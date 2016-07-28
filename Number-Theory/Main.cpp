

扩展欧几里得
void gcd(int a,int b,int &x,int &y){
	b?(gcd(b,a%b,y,c),y-=a/b*x):(x=1,y=0);
}
// Caution!! maybe exceed int limit

逆元
int inv(int n){
	int x,y;gcd(n,P,x,y);
	if(x<0)x+=P;return x;
}

inv[1]=1;
for(int i=2;i<=n;i++) inv[i]=inv[p%i]*(p-p/i)%p;




中国剩余定理
for(int i=0;i<n;i++) ans+=(M/m[i])*inv(M/m[i],m[i])*res[i];




	/*
		L <= D * x - M * y <= R
		x >= 0
		return the minimal x
		it can be proved that y is also minimal.

		L <= D * x <= R (mod M)
		L <= D * x - M * y <= R
		-R <= M * y - D * x <= -L
		-R <= M * y <= -L (mod D)

		POJ-3530 A Modular Arithmetic Challenge
		HDU-5022 Ene's problem
	*/
	ll calc(ll m, ll d, ll l, ll r)
	{
		ll k = (l - m + 1) / m;
		l = l - k * m;
		r = r - k * m;
		if (l == 0 || r >= m) return 0;
		if (d == 0)
		{
			return -1;
		}
		ll y = calc(d, m % d, -r, -l);
		if (y == -1) return -1;
		ll x = (l + m * y + d - 1) / d;
		//db(m), db(d), db(l), db(r), db(x), db(y),el;
		return x;
	}