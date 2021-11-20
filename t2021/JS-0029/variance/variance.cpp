#include<bits/stdc++.h>
using namespace std;
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
const int maxn=1e4+10;
int n;
int a[maxn],b[maxn];
void ch(vector<int> &ans,int opt,int l,int r)
{
    if(l+1>r-1)return ;
    if(opt==1)
    {
        while(1){
            
    int mi=l+1;
            for(int i=l+1;i<=r-1;i++)
            {
                if(ans[i+1]+ans[i-1]-ans[i]-ans[i]>ans[mi+1]+ans[mi-1]-ans[mi]-ans[mi])
                {
                    mi=i;
                }
            }
            if(ans[mi+1]+ans[mi-1]-ans[mi]-ans[mi]>0)
            {
                ans[mi]=ans[mi+1]+ans[mi-1]-ans[mi];
            }else break;
        }
    }
    else
    {
        while(1){
            int mi=l+1;
            for(int i=l+1;i<=r-1;i++)
            {
                if(ans[i+1]+ans[i-1]-ans[i]-ans[i]<ans[mi+1]+ans[mi-1]-ans[mi]-ans[mi])
                {
                    mi=i;
                }
            }
            if(ans[mi+1]+ans[mi-1]-ans[mi]-ans[mi]<0)
            {
                ans[mi]=ans[mi+1]+ans[mi-1]-ans[mi];
            }else break;
        }
    }
}
int cnt[maxn];
long long solve(int p)
{
    vector<int> b;
    // b.push_back
    int tot=0;
    for(int i=p-1;i<=n;i++)if(i)b.push_back(a[i]);
    ch(b,0,0,b.size()-1);
    long long ans1,ans2;
    ans1=ans2=0;
    for(int i=1;i<b.size();i++)
        ans1+=b[i]*b[i],ans2+=b[i];
    b.clear();
    for(int i=1;i<=p;i++)
    {
        b.push_back(a[i]);
    }
    ch(b,1,0,b.size()-1);
    for(int i=0;i<b.size()-1;i++)
        ans1+=b[i]*b[i],ans2+=b[i];
    return ans1*n-ans2*ans2;
}
int main()
{
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    yin>>n;
    for(int i=1;i<=n;i++)
    {
        yin>>a[i];
    }
    long long ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,solve(i));
    }
    cout<<ans<<endl;
    return 0;
}