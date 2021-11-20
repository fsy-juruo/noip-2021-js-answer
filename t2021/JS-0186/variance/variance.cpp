#include<bits/stdc++.h>
using namespace std;
int n,a[10005],end_ans=2147483647;
void calc(){
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	ans+=(n*a[i]-sum)*(n*a[i]-sum);
	end_ans=min(end_ans,ans);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	calc();
	srand(time(0));
	for(int i=1;i<=100000;i++){
		int x=rand()%n+2;
		if(x<n&&x>1)a[x]=a[x-1]+a[x+1]-a[x];
		calc();
	}
	printf("%d",end_ans/n);
	return 0;
}
