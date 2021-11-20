#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int n;
int a[10010];
int Get(){
	int f=0;
	for(int i=1;i<=n;i++)f+=a[i]*a[i];
	f*=n;
	int g=0;
	for(int i=1;i<=n;i++)g+=a[i];
	g*=g;
	return f-g;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=4){
		if(n==1)cout<<0<<' '<<Get()<<endl;
		if(n==2)cout<<(a[1]-a[2])*(a[1]-a[2])<<' '<<Get()<<endl;
		if(n==3){
			int ans1=Get();
			a[2]=a[1]+a[3]-a[2];
			int ans2=Get();
			cout<<min(ans1,ans2)<<endl;
		}
		if(n==4){
			int ans=4*9*9+10;
			for(int i=1;i<=6;i++){
				if(i%2==0){
					a[2]=a[3]+a[1]-a[2];
				}else{
					a[3]=a[2]+a[4]-a[3];
				}
				ans=min(ans,Get());
			}
			cout<<ans<<endl;		
		}
		return 0;
	}
	return 0;
}
