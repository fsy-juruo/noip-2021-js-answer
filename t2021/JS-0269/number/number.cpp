#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define fi first
#define sc second
using namespace std;

inline int rdi(){
	int cur=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		cur=((cur<<3)+(cur<<1));
		cur+=((int)ch-'0');
		ch=getchar();
	}
	return cur;
}
inline bool chk(int x){
	while(x){
		if(x%10==7){
			return 0;
		}
		x/=10;
	}
	return 1;
}
const int maxn=10000010;
int maxf=10000001;
bool bad[maxn];
int nxt[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m;
	m=rdi();
	if(m<=10000){
		maxf=300000;
	}
	forn(i,maxf){
		bool f=1;
		int k=i;
		while(k){
			if(k%10==7){
				f=0;break;
			}
			k/=10;
		}
		if(!f){
			int x=i;
			while(x<=maxf){
				bad[x]=1;
				x+=i;
			}
		}
	}
	int last=1;
	for(int i=2;i<=maxf;i++){
		if(!bad[i]){
			nxt[last]=i;
			last=i;
		}
	}
	rep(i,m){
		int q;
		q=rdi();
		if(bad[q]){
			putchar('-');
			putchar('1');
			putchar('\n');
			continue;
		}
		int d[10]={0},pos=0,k=nxt[q];
		while(k){
			d[pos]=k%10;
			k/=10;
			pos++;
		}
		for(int i=pos-1;i>=0;i--){
			putchar('0'+d[i]);
		}
		putchar('\n');
	}
	return 0;
}
