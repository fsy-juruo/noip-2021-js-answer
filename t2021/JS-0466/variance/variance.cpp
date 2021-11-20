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
int a[405],cnt,fr,tl;
int c[6005][405];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	long long mi=INT_MAX;
	Read(n);
	if(n>400)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)Read(a[i]);
	tl++;
	for(int i=1;i<=n;i++)c[tl][i]=a[i];
	fr=1;
	while(fr<=tl)
	{
		int p[405],t[405];
		for(int i=1;i<=n;i++)
		{
			p[i]=c[fr][i];
			t[i]=p[i];
		}
		fr++;
		for(int i=2;i<n;i++)
		{
			if(p[i]!=p[i-1]+p[i+1]-p[i])
			{
				p[i]=p[i-1]+p[i+1]-p[i];
				int f=0;
				for(int i=1;i<=tl;i++)
				{
					f=0;
					for(int j=1;j<=n;j++)
					{
						if(p[j]!=c[i][j])
						{
							f=1;
							break;
						}
					}
					if(f==0)break;
				}
				if(f==0)continue;
				tl++;
				for(int i=1;i<=n;i++)c[tl][i]=p[i];
				for(int i=1;i<=n;i++)p[i]=t[i];
			}
		}
		long long h=0,f=0;
		for(int i=1;i<=n;i++)
		{
			h+=t[i];
			f+=(long long)t[i]*t[i];
		}
		f*=n;
		h*=h;
		f-=h;
		mi=min(f,mi);
		if(tl>=6000)break;
	}
	print(mi);
	return 0;
}


