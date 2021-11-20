#include<bits/stdc++.h>
using namespace std;
bool a[10000],o[10000];
vector<int> v;
bool cha(int n)
{
	if(n%7==0)
	return false;
	while(n)
	{
		if(n%10==7)
		return false;
		n/=10;
	}
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b,c,t;
	bool l;
	for(b=7;b<=10000;b++)
	{
		if(a[b])
		{
			v.push_back(b);
			continue;
		}
		if(b%7==0)
		{
			a[b]=true;
			v.push_back(b);
			continue;
		}
		c=b;
		while(c)
		{
			if(c%10==7)
			{
				for(c=b;c*c<=1e+7;c+=b)
				a[c]=true;
				v.push_back(b);
				break;
			}
			c/=10;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&b);
		l=false;
		for(c=0;c<v.size()&&v[c]<=b;c++)
		{
			if(b%v[c]==0||!cha(b))
			{
				l=true;
				break;
			}
		}
		if(l)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			memset(o,false,sizeof(o));
			for(c=0;c<v.size();c++)
			o[v[c]-(b%v[c])]=true;
			for(c=1;c<=3169;c++)
			{
				if(!o[c]&&cha((b+c)))
				{
					printf("%d\n",(b+c));
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
