#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mo=998244353;

ll n,m,k,vis[350];
ll ans=0;
ll qmi(ll x,ll y){
	ll res=1;
	while(y){
		if(y%2==1)res=(res*x)%mo;
		x=(x*x)%mo;
		y>>=1;
	}
	return res%mo;
}
ll a[350],val[350],jc[350],njc[350],ttans;

void dfs(int qs,int mxk,int dep){
	if(dep>n)return;
	if(dep==n){
		//cout<<dep<<endl;
//		for(int i=1;i<=mxk;i++){
//			cout<<a[i]<<' ';
//		}cout<<endl;
		ll tans=0;
		ll csans=1;
		tans=jc[n];
		for(int i=1;i<=mxk;i++){
			if(i>m+1&&a[i]!=0)return;
			if(a[i]!=0){
				tans=(tans*njc[a[i]])%mo;
				csans=(csans*qmi(val[i-1],a[i]))%mo;
			}
		}
		//cout<<tans<<' '<<csans<<'-'<<endl;
		ttans=(ttans+(tans*csans)%mo)%mo;
		return;
	}
	for(int i=qs;i>1;i--){
		if(vis[i]==1)continue;
		vis[i]=1;
		for(int j=1;j<=a[i];j++){
			if(i>m+1)j=a[i];
			a[i]-=j;
			a[i-1]+=j*2;
			dfs(i-1,mxk,dep+j);
			a[i]+=j;
			a[i-1]-=j*2;
		}
		vis[i]=0;
	}
}

void dfsqz(int x,int mnn,int mxn,int mxk){
	
	memset(a,0,sizeof(a));
	for(int i=mxk;i>=mxk-x+1;i--){
		a[i]=1;
	}
	//cout<<mxk<<' '<<mnn<<' '<<mxn<<endl;
	do{
		int aans=0;
		for(int i=1;i<=mxk;i++){
			if(a[i]==1)aans=(aans+(1<<(i-1)))%mo;
		}//cout<<aans<<endl,
		
		if(aans>=mnn&&aans<=mxn)
			dfs(mxk,mxk,x);
	}while(next_permutation(a+1,a+mxk+1));
	
}

void sol1(){
	ll mxk=0,mxn=(1<<m)*n,mnn=n;
	ll ts=mxn;
	jc[0]=1;
	while(ts){
		ts/=2;
		mxk++;
	}//mxk--;
	for(int i=1;i<=35;i++){
		jc[i]=(jc[i-1]*i)%mo;
		njc[i]=qmi(jc[i],mo-2);
		//cout<<(jc[i]*njc[i])%mo<<endl;
	}
	for(int i=1;i<=k;i++){
		dfsqz(i,mnn,mxn,mxk);
	}
	cout<<ttans<<endl;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	int ans=0;for(int i=1;i<=17;i++){
//		ans+=Cnm(17,i);
//	}cout<<ans<<endl;
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>val[i];
	}
	if(m<=12)sol1();
	return 0;
}

