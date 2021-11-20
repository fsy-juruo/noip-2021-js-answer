#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<cstdio>
#include<queue>
using namespace std;

class Mp
{
	public:
		bool mp[10000005];
		int mp_inp[10000005];
		Mp()
		{
			mp[0]=1;
			int nmm[9];
			for(register int a=0; a<=0; a++)
			{
				nmm[1]=0;
				for(register int b=0; b<=9; b++)
				{
					if(b==7)continue;
					nmm[2]=1000000*b;
					for(register int c=0; c<=9; c++)
					{
						if(c==7)continue;
						nmm[3]=100000*c;
						for(register int d=0; d<=9; d++)
						{
							if(d==7)continue;
							nmm[4]=10000*d;
							for(register int e=0; e<=9; e++)
							{
								if(e==7)continue;
								nmm[5]=1000*e;
								for(register int f=0; f<=9; f++)
								{
									if(f==7)continue;
									nmm[6]=100*f;
									for(register int g=0; g<=9; g++)
									{
										if(g==7)continue;
										nmm[7]=10*g;
										for(register int h=0; h<=9; h++)
										{
											if(h==7)continue;
											nmm[8]=h;
											int c_num=nmm[1]+nmm[2]+nmm[3]+nmm[4]+nmm[5]+nmm[6]+nmm[7]+nmm[8];
											mp[c_num]=1;
										}
									}
								}
							}
						}
					}
				}
			}

			for(int i=1; i<=10000000; i++)
			{
				if(mp[i]==0)
				{
					for(int j=i*2; j<=10000000; j+=i)
					{
						mp[j]=0;
					}
				}

			}

			int last_valid=10000001;
			for(int i=10000000; i>=1; i--)
			{
				if(mp[i]==0)
				{
					mp_inp[i]=-1;
				}
				else
				{
					mp_inp[i]=last_valid;
					last_valid=i;
				}

			}

		}
};
const Mp mp;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	register int n;
	scanf("%d",&n);
	for(register int i=1; i<=n; i++)
	{
		register int a;
		scanf("%d",&a);
		printf("%d\n",mp.mp_inp[a]);
	}
	return 0;

}
