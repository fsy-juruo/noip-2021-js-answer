#include<bits/stdc++.h>
using namespace std;
bool num[20000010];
int n,y;
inline void read(int &x)
{
	x=0;
	int y=1;
	char a=getchar();
	while(a>'9'||a<'0')
	{
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a<='9'&&a>='0')
	{
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=y;
}
inline bool check(int x)
{
	while(x%10!=7&&x!=0)x/=10;
	if(x==0)return true;
	if(x>0)return false;
}
int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(register int i=7;i<=10000001;++i)
	if(!num[i]&&!check(i))
	for(register int j=1;j*i<=10000001;++j)num[j*i]=true;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
	{
		read(y);
		if(num[y])printf("-1\n");
		else
		{
			int z=y+1;
			while(num[z])++z;
			printf("%d\n",z);
		 } 
		
	}
	return 0;
}

