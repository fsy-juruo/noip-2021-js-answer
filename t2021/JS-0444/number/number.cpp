#include<bits/stdc++.h>
using namespace std;
bool b[10000005];
int main()
{
	for(int i=1;i<=9999997;i++){
		int t=i;
		while(t){
			if(t%10==7){
				if(b[i]) break;
				b[i]=1;
				for(int j=1;j*i<=10000000;j++)
					b[j*i]=1;
				break;
			}
			t/=10;
		}
	}
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a;
	while(n--)
	{
		scanf("%d",&a);
		if(b[a]) printf("-1\n");
		else{
			a++;
			while(b[a]) a++;
			printf("%d\n",a);
		}
	}
	return 0;
}
