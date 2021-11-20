#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second

using namespace std;
const int N=1e4+5;
int read(){int res=0;char c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))res=res*10+c-'0',c=getchar();return res;}
void print(ll x){if(!x)return;else{print(x/10);putchar(x%10+'0');}return;}
void write(ll x){if(!x)putchar('0');else print(x);putchar('\n');return;}
int n,x[N],y[N],cnt[N];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++)
		x[i]=read();
	for(int i=0;i<n-1;i++)
		y[i]=x[i+1]-x[i],cnt[y[i]]++;
	sort(y,y+n-1);
	for(int i=0;i<n;i++)
		x[i+1]=x[i]+y[i];
	ll ans=0,sum=0,tot=1e15;
	do{
		ans=sum=0;
		for(int i=0;i<n-1;i++)
			x[i+1]=x[i]+y[i];
		for(int i=0;i<n;i++)
			ans+=x[i]*x[i],sum+=x[i];
		ans=ans*n-sum*sum;
		tot=min(tot,ans);
	}while(next_permutation(y,y+n-1));
	write(tot);
	return 0;
}
