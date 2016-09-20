double integral(double l,double r){
	return (f(l)+f(r)+f((l+r)/2.0) * 4)/(6.0 * (r-l));
}
double calc(double l,double r){
	double cur=integral(l,r),m=(l+r)/2.0;
	double tmp=integral(l,m)+integral(m,r);
	if (fabs(cur-tmp)<EPS) return cur;
	return calc(l,m)+calc(m,r);
}
