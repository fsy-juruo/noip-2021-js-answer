#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define lson k<<1
#define rson k<<1|1
//#define getchar nc
#define N 10000005

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll INF64 = 1e18;
const double eps = 1e-8;

const int maxn = 1e7+10;
const int maxm = 1e7+10;

inline char nc(){
	static char buf[100005],*p1 = buf,*p2 = buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
}

inline int read(){
	char ch = getchar(); int sum = 0; int f = 0;
	while(!isdigit(ch)) f |= (ch=='-'), ch = getchar();
	while(isdigit(ch)) sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
	return f ? -sum : sum; 
}

inline void write(int x){
	if(!x) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	static int st[20]; int top = 0;
	while(x) st[top++] = x % 10, x /= 10;
	while(top) putchar(st[--top] + 48);
	putchar('\n');
}

bool v[maxm];
int p[maxn];
int cnt;
int T;
int ans[maxn];	

inline bool is_seven(int x){
	while(x){
		if(x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	double st = clock();
	for(int i=1;i<=N;i++){
		if(is_seven(i) && (!v[i])){
			p[++cnt] = i; v[i] = 1;
		}
	}
	
	for(int j=1;j<=cnt;j++){
		for(int i=2;;i++){
			if(i * p[j] > N) break;
			v[i * p[j]] = 1;
//			if(v[i]) break;
		}
	}
	
//	double ed = clock();
//	printf("Time: %.4lf\n",ed - st);
//	for(int i=1;i<=100;i++){
//		printf("i: %d v: %d\n",i,v[i]);
//	}
	int last = 0;
	for(int i=1;i<=N;i++)
		if(!v[i]){
			ans[last] = i;
			last = i;
		}
//	cout << last << endl;
	T = read();
	while(T--){
		int x; x = read();
		if(v[x]){
			write(-1);
		}else{
			write(ans[x]);
		}
	}
	return 0;
} 
