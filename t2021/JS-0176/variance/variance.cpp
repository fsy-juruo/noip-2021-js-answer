#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
int n,sum,ans,a[N],b[N];
int gao(){
	int ab=0,ac=0;
	for(int i=0;i<n;i++)
		ac+=a[i];
	for(int i=1;i!=-1;i=b[i]){
		int x=a[i-1]+a[i+1]-a[i];
		if(abs(n*x-ac)<abs(n*a[i]-ac)){
			ab++;
			ac+=x-a[i];
			a[i]=x;
		}
	}
	return ab;
}
int gg(){
	int ab=0,ac=0;
	for(int i=0;i<4;i++){
		ab+=4*a[i]*a[i];
		ac+=a[i];
	}
	return ab-ac*ac;
}
void jj(int x){
	a[x]=a[x-1]+a[x+1]-a[x];
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin >> n;
	for(int i=1;i*2<n-1;i++)
		b[i]=n-i-1;
	for(int i=n-2;i*2>n;i--)
		b[i]=n-i;
	b[n/2]=-1;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(n<=4){
		if(n==1)ans=0;
		if(n==2)ans=2*(a[0]*a[0]+a[1]*a[1])-(a[0]+a[1])*(a[0]+a[1]);
		if(n==3){
			for(int i=0;i<3;i++){
				ans+=3*a[i]*a[i];
				sum+=a[i];
			}
			ans-=sum*sum;
			int ab=0,sum=0;
			a[1]=a[0]+a[2]-a[1];
			for(int i=0;i<3;i++){
				ab+=3*a[i]*a[i];
				sum+=a[i];
			}
			ans=min(ans,ab-sum*sum);
		}
		if(n==4){
			ans=gg();
			jj(1),ans=min(ans,gg());
			jj(2),ans=min(ans,gg());
			jj(2),jj(1),jj(2);
			ans=min(ans,gg());
			jj(1),ans=min(ans,gg());
		}
		cout << ans;
		return 0;
	}
	while(gao()>0);
	for(int i=0;i<n;i++)
		sum+=a[i];
	for(int i=0;i<n;i++)
		ans+=n*a[i]*a[i];
	ans-=sum*sum;
	cout << ans;
	return 0;
}
