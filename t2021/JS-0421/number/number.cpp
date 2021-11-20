#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define m_p make_pair
using namespace std;
const int N=10000020;
int read(){
	int x=0;short negative=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')negative=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c-48);c=getchar();
	}
	return x*negative;
}
bool p[N],b[N];
int ans[N];
int tn[10];
void init(){
	tn[0]=1;
	forn(i,1,7)tn[i]=tn[i-1]*10;
	memset(p,0,sizeof(p));
	forn(i,0,999999){
		forn(j,0,6){
			int bas=tn[j];
			int x,y;
			x=i/bas;y=i%bas;
			p[x*bas*10+7*bas+y]=1;
		}
	}
	forn(i,1,10000005){
		if(p[i]&&!b[i]){
			b[i]=1;
			for(int j=i+i;j<=10000005;j+=i){
				b[j]=1;
			}
		}
	}
	int lst=114514;
	fore(i,10000001,1){
		if(!b[i]){
			ans[i]=lst;lst=i;
		}
		else ans[i]=-1;
	}
}
void solve(){
	int x;
	x=read();
	cout<<ans[x]<<"\n";
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int t;t=read();
	while(t--)solve();	
	return 0;
}
