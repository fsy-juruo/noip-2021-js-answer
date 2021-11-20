#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10000;
int pd[maxn];
int len=1;
vector<int>a;
int n;
float fc(vector<int> a){
	float arrage=0;
	int num=a.size()-1;
	for(int i=1;i<=num;i++)arrage+=(float)a[i];
	arrage/=(float)num;
	float sum=0;
	for(int i=1;i<=num;i++)
		sum+=(a[i]-arrage)*(a[i]-arrage);
	sum/=num;
	return sum*n*n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	a.push_back(-1);
	if(n==1){
		int x;cin>>x;
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		int x;
		for(int i=1;i<=n;i++)cin>>x,a.push_back(x);
		cout<<fc(a);
		return 0;
	}
	if(n==3){
		int x;
		for(int i=1;i<=n;i++)cin>>x,a.push_back(x);
		float a1=fc(a);
		a[2]=a[1]+a[3]-a[2];
		float a2=fc(a);
		cout<<min(a1,a2)<<endl;
		return 0;
	}
	if(n==4){
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			a.push_back(x); 
		}
		int a1=fc(a);
		a[2]=a[1]+a[3]-a[2];
		int a2=fc(a);
		a[3]=a[2]+a[4]-a[3];
		int a3=fc(a);
		a[3]=a[2]+a[4]-a[3];
		a[2]=a[1]+a[3]-a[2];
		a[3]=a[2]+a[4]-a[3];
		int a4=fc(a);
		a[2]=a[1]+a[3]-a[2];
		int a5=fc(a);
		cout<<min(min(min(a1,a2),a3),min(a4,a5));
	}
	return 0;
}

