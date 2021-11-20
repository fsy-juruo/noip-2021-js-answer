#include<bits/stdc++.h>
#define MAXN 10000905
using namespace std;
bool a[MAXN];
bool f(int x){
	while(x){
		if(x%10==7) return 0;
		x/=10;
	}
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	
	for(int i=1;i<=MAXN;++i){
		if(!f(i))
		for(int j=i;j<=MAXN;j+=i)
		a[j]=1;
	}
	
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(a[n]) printf("-1\n");
		else for(int i=n+1;;++i)
		if(!a[i]){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

