#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
#define lowbit(n) n&(-n)
bool b[10000010];
bool check(int x){
	while (x){
		if (x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int m,a[7634010],x,T;
void write(int x){
	if (x<=9){
		putchar(x+48); return;
	}
	write(x/10);
	putchar(x%10+48);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=1;i<=10000000;i++){
		if (!b[i]&&check(i)){
			int p=10000000/i;
			for (int j=1;j<=p;j++){
				b[i*j]=1;
			}
		}
	}
	for (int i=1;i<=10000000;i++){
		if (b[i]==0) a[++m]=i;
	}
	a[++m]=10000001;
	read(T);
	while (T--){
		read(x);
		int p=lower_bound(a+1,a+m+1,x)-a+1;
		if (b[x]){
			puts("-1"); continue;
		}
		write(a[p]); puts("");
	}
	return 0;
}

