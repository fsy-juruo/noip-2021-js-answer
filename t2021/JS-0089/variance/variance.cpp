#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int rdi(){//signed
	int x=0,y=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')y=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*y;
}
int rdui(){//unsigned
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
int n;
int a[10010],b[10010],c[10010];
int cur[10010];
// int ans[1010][1010];
int dp[10010][10010];
int f(int x,int y){
	if(x<y)swap(x,y);
	return (n-x)*y;
}
int dfs(int l,int r){
	if(dp[l][r]!=-1)return dp[l][r];
	int&ret=dp[l][r];
	int pos=r-l+1;
	if(l==r)return ret=b[pos]*b[pos]*f(l,l);
	int suml=dfs(l+1,r)+f(l,l)*b[pos]*b[pos];
	int sumr=dfs(l,r-1)+f(r,r)*b[pos]*b[pos];
	for(int i=l+1;i<=r;i++)suml+=2*f(l,i)*b[pos]*b[i-l];
	for(int i=l;i<=r-1;i++)sumr+=2*f(r,i)*b[pos]*b[i-l+1];
	return ret=min(suml,sumr);
}
void solve20(){
	int ret=Inf;
	do{
		int ans=0;
		for(int i=1;i<n;i++)
			for(int j=1;j<n;j++)
				ans+=f(i,j)*b[i]*b[j];
		ret=min(ret,ans);
	}while(next_permutation(b+1,b+n));
	printf("%lld\n",ret);
	// do{
	// 	int ans=0;
	// 	for(int i=1;i<n;i++)
	// 		for(int j=1;j<n;j++)
	// 			ans+=f(i,j)*b[i]*b[j];
	// 	if(ans==ret){
	// 		for(int i=1;i<n;i++)printf("%d ",b[i]);
	// 		puts("");
	// 	}
	// }while(next_permutation(b+1,b+n));
}
void solve100(){
	int pos=0,beg=n/2;
	c[beg]=b[++pos];
	int presum=f(beg,beg)*c[beg]*c[beg];
	for(int i=beg,j=beg;i>=1&&j<n;){
		if(i-1<1&&j+1>=n)break;
		int suml=presum,sumr=presum;
		if(i-1>=1){//calc suml
			c[i-1]=b[pos+1];
			suml+=c[i-1]*c[i-1]*f(i-1,i-1);
			for(int k=i;k<=j;k++)suml+=2*f(i-1,k)*c[i-1]*c[k];
			c[i-1]=0;
		}
		if(j+1<n){//calc sumr
			c[j+1]=b[pos+1];
			sumr+=c[j+1]*c[j+1]*f(j+1,j+1);
			for(int k=i;k<=j;k++)sumr+=2*f(j+1,k)*c[j+1]*c[k];
			c[j+1]=0;
		}
		if(i-1<1)c[++j]=b[++pos],presum=sumr;
		else if(j+1>=n)c[--i]=b[++pos],presum=suml;
		else if(suml<sumr)c[--i]=b[++pos],presum=suml;
		else c[++j]=b[++pos],presum=sumr;
	}
	for(int i=1;i<n;i++)printf("%lld ",c[i]);
	puts("");
	printf("%lld",presum);
	// printf("%lld\n",dfs(1,n-1));
}
signed main(){
#ifndef OFFLINE
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
#endif
	memset(dp,-1,sizeof dp);
	n=rdui();
	for(int i=1;i<=n;i++)a[i]=rdui();
	if(n==1)return puts("0"),0;
	if(n==2)return printf("%lld\n",(a[2]-a[1])*(a[2]-a[1]));
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	// for(int i=1;i<n;i++,puts(""))
	// 	for(int j=1;j<n;j++)
	// 		printf("%lld ",f(i,j));
	sort(b+1,b+n);
	if(n<=10)solve20();
	else solve100();
	return 0;
}






/*
9  8  7  6  5  4  3  2 1
8 16 14 12 10  8  6  4 2
7 14 21 18 15 12  9  6 3
6 12 18 24 20 16 12  8 4
5 10 15 20 25 20 15 10 5
4  8 12 16 20 24 18 12 6
3  6  9 12 15 18 21 14 7
2  4  6  8 10 12 14 16 8
1  2  3  4  5  6  7  8 9



9 8 7 6 5 4 3 2 1
8 16 14 12 10 8 6 4 2
7 14 21 18 15 12 9 6 3
6 12 18 24 20 16 12 8 4
5 10 15 20 25 20 15 10 5
4 8 12 16 20 24 18 12 6
3 6 9 12 15 18 21 14 7
2 4 6 8 10 12 14 16 8
1 2 3 4 5 6 7 8 9

10
20 10
30 20 10
40 30 20 10

*/