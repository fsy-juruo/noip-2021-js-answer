#include<bits/stdc++.h>
using namespace std;

const int mxn=10000008;

int rds()
{
	char c=getchar();
	int ans=0;
	while(  c<'0' ||  c>'9' ) c=getchar();
	while( c>='0' && c<='9' ) ans=ans*10+c-'0', c=getchar();
	return ans;
}

bool hsvn(int x)
{
	if(x<10) return x==7;
	if(x%10==7) return 1;
	return hsvn(x/10);
}

bool check(int x)
{
	if(hsvn(x)) return 1;
	for(int i=2; i*i<=x; i++) if(x%i==0 && hsvn(i)|hsvn(x/i)) return 1;
	return 0;
}

void wrts(int a)
{
	if(a<10) putchar(a%10+'0'); 
	else wrts(a/10), putchar(a%10+'0');
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T=rds(), x;
	check(1);
	while(T--)
	{
		x=rds();
		if(check(x)) puts("-1");
		else
		{
			while(x++) if(!check(x)) break;
			wrts(x); putchar('\n');
		}
	}
	return 0;
}
