
int rad[MXN];
void manacher(char s[],int n){
	for(int i=1,j=0,k;i<n;i+=k,j=max(j-k,0)){
		for(;s[i-j-1]==s[i+j+1];)j++;rad[i]=j;
		for(k=1;k<=j&&rad[i-k]!=rad[i]-k;k++) rad[i+k]=min(rad[i-k],rad[i]-k);
	}
}
