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

const int maxn=10000017;
const int INF=0x3f3f3f3f;
const ll MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

inline int mod1(int x){return x>=MOD?x-MOD:x;}
inline int mod2(int x){return x<0?x+MOD:x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}
int N=10000005;
int T;
bool vis[maxn];
int prime[maxn],tot;
int ans[maxn];
bool check(int x){
	while(x){
		if(x%10==7)return false;
		x/=10;
	}
	return true;
}
void init(){
	for(int i=7;i<=N;i++){
		if(!check(i)){
			vis[i]=true;
			for(int j=1;i*j<=N;j++){
				vis[i*j]=1;
//				if(i*j==10000001)cout<<i<<j<<endl;
			}
		}
	}
	int lst=0;
	for(int i=N;i>=1;i--){
//		if(i>=9999990)cout<<i<<' '<<vis[i]<<endl;
		if(!vis[i])ans[i]=lst,lst=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
//	int cl=clock();
	init();
//	cerr<<clock()-cl<<endl;
	while(T--){
		int x;
		scanf("%d",&x);
		if(vis[x])printf("-1\n");
		else printf("%d\n",ans[x]);
	}
	return 0;
}

