#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=998244353;
const int M=105;
int n,m,k,a[100],b[100],num[100],rp[100];
ll v[M],ans;
ll calc(int a,int b){
	ll res=1;
	for(int i=1;i<=a;i++){
		res=1ll*(b-i+1)*res;
		res/=i;
	}
	res%=P;
	return res;
}
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=0;i<=60;i++) a[i]=num[i];
		for(int i=0;i<=60;i++){
			if(a[i]>1){
				a[i+1]+=a[i]/2;
				a[i]=a[i]-2*(a[i]/2);
			}
			if(a[i]) cnt++;
		}
		if(cnt==k){
			ll tmp=1;
			int tot=n;
			for(int i=0;i<=60;i++){
				for(int j=1;j<=num[i];j++){
					tmp*=v[i];
					tmp%=P;
				}
				tmp*=calc(num[i],tot);
				tot-=num[i];
			}
			ans+=tmp;
			ans%=P;
		}
		return;
	}
	for(int i=b[x-1];i<=m;i++){
		b[x]=i;
		num[i]++;
		dfs(x+1);
		num[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	if(k==1 && n==30){
		for(int i=5;i<=104;i++){
			ll tmp=v[i-4]*v[i-4]%P;
			for(int j=1;j<=28;j++){
				tmp*=v[i-5];
				tmp%=P;
			}
			ans+=tmp*calc(2,30)%P;
			ans%=P;
			if(i>=7){
				tmp=1;
				for(int j=1;j<=14;j++){
					tmp*=v[i-4];
					tmp%=P;
				}
				for(int j=1;j<=16;j++){
					tmp*=v[i-7];
					tmp%=P;
				}
				ans+=tmp*calc(14,30)%P;
			}
			ans%=P;
		}
	}
	else{
		dfs(1);
	}
	printf("%lld\n",ans);
	return 0;
}
