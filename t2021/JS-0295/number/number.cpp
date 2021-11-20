#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool tb[10000101];
int as[10000101];

bool chk(int x)
{
	while(x!=0)
	{
		if(x%10==7)
			return false;
		x/=10;
	}
	return true;
}

void pre(int n)
{
	memset(tb,true,sizeof(tb));
	for(int i=1;i<=n;i++)
	{
		if(!chk(i))
		{
			tb[i]=false;
			for(int j=2;i*j<=n;j++)
				tb[i*j]=false;
		}
	}
	int bf=n;
	for(int i=n;i>=1;i--)
		if(!tb[i])
			as[i]=-1;
		else
		{
			as[i]=bf;
			bf=i;
		}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	pre(10000100);
	ifstream ins("number.in");
	ofstream ous("number.out");
	int t=1;
	ins>>t;
	for(int i=0;i<t;i++)
	{
		int x;
		ins>>x;
		ous<<as[x]<<'\n';
	}
	/*ios::sync_with_stdio(false);
	for(int i=1;i<=100;i++)
		cout<<tb[i];*/
	cout.flush();
	return 0;
}
