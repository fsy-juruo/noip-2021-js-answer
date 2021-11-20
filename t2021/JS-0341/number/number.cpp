#include <bits/stdc++.h>
using namespace std;
int dj[55555555],t,x[200010],xmx;
void fb(int xxx)
{
	int ii=1;
	while (1)
	{
		dj[ii*xxx]=1;
		if (ii*xxx>xmx)
		{
			dj[(ii+1)*xxx]=1;
			break;
		}	
		ii++;
	}
}
void dd(int xx)
{
	for (int i=1;i<=xx/10*2;i++)
	{
		int j=1,p;
		while (1)
		{
			p=i/j*j*10+7*j+i%j;
			if (p<30000000)
				fb(p);
			if (j>i)
				break;
			j=j*10;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>t;
	for (int i=1;i<=t;i++)
	{
		cin >>x[i];
		xmx=max(xmx,x[i]);
	}
	dd(xmx);
	for (int i=1;i<=t;i++)
	{
		if (dj[x[i]]==1 || x[i]%7==0) 
		{
			cout <<-1<<endl;
			continue;
		}
		else
		{
			for (int j=x[i]+1;j;j++)
				if (dj[j]==0 && j%7!=0) 
				{
					cout <<j<<endl;
					break;					
				}
		}	
	} 
	return 0;
}

