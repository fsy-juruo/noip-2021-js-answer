#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,a[N],ans=0x3f3f3f3f;
inline int read(){
	char c=getchar();
	int res=0;
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		res=10*res+c-'0';
		c=getchar();
	}
	return res;
}
void output(){
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
}
void cupdate(){
	int sum=0,res=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	for(int i=1;i<=n;i++)
		res+=a[i]*a[i];
	res*=n;
	//printf("%d %d\n",res,sum);
	res-=sum*sum;
	
	ans=min(ans,res);
}
void dfs(int x,int curdep,int maxdep){
	a[x]=a[x-1]+a[x+1]-a[x];
	cupdate();
	if(curdep<maxdep){
		if(x+1<n){
			dfs(x+1,curdep+1,maxdep);
			a[x+1]=a[x+2]+a[x]-a[x+1];
		}
		if(x-1>1){
			dfs(x-1,curdep+1,maxdep);
			a[x-1]=a[x-2]+a[x]-a[x-1];
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout); 
	n=read();
	//srand(time(0));
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=2;i<=n-1;i++){
		dfs(i,1,23);
		a[i]=a[i+1]+a[i-1]-a[i];
	}
	printf("%d\n",ans);
	return 0;
}
