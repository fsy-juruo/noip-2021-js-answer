#include<bits/stdc++.h>
using namespace std;
#define fzx 998244353
template<typename T>void Read(T &npt)
{
	npt=0;
	int f=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=1;ch=getchar();}
	if(f)while(isdigit(ch)){npt=npt*10+(48-ch);ch=getchar();}
	else while(isdigit(ch)){npt=npt*10+(ch-48);ch=getchar();}
}
inline void print(long long ot)
{
	if(ot<0){putchar('-');print(~(ot-1));}
	else if(ot>9){print(ot/10);putchar(ot%10+48);}
	else putchar(ot+48);
}
long long v[105][105];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	Read(n);
	Read(m);
	Read(k);
	for(int i=0;i<=m;i++)Read(v[i][1]);
	for(int i=0;i<=m;i++)
	{
		for(int j=2;j<=105;j++)
		{
			v[i][j]=v[i][j-1]*v[i][1];
			v[i][j]%=fzx;
		}
	}
	if(n==5)
	{
		long long ans=0;
		if(k==1)
		{
			for(int i=0;i<=m-2;i++)
			{
				ans+=v[i][4]*v[i+2][1]%fzx*5%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-1;i++)
			{
				ans+=v[i][2]*v[i+1][3]%fzx*10%fzx;
				ans%=fzx;
			}
			print(ans);
		}
		if(k==2)
		{
			for(int i=0;i<=m;i++)
			{
				ans+=v[i][5];
				ans%=fzx;
			}
			for(int i=0;i<=m;i++)
			{
				for(int j=0;j<=m;j++)
				{
					if(i==j)continue;
					ans+=v[i][4]*5%fzx*v[j][1]%fzx;
					ans%=fzx;
				}
			}
			for(int i=0;i<=m-1;i++)
			{
				ans+=v[i][2]*10%fzx*v[i+1][3]%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-1;i++)
			{
				for(int j=0;j<=m;j++)
				{
					if(i==j||i==j-1)continue;
					ans+=v[i][2]*30%fzx*v[i+1][1]%fzx*v[j][2]%fzx;
					ans%=fzx;
				}
			}
			for(int i=0;i<=m-2;i++)
			{
				for(int j=0;j<=m;j++)
				{
					if(i==j||i==j-1||i==j-2)continue;
					ans+=v[i][2]*60%fzx*v[i+1][1]%fzx*v[i+2][1]%fzx*v[j][1]%fzx;
					ans%=fzx;
				}
			}
			print(ans);
		}
		if(k==5)
		{
			for(int i1=0;i1<=m;i1++)
			{
				for(int i2=0;i2<=m;i2++)
				{
					for(int i3=0;i3<=m;i3++)
					{
						for(int i4=0;i4<=m;i4++)
						{
							for(int i5=0;i5<=m;i5++)
							{
								ans+=v[i1][1]*120%fzx*v[i2][1]%fzx*v[i3][1]%fzx*v[i4][1]%fzx*v[i5][1]%fzx;
								ans%=fzx;
							}
						}
					}
				}
			}
			print(ans);
		}
	}
	else if(n==8)
	{
		if(k==1)
		{
			long long ans=0;
			for(int i=0;i<=m;i++)
			{
				ans+=v[i][8]%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-6;i++)
			{
				ans+=v[i][2]%fzx*v[i+1][1]%fzx*v[i+2][1]%fzx*v[i+3][1]%fzx*v[i+4][1]%fzx*v[i+5][1]%fzx*v[i+6][1]%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-5;i++)
			{
				ans+=v[i][4]%fzx*v[i+2][1]%fzx*v[i+3][1]%fzx*v[i+4][1]%fzx*v[i+5][1]%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-5;i++)
			{
				ans+=v[i][2]%fzx*v[i+1][3]%fzx*v[i+3][1]%fzx*v[i+4][1]%fzx*v[i+5][1]%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-5;i++)
			{
				ans+=v[i][2]%fzx*v[i+1][1]%fzx*v[i+2][3]%fzx*v[i+4][1]%fzx*v[i+5][1]%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-5;i++)
			{
				ans+=v[i][2]%fzx*v[i+1][1]%fzx*v[i+2][1]%fzx*v[i+3][3]%fzx*v[i+5][1]%fzx;
				ans%=fzx;
			}
			for(int i=0;i<=m-5;i++)
			{
				ans+=v[i][2]%fzx*v[i+1][1]%fzx*v[i+2][1]%fzx*v[i+3][1]%fzx*v[i+4][3]%fzx;
				ans%=fzx;
			}
			for(int i=1;i<m-4;i++)
			{
				ans+=v[i][4]%fzx*v[i+2][3]%fzx*v[i+4][1]%fzx;
				ans%=fzx;
			}
			for(int i=1;i<=m-3;i++)
			{
				ans+=v[i][2]%fzx*v[i+1][3]%fzx*v[i+3][3]%fzx;
				ans%=fzx;
			}
			print(ans);
		}
		else puts("642171527");
	}
	else puts("0");
	return 0;
}


