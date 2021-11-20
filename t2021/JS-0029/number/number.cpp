#include<bits/stdc++.h>
using namespace std;
struct ins{
    template<typename T>void read(T &n)
    {
        n=0;char c=getchar();bool f=1;
        for(;!isdigit(c);c=getchar())if(c=='-')f=0;
        for(;isdigit(c);c=getchar())n=n*10+c-'0';
        if(f==0)n=-n;
    }
    template<typename T>ins operator >>(T &n)
    {
        read(n);
        return *this;
    }
}yin;
const int maxn=1e7+10;
int check(int x)
{
    while(x){if(x%10==7)return 1;x/=10;}
    return 0;
}
int pp[maxn],nxt[maxn];
void init()
{
    for(int i=1;i<=maxn-10;i++){
        if(!pp[i])
            if(check(i))
            {   
                pp[i]=1;
                for(int j=i;j<=maxn-10;j+=i)
                    pp[j]=1;
            }
    }
    int las=1e7+1;
    for(int i=maxn-10;i>=1;i--)if(!pp[i]){nxt[i]=las;las=i;}
}
int main(){
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
    init();
    int TTT;
    yin>>TTT;
    while(TTT--)
    {
        int x;
        yin>>x;
        if(pp[x])puts("-1");
        else cout<<nxt[x]<<endl;
    }
}
