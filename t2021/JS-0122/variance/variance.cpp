#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf=0x3f3f3f3f;
const int N=1e4+10;

int n;
int a[N];
ll sum;
ll ans;

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10-'0'+ch;ch=getchar();}
	return f*x;
}

bool adjust(int x){
	sum+=a[x+1]+a[x-1]-2*a[x];
	if (a[x]==a[x+1]+a[x-1]-a[x])return 0;
	a[x]=a[x+1]+a[x-1]-a[x];return 1;
}

int main()
{
	freopen("variance.in","r",stdin);
  freopen("variance.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++){a[i]=read();sum+=a[i];}
	int flag=0;
//	cerr<<"aha"<<endl;
	int r=upper_bound(a+1,a+n+1,(sum+n-1)/n)-a,l=r-1;
	do{
		flag=0;
		for (int i=r;i<n;i++){
//			cerr<<i<<endl;
			if ((a[i+1]+a[i-1]-2*a[i]>0 && (n-1)*(a[i-1]+a[i+1])+2*a[i]-2*sum<0) ||
				(a[i+1]+a[i-1]-2*a[i]<0 && (n-1)*(a[i-1]+a[i+1])+2*a[i]-2*sum>0)){
				flag|=adjust(i);
			}
		}
		for (int i=l;i>=2;i--){
//			cerr<<i<<endl;
			if ((a[i+1]+a[i-1]-2*a[i]>0 && (n-1)*(a[i-1]+a[i+1])+2*a[i]-2*sum<0) ||
				(a[i+1]+a[i-1]-2*a[i]<0 && (n-1)*(a[i-1]+a[i+1])+2*a[i]-2*sum>0)){
				flag|=adjust(i);
			}
		}
//		for (int i=1;i<=n;i++)cerr<<a[i]<<' ';cerr<<endl;
	}while (flag==1);
	for (int i=1;i<=n;i++){
		ans+=a[i]*a[i];
	}
	ans*=n;
	ans-=sum*sum;
	printf("%lld\n",ans);

	return 0;
}

