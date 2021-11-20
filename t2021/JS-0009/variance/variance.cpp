#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int inf=1039714778;
template <typename T> inline void chmin(T &x,const T &b) {x=min(x,b);}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,const pair<T1,T2> &o)
{
	cout<<'('<<o.first<<','<<o.second<<')';
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,const vector<T> &v)
{
	cout<<'{';
	for(int i=0;i<(int)v.size();i++)
	{
		cout<<v[i];
		if(i!=(int)v.size()-1) cout<<',';
	}
	cout<<'}';
	return cout;
}

int n;
int dp[105][75][4005];
int d[10005];
int a[10005];
int s[10005];
ll L,R;

void solve1()
{
    ll f[25];
    ll res=1e18;
    for(int mask=0;mask<(1<<(n-2));mask++)
    {
        ll l=L,r=R;
        int lp=0,rp=n-1;
        f[lp++]=l;
        f[rp--]=r;
        for(int i=0;i<n-2;i++)
        {
            if(mask & (1<<i)) f[lp++]=(l+=d[i]*n);
            else f[rp--]=(r-=d[i]*n);
        }
        ll s1=0,s2=0;
        for(int i=0;i<n;i++) s1+=f[i],s2+=f[i]*f[i];
        s1/=n;
        chmin(res,s2/n-s1*s1);
    }
    cout<<res<<endl;
}

void solve2()
{
    memset(dp,0x3f,sizeof(dp));
    int mx=*max_element(a,a+n);
    int l=a[0],r=a[n-1];
    dp[0][0][l+r]=l*l+r*r;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<=s[i];j++)
        {
            for(int tot=0;tot<=mx*i+l+r;tot++)
            {
                int v=dp[i][j][tot];
                if(v>=inf) continue;
                int x=l+j+d[i];
                chmin(dp[i+1][j+d[i]][tot+x],v+x*x);
                x=r-(s[i]-j)-d[i];
                chmin(dp[i+1][j][tot+x],v+x*x);
            }
        }
    }
    ll res=1e18;
    for(int j=0;j<=s[n-2];j++)
    {
        for(int tot=0;tot<=mx*n;tot++)
        {
            if(dp[n-2][j][tot]>=inf) continue;
            chmin(res,1LL*dp[n-2][j][tot]*n-1LL*tot*tot);
        }
    }
    cout<<res<<endl;
}

int main()
{
	// freopen("input.txt","r",stdin);
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        puts("0");
        return 0;
    }
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n-1;i++) d[i]=a[i+1]-a[i];
    sort(d,d+n-1);
    reverse(d,d+n-1);
    s[0]=0;
    for(int i=1;i<n;i++) s[i]=s[i-1]+d[i-1];
    L=n*a[0],R=n*a[n-1];
    if(n<=20)
    {
        solve1();
        return 0;
    }
    else
    {
        solve2();
        return 0;
    }
    // memset(dp,0x3f,sizeof(dp));
    // dp[0][0]=1LL*(av-L)*(av-L)+1LL*(R-av)*(R-av);
    // for(int i=0;i<n-2;i++)
    // {
    //     for(int j=0;j<=s[i];j++)
    //     {
    //         chmin(dp[i+1][j+d[i]],dp[i][j]+1LL*(av-(j+d[i])*n-L)*(av-(j+d[i])*n-L));
    //         chmin(dp[i+1][j],dp[i][j]+1LL*(R-n*((s[i]-j)+d[i])-av)*(R-n*((s[i]-j)+d[i])-av));
    //     }
    // }
    // cout<<R<<' '<<n<<' '<<s[0]<<' '<<0<<' '<<d[0]<<' '<<av<<endl;
    // cout<<dp[0][0]<<' '<<dp[1][0]<<endl;
    // ll res=1e18;
    // for(int j=0;j<=s[n-2];j++) chmin(res,dp[n-2][j]);
    // assert(res%n==0);
    // cout<<res/n<<endl;
	return 0;
}