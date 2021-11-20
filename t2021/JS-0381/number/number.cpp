#include<bits/stdc++.h>
using namespace std;
int asp(int w,int ww)
{
	for(int i=w;i>=1;i/=10)
	{
		if((w%7==0)||(i%10==7))//7的倍数或含有7
		{
			return 1;
			if(ww%w==0)//含有7的数的倍数或7的倍数 
			{
				return 1;
			}
			break;	
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long  T,x;
	cin>>T;
	long s;
	for(int i=1;i<=T;i++)
	{
		cin>>x;
		s=0;
		if(!asp(x,x))
		{
			s=s+x+1;
			if(!asp(s,s))
			{
				cout<<s;
			}
			else
			{
				while(asp(s,s))
				{
					s++;
					if(!asp(s,s))
					{
						cout<<s;
						break;
					}
				}
			}
		}
		if(asp(x,x))
		{
			cout<<"-1";
			break;
		}	
	}
	return 0;
}

