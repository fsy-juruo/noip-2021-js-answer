#include <cstdio>
#include <bitset>
#define MAXN 105
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,m,k;
ll a[MAXN];
int b[MAXN];
bitset<MAXN> bs;
ll result=0;
int se[MAXN],cnt=0;
ll power(ll x,ll nu){
	ll base=x,mu=nu,res=1;
	while(mu>0){
		if(mu&1){
			res=(res*base)%MOD;
		}
		base=(base*base)%MOD;
		mu/=2;
	}
	return res;
}
void solve1(){
	ll ans=1;
	for(int i=0;i<=n;i++){
		if(se[i]!=0){
			//printf("%d",i);
			ans=(ans*a[i])%MOD;
		}
	}
	//printf("\n");	
	result=(result+ans)%MOD;
}
ll so[MAXN];
int solve(ll s){
	//printf("solve:%lld\n",s);
	so[0]=s;
	for(int i=0;i<m;i++){
		if(s/2+(s%2)>=n){
			so[i+1]=so[i];
			so[i]=s%2;
			s=s/2+(s%2);
		}else {
			int t=s-n;
			//printf("t:%d\n",t);
			so[i]-=2*t;
			so[i+1]+=t;
			s-=t;
			break;
		}
		
	}
	/*
	for(int i=0;i<=m;i++){
		if(so[i]){
			printf("%d:%lld\n",i,so[i]);
		}
	}
	*/
	if(s==n)return 1;
	return 0;
}

void dfs(int x,int k,int y){
	if(k<0)return;
	if(x>n)return;
	//printf("(%d,%d)\n",x,k);
	if(y){
		ll s=0;
		for(int i=0;i<cnt;i++){
			s=(s+power(2,b[i]))%MOD;
		}
		if(s>=n&&s<=n*power(2,m)&&solve(s)){
			//printf("valid:%lld\n",s);
			ll su=0,maxu=-1,maxui=-1;
			for(int i=0;i<=m;i++){
				su+=so[i];
				if(so[i]>maxu){
					maxu=so[i];
					maxui=i;
				}
			}
			ll as=1,cnt=1;
			for(int i=maxu+1;i<=su;i++){
				as=(as*i)%MOD;
			}
			for(int i=0;i<=m;i++){
				if(so[i]){
					if(i!=maxui){
						for(int j=2;j<=so[i];j++){
							as=(as*power(j,MOD-2))%MOD;
						}
					}
					cnt=(cnt*power(a[i],so[i]))%MOD;
					//printf("i: %dai: %lldcnt:%lld\n",i,a[i],cnt);
				}
			}
			//printf("cnt:%lld\n",cnt);
			as=(as*cnt)%MOD;
			result=(result+as)%MOD;
		}
	}
	se[x]=1;
	b[cnt]=x;
	cnt++;
	dfs(x+1,k-1,1);
	cnt--;
	se[x]=0;
	dfs(x+1,k,0);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,k,0);
	printf("%lld\n",result);
	return 0;
}
