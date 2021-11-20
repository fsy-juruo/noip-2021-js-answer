#include<bits/stdc++.h>
using namespace std;

int n,vis[25];
double sum,ans=100000000.0; 
void dfs(int* a,double sum,int step){
	if(step>n)return ;
	double s=0.0;
	for(int i=1;i<=n;++i)s+=(double(a[i])-sum/double(n))*(double(a[i])-sum/double(n));
	if(s<ans)ans=s;
	for(int i=2;i<n;++i){
		if(vis[i])continue;
		int aa=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		sum+=double(a[i-1]+a[i+1]-aa*2);
		dfs(a,sum,step+1);
		a[i]=aa;
		sum-=double(a[i-1]+a[i+1]-a[i]*2);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int a[25];
	scanf("%d",&n);
	if(n>4){
		printf("555~\n");	
		return 0;
	}
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i];
	dfs(a,sum,1);
	printf("%.0lf",ans*n);
	return 0;
}
/*
a_i E [0,m]
4
1 2 4 6


*/ 
