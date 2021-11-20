#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG printf("Passing Line %d in Function [%s].\n",__LINE__,__FUNCTION__);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int > pii;

const int maxn=200007;
const int INF=0x3f3f3f3f;
const ll MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

inline int mod1(int x){return x>=MOD?x-MOD:x;}
inline int mod2(int x){return x<0?x+MOD:x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}
int n;
int a[maxn],b[maxn],c[maxn];
ll ans=0;
//int id[maxn];
int d[maxn];
int e[maxn];
void solve1(){
//	for(int i=1;i<=n-1;i++){
//		id[i]=i;
//	}
	a[1]=0;
	ans=LINF;
	int N=n-1;
	for(int i=1;i<(1<<N);i++){
		int cnt1=0,cnt2=0;
		for(int j=1;j<=N;j++){
			if((1<<(j-1))&i)c[++cnt1]=b[j];
			else d[++cnt2]=b[j];
//			cout<<c[cnt1]<<' '<<d[cnt2]<<endl;
		}
		sort(c+1,c+cnt1+1);
		reverse(c+1,c+cnt1+1);
		sort(d+1,d+cnt2+1);
		reverse(d+1,d+cnt2+1);
		for(int i=1;i<=cnt1;i++)e[i]=c[i];
		for(int i=1;i<=cnt2;i++)e[n-i]=d[i];
		ll rt=0,sum=0;
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=2;i<=n;i++)a[i]=a[i-1]+e[i-1];
//		cout<<endl;
		for(int i=1;i<=n;i++){
			rt+=1ll*n*a[i]*a[i];
			sum+=1ll*a[i];
		}
		ans=min(ans,rt-sum*sum);
	}
	printf("%lld",ans);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(i>1)b[i-1]=a[i]-a[i-1];
	}
	if(n<=20){
		solve1();
		return 0;
	}
//	for(int i)

	return 0;
}

