#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=b;a<=c;++a)
#define per(a,b,c) for(register int a=b;a>=c;--a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int MAXN=7001000;
int a[MAXN],b[MAXN],tot,len;
bool vis[MAXN*2],used[10001000];
inline void init(int dep,int pos,int x)
{
	if(dep>7){
		if(!used[x])a[++tot]=x;
		used[x]=1;
		return;
	}
	if(dep==pos)
		init(dep+1,pos,x*10+7);
	else
	{
		rep(i,0,9)
		init(dep+1,pos,x*10+i);
	}	
	
}

inline void preWork()
{
	rep(i,1,tot)
	{
		if(vis[a[i]])continue;
		for(int j=a[i];j<=10001000;j+=a[i])
		{
			vis[j]=1;
		}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	scanf("%d",&T);
	
	rep(i,1,7)init(1,i,0);
//	cout<<tot<<endl;
//	sort(a+1,a+tot+1);
//	len=unique(a+1,a+tot+1)-a;
	
	preWork();
	int cnt=0;
	rep(i,1,10001000)if(!vis[i])b[++cnt]=i;

	rep(i,1,T)
	{
		int x;
		scanf("%d",&x);
		if(vis[x])puts("-1");
		else
		{
			int t=upper_bound(b+1,b+cnt+1,x)-b;
			printf("%d\n",b[t]);
		}
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
