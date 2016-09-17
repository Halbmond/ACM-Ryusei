#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
typedef long long ll;
const int pr[]={2,3,5,7,11,13,17,19,23,29};

ll mo(ll a,ll pp){
	if (a >= 0 && a < pp) return a;
	a%=pp;
	if (a < 0) a+= pp;
	return a;
}

ll mulmod(ll a,ll b, ll pp){
	ll y=(ll)(1.0*a*b/pp+0.5);
	return mo(a*b-y*pp,pp);
}

ll powmod(ll a,ll b,ll pp){
	ll ans=1;
	for (; b; b >>= 1, a = mulmod(a, a, pp))
		if (b & 1) ans = mulmod(ans, a, pp);
	return ans;
}

/*
http://math.stackexchange.com/questions/366800/solution-set-for-congruence-x2-equiv-1-mod-m
m有原根
解方程 x * x = 1 (mod m)
考虑 m 的简化剩余系。
讨论 phi(m) 的奇偶。
x = 1 或 x = -1  (mod m)

m 没有原根时，可能有其他解
67 * 67 = 1 (mod 561)
*/
/*
若 x ^ (2m - 2) = 1 (mod m)
证明 x ^ (m - 1) = 1 (mod m)

(x, m) = 1
(phi(m), 2m - 2)
*/
bool witness(int a, ll n){
	ll u = n - 1;
	int t = 0;
	for (; u & 1 ^ 1; u >>= 1) ++t;
	ll x = powmod(a, u, n);
	//if (x == 1 || x == n - 1) return 0;
	for(int i = 0; i < t; ++i){
		ll nx = mulmod(x, x, n);
		if (nx == 1 && x != 1 && x != n - 1) return 0;
		x = nx;
	}
	return x != 1;
}

bool miller(ll x){
	if (x < 2) return 0;
	if (x == 2) return 1;
	if (x & 1 ^ 1) return 0;
	for(int i = 0; i < 10; ++i)
		if (pr[i] == x) return 1;
	for(int i = 0; i < 10; ++i)
		if (witness(pr[i], x)) return 0;
	return 1;
}

int main(){
	freopen("Miller-Rabin.in","r",stdin);
	ll n;
	while (cin >> n){
		cout << miller(n) << endl;
	}
	return 0;
}
