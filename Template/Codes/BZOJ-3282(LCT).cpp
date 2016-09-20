//Tree
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl;
using namespace std;
const int MXN=300009;

struct node{
	node*c[2],*f;
	int w,s;bool rev;
	bool dir(){return f->c[1]==this;}
	bool isr(){return !f||(f->c[0]!=this&&f->c[1]!=this);}
	void setc(node*u,int d){if (u)u->f=this;c[d]=u;}
	void put(int k){w=s=k;rev=0;}
	void down(){
		if (rev){
			swap(c[0],c[1]);
			if (c[0])c[0]->rev^=1;
			if (c[1])c[1]->rev^=1;
			rev=0;
		}
	}
	void upd(){
		s=w;
		if (c[0])s^=c[0]->s;
		if (c[1])s^=c[1]->s;
	}
}nd[MXN]={};

void rot(node*u){
	node*p=u->f;int d=u->dir();
	if (!p->isr())p->f->setc(u,p->dir());else u->f=p->f;
	p->setc(u->c[!d],d);
	u->setc(p,!d);
	p->upd();
}

stack<node*>S;
void splay(node*u){
	for(node*p=u;S.push(p),!p->isr();p=p->f);
	for(;!S.empty();S.pop())S.top()->down();
	for(;!u->isr();)u->f->isr()?rot(u):(u->f->dir()==u->dir()?(rot(u->f),rot(u)):(rot(u),rot(u)));
	u->upd();//remember it!
}

void expose(node*u){for(node*v=NULL;u;u=u->f)splay(u),u->c[1]=v,(v=u)->upd();}

void expose(node*u,node*v){expose(u),splay(u),u->rev^=1;expose(v);splay(u);}

void merge(node*u,node*v){
	expose(v),splay(v),v->rev^=1;
	expose(u),splay(u);
	if (!v->f)v->f=u;
}

void split(node*u,node*v){expose(u,v);u->c[1]=v->f=NULL;u->upd();}

int N,Q;
int w[MXN];

void init(){
	scanf("%d%d",&N,&Q);
	rep(i,1,N)scanf("%d",w+i),(nd+i)->put(w[i]);
}

void solve(){
	int key,x,y;node*u,*v;
	rep(iq,1,Q){
		scanf("%d%d%d",&key,&x,&y);
		if (key==3){
			u=nd+x;
			expose(u,u);u->put(y);
		}else{
			u=nd+x,v=nd+y;
			expose(u,v);
			if (key==0){
				printf("%d\n",u->s);
			}
			if (key==1){
				merge(u,v);
			}
			if (key==2){
				split(u,v);
			}
		}
	}
}

int main() {
	init();
	solve();
	return 0;
}
