#include <bits/stdc++.h>
const int MAXN=10000005;
const int MAXT=200005;
struct node
{
	bool c;
	int nxt,x;
	inline void put(void){printf("%d %d\n",c,x);}
}a[MAXN];
int T,n,i,j,k,x,cnt,q[MAXT],pri[MAXN];
bool isPri[MAXN];
inline void read(int &x)
{
	short negative=1;
	x=0;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-')
			negative=-1;
		c=getchar();
	}
	while (c>='0' && c<='9')
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=negative;
} 
inline void print(int x)
{
	if (x<0)
		putchar('-'),x=-x;
	if (x>9)
		print(x/10);
	putchar(x%10+'0');
}
inline bool check(int x)
{
	while (x)
	{
		if (x%10==7)
			return true;
		x/=10;
	}
	return false;
}
inline void init(void)
{
	isPri[1]=true;
	for (i=2;i<=MAXN-5;i++)
	{
		if (!isPri[i])
			pri[++cnt]=i;
		for (j=1;j<=cnt && i*pri[j]<=MAXN-5;j++)
		{
			isPri[i*pri[j]]=true;
			if (!i%pri[j])
				break;
		} 
	}
	for (i=1;i<=MAXN-5;i++)
	{
		if  ((!a[i].c) && check(i))
			a[i].c=true,a[i].x=1;
		if (!a[i].c)
			continue; 
		for (j=1;j<=cnt && i*pri[j]<=MAXN-5;j++)
		{
			if (!a[i*pri[j]].c)
			{
				a[i*pri[j]].c=true;
				a[i*pri[j]].x=a[i].x*pri[j];
			}
			else
				a[i*pri[j]].x=1;
			if (a[i].x%pri[j]==0)
				break;
		}
	}
	for (i=1;i<=MAXN-5;)
		if (!a[i].c)
		{
			k=i;
			while (a[++i].c);
			a[k].nxt=i;
		}
		else
			i++;
}
signed main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	/*
	for (i=1;i<=150;i++)
		if (a[i].c)
			printf("%d\n",i);*/
	read(T);
	for (i=1;i<=T;i++)
		read(q[i]);
	for (i=1;i<=T;i++)
		print(a[q[i]].nxt?a[q[i]].nxt:-1),putchar('\n');
	return 0;
}
