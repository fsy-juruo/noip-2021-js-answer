#include<bits/stdc++.h>
#define filename "variance"
#define lint long long
using namespace std;
const int maxn=200;
int read(){
	int re=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		re=(re<<3)+(re<<1)+(ch^48);
		ch=getchar();
	}
	return f*re;
}
struct que{
	int num[maxn];
};
int n,cnt,a[maxn],last[maxn*maxn][maxn];
lint ans=1ll<<60;
que q[maxn*maxn];
bool check(int x[]){
	for(int i=1;i<=cnt;i++){
		bool flag=0;
		for(int j=1;j<=n;j++)
		  if(last[i][j]!=x[j]){
		  	flag=1;
		  	break;
		  }
	    if(!flag) return 0;
	}
	return 1;
}
lint calc(int x){
	lint temp=0,sum=0;
	for(int i=1;i<=n;i++) temp+=n*last[x][i]*last[x][i],sum+=last[x][i];
	temp-=sum*sum;
	return temp;
}
void bfs(){
	int l=0,r=1;
	for(int i=1;i<=n;i++)
	  q[r].num[i]=a[i];
	++cnt;
	for(int i=1;i<=n;i++)
	  last[cnt][i]=a[i];
	ans=min(ans,calc(cnt));
	while(l<r){
		int xx[maxn];
		++l;
		for(int i=1;i<=n;i++)
		  xx[i]=q[l].num[i];
		for(int i=2;i<n;i++){
			xx[i]=xx[i+1]+xx[i-1]-xx[i];
			if(check(xx)){
				++cnt;
				for(int i=1;i<=n;i++)
				  last[cnt][i]=xx[i];
				ans=min(ans,calc(cnt));
				++r;
				for(int i=1;i<=n;i++)
				  q[r].num[i]=xx[i];
			}
		}
	}
}
int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    bfs();
    printf("%lld\n",ans);
	return 0;
}

