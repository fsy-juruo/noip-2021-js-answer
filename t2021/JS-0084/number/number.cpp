#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	int y=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x=x*y;
}
int t,v[10000010],ans[10000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=999999;i++)
	{
		int p1=i*10+7,p2=i/10*100+i%10+70,p3=i/100*1000+700+i%100;
		int p4=i/1000*10000+7000+i%1000;
		int p5=i/10000*100000+70000+i%10000;
		int p6=i/100000*1000000+700000+i%100000;
		int p7=7000000+i;
		if(!v[p1])for(int j=1;j*p1<=10000000;j++)v[j*p1]=1;
		if(!v[p2])for(int j=1;j*p2<=10000000;j++)v[j*p2]=1;
		if(!v[p3])for(int j=1;j*p3<=10000000;j++)v[j*p3]=1;
		if(!v[p4])for(int j=1;j*p4<=10000000;j++)v[j*p4]=1;
		if(!v[p5])for(int j=1;j*p5<=10000000;j++)v[j*p5]=1;
		if(!v[p6])for(int j=1;j*p6<=10000000;j++)v[j*p6]=1;
		if(p7<8000000)v[p7]=1;
	}
	int now=10000001;
	for(int i=10000000;i>=1;i--)
	{
		if(v[i]){ans[i]=-1;continue;}
		ans[i]=now;now=i;
	}
	read(t);
	for(int i=1,x;i<=t;i++)
	{
		read(x);
		printf("%d\n",ans[x]);	
	}
	return 0;
}
