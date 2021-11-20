#include<bits/stdc++.h>
#define filename "number"
using namespace std;
int T,maxn,len,a[800001],x[200001];
bool flag[10001001];
bool check(int x)
{
    while(x)
    {
        if(x%10==7)return true;
        x/=10;
    }
    return false;
}
void init(int N)
{
    for(int i=2;i<=N;++i)
    {
        if(flag[i]||!check(i))continue;
        for(int j=1;i*j<=N;++j)flag[i*j]=true;
    }
    for(int i=1;i<=N;++i)
    {
        if(flag[i])continue;
        a[++len]=i;
    }
}
int binary(int l,int r,int x)
{
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]>x)r=mid-1;
        else l=mid+1;
    }
    return a[l];
}
namespace IO
{
    char buf[1<<21],*p1=buf,*p2=buf;
    char gc()
    {
        if(p1==p2)
        {
            p1=buf;
            p2=buf+fread(buf,1,1<<21,stdin);
        }
        return p1==p2?EOF:*p1++;
    }
    template<typename T>void read(T &x)
    {
        char ch=gc();
        while(!isdigit(ch))ch=gc();
        while(isdigit(ch))
        {
            x=(x<<3)+(x<<1)+(ch^48);
            ch=gc();
        }
    }
    template<typename T>void write(T x)
    {
        if(x>9)write(x/10);
        putchar(x%10+48);
    }
}using namespace IO;
int main()
{
    freopen(filename".in","r",stdin);
    freopen(filename".out","w",stdout);
    read(T);
    for(int i=1;i<=T;++i)
    {
        read(x[i]);
        maxn=max(maxn,x[i]);
    }
    init(maxn+1000);
    for(int i=1;i<=T;++i)
    {
        if(flag[x[i]])
        {
            putchar('-');
            putchar('1');
        }
        else write(binary(1,len,x[i]));
        putchar('\n');
    }
    return 0;
}