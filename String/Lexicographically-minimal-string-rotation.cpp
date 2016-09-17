int minr(int s[],int n){
	int i,j,k,t;
	for(i=0,j=1,k=0;i<n&&j<n&&k<n;){
		t=s[(i+k)%n]-s[(j+k)%n];
		if (!t) k++;else{
			t>0?i+=k+1:j+=k+1;
			j+=i==j;
			k=0;
		}
	}
	return min(i,j);
}
