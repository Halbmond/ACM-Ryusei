
void split(ll L, ll R){
	for(int w = 0; L < R; L += pow10[w]){
		while (L + pow10[w+1] <= R && L % pow10[w+1] == 0) w++;
		while (L + pow10[w] > R) w--;
	}
}
