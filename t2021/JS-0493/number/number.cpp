#include<bits/stdc++.h>
using namespace std;
inline int f_read(void)
{
	int x=0,y=1;
	char c=getchar();
	while(c!='-'&&(c>'9'||c<'0'))
		c=getchar();
	if(c=='-')
		y=-1,c=getchar();
	while(c>='0'&&c<='9')
		x=x*10+c-'0',c=getchar();
	return x*y;
}
inline void f_write(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	string xx="";
	while(x)
		xx=xx+char(x%10+'0'),x/=10;
	for(int i=xx.size()-1;i>=0;i--)
		putchar(xx[i]); 
	return ;
}
int T,n,nxt[10000005],lst,num,pw10[10];
bool ntok[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=f_read();
	pw10[0]=1;
	pw10[1]=10;
	pw10[2]=100;
	pw10[3]=1000;
	pw10[4]=10000;
	pw10[5]=100000;
	pw10[6]=1000000;
	pw10[7]=10000000;
	for(int i=0;i<=999999;i++)
		for(int d=0;d<7;d++)
		{
			num=i%pw10[d]+i/pw10[d]*pw10[d+1]+7*pw10[d];
			for(int j=num;j<=10000000;j+=num)
				ntok[j]=true;
		}
	lst=1;
	for(int i=2;i<=10000000;i++)
		if(!ntok[i])
			nxt[lst]=i,lst=i;
	nxt[9999998]=10000001;
	while(T--)
	{
		n=f_read();
		if(ntok[n])
			putchar('-'),putchar('1');
		else
			f_write(nxt[n]);
		putchar('\n');
	}
	return 0;
}
