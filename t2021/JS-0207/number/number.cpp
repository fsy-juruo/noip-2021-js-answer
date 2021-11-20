#include<bits/stdc++.h>
using namespace std;
int T,x;
short int pd[20000010];
bool sj(int k)
{
	while(k)
	{
		int k1=k%10;
		if(k1==7) return 1;
		k/=10;
	};
	return 0;
}
bool bj(int y)
{
	for(int i=1; i<=sqrt(y); i++) if(y%i==0&&(sj(i)||sj(y/i))) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>T;
	memset(pd, -1, sizeof(pd));
	for(int joker=1; joker<=T; joker++)
	{
		cin>>x;
		if(pd[x]==-1) pd[x] = bj(x);
		if(!pd[x]) {cout<<"-1"<<endl;continue;};
		for(int i=x+1; ; i++) 
		{
			if(pd[i]==-1) pd[i]=bj(i);
			if(pd[i]) {cout<<i<<endl;break;};
		}
	}
	return 0;
}
//µ¶ºÜ³ÃÊÖ£¬Ð»Ð»
