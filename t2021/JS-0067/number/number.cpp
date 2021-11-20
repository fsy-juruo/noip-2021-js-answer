#include <bits/stdc++.h>
using namespace std;
const int N = 10000500, M = 10000600;
int T,x;
int i,j;
int tmp[M];
bool vis[M],avl[M];
int erfen(int l,int r,int val) {
	int t;
	while (l<=r) {
		int mid=l+(r-l)/2;
		if (tmp[mid]>val)  t=mid, r=mid-1;
		else  l=mid+1;
	}
	return t;
}
int read() {
	char c=getchar();
	int sum=0;
	while (c<'0' || c>'9')  c=getchar();
	while (c>='0' && c<='9') {
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for (i=1;i<=N;i++) {
		if (i%10==7)  vis[i]=1;
		else  vis[i]=vis[i/10];
	}
	for (i=1;i<=N;i++)
		if (vis[i]&&!avl[i])
			for (j=1;j*i<=N;j++)
				avl[j*i]=1;
	for (i=1;i<=N;i++) {
		avl[i]=avl[i]|vis[i];
		if (!avl[i])  tmp[i]=tmp[i-1]+1;
		else  tmp[i]=tmp[i-1];
	}	
	while (T--) {
		x=read();
		if (avl[x]) {
			printf("-1\n");
			continue;
		}
		printf("%d\n",erfen(x+1,N,tmp[x]));
	} 
	return 0;
}

