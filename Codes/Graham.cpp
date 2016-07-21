
bool cmp(const point&a,const point&b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
ll multi(const point&a,const point&b,const point&c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}
point p[MXN],q[MXN];int n,top;
void graham(){
	sort(p+1,p+n+1,cmp);
	q[top=0]=p[1];
	rep(i,2,n){
		while (top>0&&multi(p[i],q[top],q[top-1])>=0) top--;
		q[++top]=p[i];
	}
	int len=top;
	red(i,n-1,1){
		while (top>len&&multi(p[i],q[top],q[top-1])>=0) top--;
		q[++top]=p[i];
	}
}

