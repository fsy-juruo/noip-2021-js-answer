#include<bits/stdc++.h>
#define ll long long
#define rep(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
template <typename T> void read(T&x){
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int N=1e4+5;
int n,a[N],v[1005][1005];
ll ans=1e16,num=0;
bool check(){
	for(int i=1;i<=num;i++){
		int f=1;
		for(int j=1;j<=n;j++){
			if(a[j]!=v[i][j]){
				f=0;
				break;
			}
		}
		if(f)return 0;
	}
	return 1;
}
ll cnt(){
	ll s=0,sum=0;
	rep(i,1,n)sum+=a[i];
	rep(i,1,n)s+=a[i]*a[i]*n-2*a[i]*sum;
	s+=sum*sum;
	return s;
}
void dfs(){
	if(check()){
		num++;
		for(int j=1;j<=n;j++){
			v[num][j]=a[j];
		}
		ans=min(ans,cnt());	
		for(int i=2;i<=n-1;i++){
			int k=a[i];
			a[i]=a[i+1]+a[i-1]-a[i];
			dfs();
			a[i]=k;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	rep(i,1,n)read(a[i]);
	dfs();
	printf("%lld\n",ans);
	return 0;
}

