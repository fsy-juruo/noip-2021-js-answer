#include<bits/stdc++.h>
using namespace std;
double n,ans;
int q;
bool b[10050];
float a[10050],c[10050];
double change(int x){
	int u=a[x-1]+a[x+1]-a[x];
	return u;
}
double qfc(){
	double sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum1+=a[i]/n;
	}
	for(int i=1;i<=n;i++){
		sum2+=pow((a[i]-sum1),2);
	}
	return sum2*n;
}
void dfs(int x){
	if(b[x]==1)
		return; 
	else{
		b[x]=1;
		if(a[x]==change(x)){
		if(x+1<n)dfs(x+1);
		if(x-1>1)dfs(x-1);
		}
		else{
			a[x]=change(x);
			ans=min(ans,qfc());
		if(x+1<n)dfs(x+1);
		if(x-1>1)dfs(x-1);
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&q);
	n=double(q);
	for(int i=1;i<=n;i++){
		scanf("%f",&a[i]);
		c[i]=a[i];
	}
	ans=qfc();
	for(int i=2;i<=n-1;i++){
		dfs(i);
		for(int y=1;y<=n;y++)
		b[y]=0;
		for(int y=1;y<=n;y++)
		a[y]=c[y];
	}
	int ans1=int(ans);
	printf("%d",ans1);
	return 0;
}
