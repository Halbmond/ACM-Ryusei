//POJ-3530 A Modular Arithmetic Challenge
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
typedef long long ll;

int cas, tcas;

int M, D, L, R;

void init()
{
	scanf("%d %d %d %d", &M, &D, &L, &R);
}

namespace solve
{
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
	void solve()
	{
		D %= M;
		R = min(R, M - 1);
		if (L > R)
		{
			printf("-1\n");
			return;
		}
		cout << calc(M, D, L, R) << endl;
	}
}

int main()
{
	freopen("POJ-3530.in", "r", stdin);
	freopen("POJ-3530.out", "w", stdout);
	scanf("%d", &cas);
	for(tcas = 1; tcas <= cas; ++tcas)
	{
		init();
		solve::solve();
	}
	return 0;
}
