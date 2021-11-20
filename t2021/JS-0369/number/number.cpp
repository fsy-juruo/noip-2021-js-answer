#include<bits/stdc++.h>
using namespace std;
const int SIZE=1e7+10;

int t,f[SIZE];

inline bool judge(int n)
{
	int ts=n,bit;
	while(ts>0)
	{
		bit=ts%10;
		if(bit==7) return true;
		ts/=10;
	}
	return false;
}

inline void work()
{
	memset(f,0,sizeof(f));
	for(int i=7;i<=SIZE;i++)
	{
		if(judge(i))
		{
			for(int j=1;j<=SIZE/i;j++)
			{
				f[j*i]=true;
			}
		}
	}
}

inline bool check(int x)
{
	bool flag=true;
	for(int i=1;i<=sqrt(x);i++)
	{
		if(x%i==0&&(f[i]||f[x]/i))
		{
			flag=false;
			break;
		}
	}
	return flag;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	work();
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		if(!check(x)) cout<<-1<<endl;
		else
		{
			int y=x;
			while(1)
			{
				y++;
				if(check(y))
				{
					cout<<y<<endl;
					break;
				}
			}
		}
	}
}

