int sa[MXN],rk[MXN],ht[MXN];
void DA(int n,int m){
	static int t[2][MXN*2]={},*x=t[0],*y=t[1],w[MXN],p;
	rep(i,1,n)x[i]=A[i],y[i]=i;
	rep(i,0,m)w[i]=0;
	rep(i,1,n)w[x[i]]++;
	rep(i,1,m)w[i]+=w[i-1];
	red(i,n,1)sa[w[x[y[i]]]--]=y[i];
	for(p=1,j=1;p<n;m=p,j<<=1){
	p=0;
	rep(i,n-j+1,n)y[++p]=i;
	rep(i,1,n)if (sa[i]>j)y[++p]=sa[i]-j;
	rep(i,0,m)w[i]=0;
	rep(i,1,n)w[x[i]]++;
	rep(i,1,m)w[i]+=w[i-1];
	red(i,n,1)sa[w[x[y[i]]]--]=y[i];
	swap(x,y);x[sa[1]]=p=1;
	rep(i,2,n)x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]?p:++p;
	}
	p=0;
	rep(i,1,n){
		p?p--:0;
		if(rk[i]>1)for(;s[i+p]==s[sa[rk[i]-1]+p];)p++;
		ht[rk[i]]=p;
	}
}

