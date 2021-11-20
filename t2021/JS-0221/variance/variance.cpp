#include<bits/stdc++.h>
using namespace std;

inline long long read(){
	long long x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=(ch=='-');
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

const long long N=1e4+5;

long long n,a[N],sum1,sum2,ans;

int main(){
//	freopen("in.txt","r",stdin);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	cin>>n;
	for(long long i=1; i<=n; i++)
		a[i]=read();
	
	for(long long i=1; i<=n; i++){
		sum1+=a[i];
		a[i]*=n;
	}
	
	for(long long i=1; i<=n; i++)
		sum2+=(a[i]-sum1)*(a[i]-sum1);
	
	ans=sum2/n;
	
	cout<<ans<<endl;
	
	return 0;
}

