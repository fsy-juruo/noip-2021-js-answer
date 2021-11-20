#include<bits/stdc++.h>
//#define int long long
//#define mo
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int T,a[200005],ma;
int nxt[20000005];
bool ha[20000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++)
		a[i]=read(),ma=max(a[i],ma);
	for(int i=1;1;i++)
	{
		if (ha[i]==1) continue;
		int k=i,f=0;
		while(k)
		{
			if (k%10==7)
			{
				f=1;
				break;
			}
			k/=10;
		}
		if (f==1) 
		{
			for(int j=i;1;j+=i)
			{
				ha[j]=1;
//				if (j==ma) cout<<i<<endl;
				if (j>ma) break;
			}
		}
		else
		{
			if (i>ma) break;
		}
	}
//	for(int i=ma;i<=ma+100;i++)
//		cout<<i<<" "<<ha[i]<<endl;
	int la=1;
	for(int i=2;1;i++)
		if (ha[i]==0) 
		{
			nxt[la]=i,la=i;
			if (la>ma) break;
		}
	for(int i=1;i<=T;i++)
		if (ha[a[i]]==1) cout<<"-1"<<endl;
		else cout<<nxt[a[i]]<<endl;
	return 0;
}

