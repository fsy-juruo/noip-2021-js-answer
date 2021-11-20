#include <bits/stdc++.h>
#define ll long long
const int N=10000010;
int read()
{   int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return x*f;
}
int T,x;
int prime[N];
bool isfalse(int x)
{
	while((x%10)!=7&&x!=0)
	{
		x/=10;
//		printf("%d\n",x);
	}
	if(!x) return false;
	return true;
}
void init()
{
	for(int i=1;i<=N;i++)
	{
		if(!prime[i]&&isfalse(i))
		{
			prime[i]=i;
			if(i>(N/2)) continue;
			for(int j=i+i;j<=N;j+=i)
			{
				prime[j]=i;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	T=read();
	while(T--)
	{
		x=read();
		if(prime[x]) printf("-1\n");
		else 
		{
			x++;
			while(prime[x]) x++; 
			printf("%d\n",x);
		}
//	if(isfalse(x))
//	printf("%d\n",prime[x]);
	}
	return 0;
}
