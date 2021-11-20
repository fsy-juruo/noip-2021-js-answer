#include<bits/stdc++.h>
#define mp make_pair
#define lb lower_bound
#define up upper_bound
#define re register int
using namespace std;
typedef long long ll;
typedef long double ld;

template<typename T> inline void rd(T &x){
	x=0;bool fl=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl^=1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
	if(fl) x=-x;
}

template<typename T> inline void wr(T x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else wr(x/10),putchar(x%10+'0');
}

// ---------- IO ---------- //

const int N=1e7+10;
int T,n,sum,qaq[N],tot,ha,ans[N];
bool tag[N];

inline bool check(int x){
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}

// ----------  ---------- //

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(re i=1;i<=N;++i){
		if(check(i)){
			tag[i]=1;
			for(re j=i+i;j<=N;j+=i) tag[j]=1;
		}
	}
	for(re i=N-2;i>0;--i)
		if(!tag[i+1]) ans[i]=i+1;
		else ans[i]=ans[i+1];
	rd(T);
	while(T--){
		rd(n);
		if(tag[n]){puts("-1");continue;}
		wr(ans[n]);puts("");
	}
	return 0;
}

// ---------- Main ---------- //

