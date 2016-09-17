//BZOJ-1251
#define id(p) (p-T)

const int MXN=50010,inf=~0U>>2;

int N, Q;

struct node{
	node*c[2],*f;
	int v,m,ls,rev,sz;
	bool dir(){
		if (!f){
			cout<<"ERROR"<<endl;
			return 0;
		}
		return f->c[1]==this;
	}
	void setc(node*u,int d){
		c[d]=u;if (u)u->f=this;
	}
	void put(int s){
		v+=s;
		m+=s;
		ls+=s;
	}
	void down(){
		if (rev){
			swap(c[0],c[1]);
			if (c[0]) c[0]->rev^=1;
			if (c[1]) c[1]->rev^=1;
			rev=0;
		}
		if (c[0]) c[0]->put(ls);
		if (c[1]) c[1]->put(ls);
		ls=0;
	}
	void upd(){
		sz=1,m=v;
		if (c[0]) m=max(m,c[0]->m),sz+=c[0]->sz;
		if (c[1]) m=max(m,c[1]->m),sz+=c[1]->sz;
	}
}T[MXN]={},*ro;

void print(){
	rep(i,1,N) db(i),db(T[i].m),db(T[i].ls),db(id(T[i].c[0])),db(id(T[i].c[1])),el;
}

void rot(node*x){
	node*p=x->f;int d=x->dir();
	if (p->f) p->f->setc(x,p->dir());else x->f=p->f;
	p->setc(x->c[!d],d);
	x->setc(p,!d);
	p->upd();if (ro==p) ro=x;
}

node*find(int k){
	if (k<=0||k>N){
		cout<<"ERROR"<<endl;
		return NULL;
	}
	int sz;
	for(node*u=ro;;){
		if (u==NULL){
			cout<<"ERROR"<<endl;
			return NULL;
		}
		u->down();
		sz=1;if (u->c[0])sz+=u->c[0]->sz;
		if (k==sz) return u;
		if (k<sz) u=u->c[0];else u=u->c[1],k-=sz;
	}
}

stack<node*>s;
void splay(node*x,node*y=NULL){
	if (!x){
		cout<<"ERROR"<<endl;
		return;
	}
	//for(node*p=x;p;p=p->f) s.push(p);
	//for(;!s.empty();s.pop()) s.top()->down();
	for(;x->f!=y;){
		(x->f->f==y)?rot(x):(x->dir()==x->f->dir()?(rot(x->f),rot(x)):(rot(x),rot(x)));
	}
	x->upd();
}

node*splay(int l,int r){
	if (l==1&&r==N) return ro;
	if (l==1){
		splay(find(r+1));
		return ro->c[0];
	}
	if (r==N){
		splay(find(l-1));
		return ro->c[1];
	}
	splay(find(r+1));
	splay(find(l-1),ro);
	return ro->c[0]->c[1];
}

void init(){
	ro=T+N;
	rep(i,2,N) T[i].setc(T+i-1,0);
	rep(i,1,N) T[i].sz=i;
}

int main() {
	scanf("%d %d",&N,&Q);
	init();
	int key,x,y,val;
	rep(iq,1,Q){
		scanf("%d %d %d",&key,&x,&y);
		node*u=splay(x,y);
		if (key==1){
			scanf("%d",&val);
			u->put(val);
		}else
		if (key==2){
			u->rev^=1;
		}else
		if (key==3){
			printf("%d\n",u->m);
		}
		//print();el;
	}
	return 0;
}
