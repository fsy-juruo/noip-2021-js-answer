#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
inline void write(int x)
{
	if(x<0) {putchar('-');x=~(x-1);}
	if(x>9) write(x/10);
	putchar(x%10+48);
}

#define MAX 10005000+5
int T,pin;
int rec[MAX];
bool v[MAX]; 

bool check(int x)
{
	bool flag=false;
	while(x)
	{
		int d=x%10;
		if(d==7)
		{
			flag=true;
			break;
		}
		x/=10;
	}
	return flag;
}

void sol1()
{
	for(int i=1;i<=10005000;i++)
		if(v[i]) continue;
		else if(check(i))
		{
			v[i]=true;
			for(int j=2;j*i<=10005000;j++)
				v[j*i]=true;
		}
		else rec[++pin]=i;
	while(T--)
	{
		int x=read();
		int pos=lower_bound(rec+1,rec+1+pin,x)-rec;
		if(rec[pos]!=x) write(-1);
		else write(rec[pos+1]);
		putchar('\n');
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	sol1();
	return 0;
}
