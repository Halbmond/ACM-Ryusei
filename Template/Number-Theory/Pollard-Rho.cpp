
ll pollardRho(ll n, ll seed) {
	ll x, y;
	x = y = rand() % (n - 1) + 1;
	ll head = 1 ，tail = 2;
	while (true) {
		x = multiplyMod(x, x, n);
		x = addMod(x, seed, n);
		if (x == y) return n;
		ll d = gcd(abs(x - y), n);
		if (1 < d && d < n) return d;
		head ++;
		if (head == tail) {
			y = x;
			tail <<= 1;
		}
	}
}

vector <ll> divisors;
void factorize(ll n) {
	if (n == 1) return;
	if (isPrime(n)) {
		divisors.push_back(n);
	} else {
		ll d = n;
		while (d >= n) {
			d = pollardRho(n, rand() % (n - 1) + 1);
		}
		factorize(n / d); factorize(d);
	}
}
