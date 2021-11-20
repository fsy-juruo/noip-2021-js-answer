#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,ans=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<3)+(ans<<1)+c-'0';c=getchar();}
	return f*ans;
}
void print(int xx){
	if(xx<0){
		putchar('-');
		print(-xx);
		return;
	}
	if(xx>9)print(xx/10);
	putchar(xx%10+'0');
	return;
}
int a[10010];
long long h=0,fh=0;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		fh+=a[i]*a[i];
		h+=a[i];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		cout<<n*(a[1]*a[1]+a[2]*a[2])-(a[1]+a[2])*(a[1]+a[2])<<endl;
		return 0;
	}
	if(n>4){
		long long ans=INT_MAX;
		ans*=100000;
		int jt=0;
		for(int i=1;i<=5000000;i++){
			int j=(rand()*rand()+rand()-1+rand())%(n-4)+2;
			while(j==jt){
				j=rand()%(n-4)+2;
			}
			jt=j;
			fh-=a[j]*a[j];
			h-=a[j];
			a[j]=a[j-1]+a[j+1]-a[j];
			fh+=a[j]*a[j];
			h+=a[j];
			long long tans;
			tans=n*fh;
			tans-=h*h;
			ans=min(tans,ans);
		}
		cout<<ans<<endl;
		return 0;
	}
	int t=1;
	for(int i=1;i<=(n-2);i++){
		t*=2;
	}
	long long ans=INT_MAX;
	for(int i=1;i<=t;i++){
		for(int j=2;j<=n-2;j++){
			fh-=a[j]*a[j];
			h-=a[j];
			a[j]=a[j-1]+a[j+1]-a[j];
			fh+=a[j]*a[j];
			h+=a[j];
			long long tans;
			tans=n*fh;
			tans-=h*h;
			ans=min(tans,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
