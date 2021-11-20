#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ss=0;char cc=getchar();bool ff=1;
	for(cc;!isdigit(cc);cc=getchar()) if(cc=='-')	ff=0;
	for(cc;isdigit(cc);cc=getchar()) ss=(ss<<3)+(ss<<1)+cc-'0';
	return ff?ss:-ss;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=read();
	double a[100010],b[100010],s=0,ans=0,maxn=9999999;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
		cout<<"0"<<endl;
	if(n==2){
		s=a[1]+a[2];
		ans=((n*a[1]-s)*(n*a[1]-s)+(n*a[2]-s)+(n*a[2]-s))/n;
		cout<<ans<<endl;
	}
	if(n==3){
		for(int j=1;j<=n;j++)
			s+=a[j];
		for(int j=1;j<=n;j++)
			ans+=(n*a[j]-s)*(n*a[j]-s);
		maxn=min(maxn,ans);
		a[2]=a[1]+a[3]-a[2];
		s=0;
		for(int j=1;j<=n;j++)
			s+=a[j];
		for(int j=1;j<=n;j++)
			ans+=(n*a[j]-s)*(n*a[j]-s);
		maxn=min(maxn,ans);
		ans=0;
		cout<<maxn/n<<endl;
	}
	if(n==4){
		s=0;
		for(int j=1;j<=n;j++)
				s+=a[j];
		for(int j=1;j<=n;j++)
			ans+=(n*a[j]-s)*(n*a[j]-s);
			//cout<<ans<<endl;
		maxn=min(maxn,ans);
		ans=0;
		for(int k=2;k<=3;k++){
			for(int i=1;i<=n;i++)
				b[i]=a[i];
			b[k]=b[k-1]+b[k+1]-b[k];
			s=0;
			for(int j=1;j<=n;j++)
				s+=b[j];
			for(int j=1;j<=n;j++)
				ans+=(n*b[j]-s)*(n*b[j]-s);
			//cout<<ans<<endl;
			maxn=min(maxn,ans);
			ans=0;
		}
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		b[2]=b[1]+b[3]-b[2];
		b[3]=b[2]+b[4]-b[3];
		//for(int i=1;i<=n;i++)
		//	cout<<b[i]<<endl;
		s=0;
		for(int j=1;j<=n;j++)
			s+=b[j];
		//cout<<s<<endl;
		for(int j=1;j<=n;j++){
			ans+=(n*b[j]-s)*(n*b[j]-s);
			//cout<<(n*b[j]-s)<<endl;
			//cout<<ans<<endl;	
		}
		//cout<<ans<<endl;
		maxn=min(maxn,ans);
		ans=0;
		b[3]=b[2]+b[4]-b[3];
		b[2]=b[3]+b[1]-b[2];
		s=0;
		for(int j=1;j<=n;j++)
			s+=b[j];
		for(int j=1;j<=n;j++)
			ans+=(n*b[j]-s)*(n*b[j]-s);
		//cout<<ans<<endl;
		maxn=min(maxn,ans);
		ans=0;
		maxn=maxn/n;
		cout<<maxn<<endl;
	}
	return 0;
}

