// DYW NOIP RP++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int T,x;
bool check[200010];
int nnext[200010];
void to(int x)
{
	int cnt=2*x;
	while( cnt <= 10000 )
	{
		check[cnt]=1;
		cnt+=x;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000;i++)
	{
		int temp=i;
		if( check[i] == 1 )
		  continue;
		while( temp )
		{
			if( temp % 10 == 7 )
			{
				check[i]=1;
				to(i);
				break;
			 } 
			temp/=10; 
		}
	}
	int last=0;
	for(int i=1;i<=10000;i++)
	{
		if( check[i] == 0 )
		{
			nnext[last]=i;
			last=i;
		}
	}
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>x;
		if( check[x] == 1 )
		  cout<<-1<<endl;
		else
		  cout<<nnext[x]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4
6
33
69
300

5
90
99
106
114
169
*/
