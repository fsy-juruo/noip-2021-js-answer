#include<bits/stdc++.h>
using namespace std;
const int N=100010,n=10500;
int T;
bool b[N];
void prework()
{
	b[7]=true;
	for(int i=1;i<=n;i++)
	{
		int y=i;
		while(y)
		{
			if(y%10==7) {b[i]=true;break;}
			y/=10;
		}
		for(int j=1;j<=n;j++)
		  if(b[j]){
		  	if(i%j==0) {
			  	b[i]=true;
			  	break;
			  }
		  }
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	prework();
	while(T--)
	{
		int x;
		scanf("%d",&x);
		if(b[x]) puts("-1");
		else {
			for(int i=x+1;i<=n;i++)
			  if(!b[i]) {
			  	printf("%d\n",i);
			  	break;
			  }
		}
	}
	return 0;
}
