#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int aa=max(a,b);
        int bb=min(a,b);
        int k=aa-bb;
        int temp=(k*(1+sqrt(5))/2);
        if(bb==temp)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}

