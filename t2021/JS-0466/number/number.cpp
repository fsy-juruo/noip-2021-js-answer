#include<bits/stdc++.h>
using namespace std;
template<typename T>void Read(T &npt)
{
	npt=0;
	int f=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=1;ch=getchar();}
	if(f)while(isdigit(ch)){npt=npt*10+(48-ch);ch=getchar();}
	else while(isdigit(ch)){npt=npt*10+(ch-48);ch=getchar();}
}
inline void print(int ot)
{
	if(ot<0){putchar('-');print(~(ot-1));}
	else if(ot>9){print(ot/10);putchar(ot%10+48);}
	else putchar(ot+48);
}
int b[10000005],c[200005],d[10000005];
int a[7];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,ma=0,mi=100000000;
	Read(n);
	for(int i=1;i<=n;i++)
	{
		Read(c[i]);
		ma=max(ma,c[i]);
		mi=min(mi,c[i]);
	}
	for(int w=0;w<=6;++w)
	{
		for(a[1]=0;a[1]<=9;++a[1])
		{
			for(a[2]=0;a[2]<=9;++a[2])
			{
				for(a[3]=0;a[3]<=9;++a[3])
				{
					for(a[4]=0;a[4]<=9;++a[4])
					{
						for(a[5]=0;a[5]<=9;++a[5])
						{
							for(a[6]=0;a[6]<=9;++a[6])
							{
								int x=0,j=1;
								for(int i=0;i<=6;++i)
								{
									if(i==w)x=x*10+7;
									else x=x*10+a[j],++j;
								}
								for(int i=ceil(mi*1.0/x);i<=floor(ma*1.0/x);++i)b[i*x]=1;
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[c[i]])puts("-1");
		else
		{
			if(d[c[i]])
			{
				print(d[c[i]]);
				puts("");
				continue;
			}
			int x=c[i]+1;
			while(b[x])x++;
			d[c[i]]=x;
			print(x);
			puts("");
		}
	}
	return 0;
}
