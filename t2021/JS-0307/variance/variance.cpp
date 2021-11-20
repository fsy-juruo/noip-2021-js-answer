#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define lson k<<1
#define rson k<<1|1
//#define getchar nc

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll INF64 = 1e18;
const double eps = 1e-8;

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

const int maxn = 1e5+5;

int n;
int a[maxn];
int b[maxn];
int mid;
ll res;

multiset<pii, greater<pii> >s;

inline void calc(){
	ll sum = 0; res = 0;
	for(int i=1;i<=n;i++) sum += a[i];
	for(int i=1;i<=n;i++) res += 1ll * a[i] * a[i]; 
	res = 1ll * n * res;
	res -= 1ll * sum * sum;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	mid = n/2;
	for(int i=2;i<=mid;i++) 
		if(a[i-1] + a[i+1] - 2 * a[i] > 0)
			s.insert(MP(a[i-1] + a[i+1] - 2 * a[i], i));
	multiset<pii, greater<pii> >::iterator it;
//	puts("FUCK");
	while(!s.empty()){
		int idx = (s.begin()->S);
		cout<<idx<<endl;
		if(idx > 2){
			it = s.find(MP(a[idx-2] + a[idx] - 2 * a[idx], idx-1));
			assert(it == s.end());
			if((*it) == MP(a[idx-2] + a[idx] - 2 * a[idx], idx-1)) s.erase(it); 
		}
		if(idx < n-1 && idx + 1 <= mid){
			it = s.find(MP(a[idx] + a[idx+2] - 2 * a[idx], idx+1));
			assert(it == s.end());
			if((*it) == MP(a[idx-2] + a[idx] - 2 * a[idx], idx-1)) s.erase(it);
		}
//		cout<<idx<<endl;
//		cout<<s.size()
		s.erase(s.begin());
//		puts("FUCK");
		a[idx] = a[idx-1] + a[idx+1] - a[idx];
//		cout<<a[idx]<<endl;
		if(idx > 2){
			if(a[idx-2] + a[idx] - 2 * a[idx])
				s.insert(MP(a[idx-2] + a[idx] - 2 * a[idx], idx-1));
		}
		if(idx < n-1 && idx + 1 <= mid){
			if(a[idx-2] + a[idx] - 2 * a[idx])
				s.insert(MP(a[idx] + a[idx+2] - 2 * a[idx], idx+1));
		}
	} 
//	puts("FUCK");
	s.clear();
	for(int i=mid+1;i<n;i++) 
		if(a[i-1] + a[i+1] - 2 * a[i] < 0)
			s.insert(MP( -(a[i-1] + a[i+1] - 2 * a[i]), i));
	while(!s.empty()){
		int idx = (s.begin()->S);
		if(idx > 2 && idx - 1 >= mid + 1){
			it = s.find(MP( -(a[idx-2] + a[idx] - 2 * a[idx]), idx-1));
			assert(it == s.end());
			if((*it) == MP(a[idx-2] + a[idx] - 2 * a[idx], idx-1)) s.erase(it); 
		}
		if(idx < n-1){
			it = s.find(MP( -(a[idx] + a[idx+2] - 2 * a[idx]), idx+1));
			assert(it == s.end());
			if((*it) == MP(a[idx-2] + a[idx] - 2 * a[idx], idx-1)) s.erase(it);
		}
		s.erase(s.begin());
		a[idx] = a[idx-1] + a[idx+1] - a[idx];
		if(idx > 2 && idx - 1 >= mid + 1){
			if(a[idx-2] + a[idx] - 2 * a[idx])
				s.insert(MP( -(a[idx-2] + a[idx] - 2 * a[idx]), idx-1));
		}
		if(idx < n-1){
			if(a[idx-2] + a[idx] - 2 * a[idx])
				s.insert(MP( -(a[idx] + a[idx+2] - 2 * a[idx]), idx+1));
		}
	} 
	calc();
	printf("%lld\n",res);
	return 0;
}

