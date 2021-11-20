#include<bits/stdc++.h>
using namespace std;

const int maxn=10000005;
int	len;
int p[maxn];
int t[maxn];

bool judge(int num) {
	while(num) {
		int dig=num%10;
		if(dig==7) return false;
		num/=10;
	}
	return true;
}

const int B=10000001;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	len=0;
	for(int i=1;i<=B;i++) {
		if(!judge(i)&&!p[i]) {
			p[i]=1;
			for(int j=i+i;j<=B;j+=i) {
				p[j]=1;
			}
		}
	}
	for(int i=B;i>=1;i--) {
		if(p[i]==0) t[i]=i;
		else t[i]=t[i+1];
	}
	int T;
	scanf("%d",&T);
	while(T--) {
		int x;
		scanf("%d",&x);
		if(p[x]==1) printf("-1\n");
		else printf("%d\n",t[x+1]);
	}
	return 0;
}
