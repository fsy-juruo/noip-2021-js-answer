#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=998244353;

int n,m,k,v[110];

ll l,r,a[30],ans=1;

int num(ll x){
	int ss=0;
	while(x){
		if(x&1==1) ss++;
		x>>=1;
	}
	return ss;
}

ll chen(ll xx,ll xxx){
	ll re=1;
	for(int i=1;i<=xxx;i++){
		re*=xx;
		re%=mod;
	}
	return re;
}

ll fang(int z,int zz){ //z qu zz
	ll ree=1;
	for(int i=z;i>=z-zz+1;i--) ree*=i;
	for(int i=1;i<=zz;i++) ree/=i;
	return ree;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	l=n,r=n*(1<<m);
	for(int i=0;i<=30;i++) a[i]=1<<i;
	for(ll i=l;i<=r;i++){
		if(num(i)<=k){
			ll tmp=i,tot=1,f=1;//rest和 权和 方法 
			int res=n;//剩余 
			for(int j=30;j>=0;j--){
				if(a[j]>tmp) continue;
				if(tmp/a[j]==res){
					tot*=chen(v[j],res);
					tot%=mod;
					break;
				} 
				int cnt=0,ress=res;
				while(a[j-1]*res<tmp){
					cnt++;
					res--;
					tmp-=a[j];
					tot*=v[j];
					tot%=mod;
				}
				if(cnt!=0){
					f*=fang(ress,cnt);
					f%=mod;
				}
			}
			ans+=tot*f;
			ans%=mod;
		}
	}
	cout<<ans-1;
	return 0;
}
