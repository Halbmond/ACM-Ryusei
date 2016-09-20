
//128位乘

typedef long long ll ;

inline ll pdtt(ll x,ll y,ll z){
    x =(x*y-(ll)(((long double)x*y+0.5)/(long double)z)*z+z)%z;
    if (x < 0) x += z;
    return x;
}
inline ll mod_mul(ll a, ll b, int modu = ::modu) {
    ll res = 0;
    while (b) {
        if (b & 1) (res += a) %= modu;
        (a <<= 1) %= modu;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a , b , c ;
    for(;;) {
        a = (((ll)(rand())*32768ll+(ll)(rand()))*32768ll+(ll)(rand()))*32768+(ll)(rand())+1 ;
        b = (((ll)(rand())*32768ll+(ll)(rand()))*32768ll+(ll)(rand()))*32768+(ll)(rand())+1 ;
        c = rand(); //(ll)(rand())*32768ll+(ll)(rand())+1 ;
        //((a%c)*(b%c))%c
        if ( pdtt(a,b,c) != mull(a,b,c)) {
            //cout << a << "*" << b << " = " << a%c << "*" << b%c << " = " << ((a%c)*(b%c))%c << "\n" ;
            cout << "mull(" << a << "," << b << "," << c << ") = " << mull(a,b,c) << "\n" ;
            cout << "pdtt(" << a << "," << b << "," << c << ") = " << pdtt(a,b,c) << "\n" ;
        }
    }
}








――――――――――――――――――――

随机了大数据。。几乎没几个是对的。。。。
。。。。看来 long double 非常不靠谱。。。。。

建议使用 head 算法。


――――――――――――――――――――

哦，似乎是对的。。。使用前要保证 x, y <= z 。。。。

三个算法都写出来吧。。
从上到下分别是



―― head
―― long double
―― 倍增



#define m _mod
ll _mod;
inline void Incc(ll&x,ll y){
    x += y; if (x >= m) x -= m;
}

inline ll pdtt(ll x,ll y){
    x%=m,y%=m;
    ll p=sqrt(m)+0.5,q=p*p-m,a=x/p,b=x%p,c=y/p,d=y%p,e=a*c/p*q,f=a*c%p*q;
    ll t=((a*d+b*c)%m+e)%m;x=t/p*q,y=t%p*p;
    x = (((b*d+f)%m+x)%m+y)%m; if (x<0) x += m;
    return x;
}

inline ll pdtt1(ll x,ll y){
    x%=m,y%=m;
    x =(x*y-(ll)(((long double)x*y+0.5)/(long double)m)*m)%m; if (x<0) x += m;
    return x;
}

inline ll pdtt2(ll a,ll b){
    a%=m,b%=m;
    ll c=0; for (;b;b>>=1,Incc(a,a))
    if (b&1) Incc(c,a);
    return c;
}
#undef m
