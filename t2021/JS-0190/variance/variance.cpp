#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 500099
#define mod 998244353
#define irep(i,l,r) for(int i=l;i<=r;++i)
#define drep(i,l,r) for(int i=r;i>=l;--i)

using namespace std;

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s*=10,s+=ch-'0';
		ch=getchar();
	}
	return s*w;
}

int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-x*(a/b);
	return d;
}
int n;
vector<int>g[N],c[N];

void add_edge(int x,int y,int w){
	g[x].push_back(y);
	c[x].push_back(w);
}

//freopen("NOIP.in","r",stdin);
//
ll b[N];
void FILEREAD(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}
ll sum,sqsum,a[N],ans=mod,fc;
void dfs(){
	int fl=0;
	for(int i=2;i<n;++i){
		ll oda=a[i],ods=sum,odsq=sqsum;
		ll v=n*sqsum-sum*sum;
		ans=min(ans,v);
		ll ap=a[i-1]+a[i+1]-a[i];
		ll vp=n*(sqsum-a[i]*a[i]+ap*ap)-(sum-a[i]+ap)*(sum-a[i]+ap);
		if(vp<v){
			sqsum=sqsum-a[i]*a[i]+ap*ap;
			sum=sum-a[i]+ap;
			v=vp;
			a[i]=ap;
			dfs();
			a[i]=oda,sum=ods,sqsum=odsq;
		}
	}
	
}
void work(int i){
	ll ap=a[i-1]+a[i+1]-a[i];
	sqsum=sqsum-a[i]*a[i]+ap*ap;
	sum=sum-a[i]+ap;
	a[i]=ap;
	fc=n*sqsum-sum*sum;
}

int main(){
	FILEREAD();
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),sum+=a[i],sqsum+=a[i]*a[i],b[i]=a[i];
	if(1){
		dfs();
		cout<<ans<<endl;
		return 0;
	}
	ll x=sum,y=sqsum;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)b[j]=a[j];
		for(int j=i+1;j<n;++j){
			work(j);
		}
		for(int j=i-1;j>1;--j){
			work(j);
		}
		ans=min(ans,fc);
	}
	cout<<ans<<endl;
	/*
	while(1){
		int fl=0;
		for(int i=2;i<n;++i){
			ll v=n*sqsum-sum*sum;
			ll ap=a[i-1]+a[i+1]-a[i];
			ll vp=n*(sqsum-a[i]*a[i]+ap*ap)-(sum-a[i]+ap)*(sum-a[i]+ap);
			if(vp<v){
				sqsum=sqsum-a[i]*a[i]+ap*ap;
				sum=sum-a[i]+ap;
				v=vp;
				a[i]=ap;
				fl=1;
			}
		}
		if(fl==0)break;
	}
	*/
//	cout<<ans<<endl;
//	cout<<n*sqsum-sum*sum;
	return 0;
} 
