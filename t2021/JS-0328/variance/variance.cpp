#include<bits/stdc++.h>
using namespace std;
int n;
double sum,ans,a[10005];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum/=n;
	//cout<<sum<<endl;
	for(int i=1;i<=n;i++){
		ans+=(a[i]-sum)*(a[i]-sum);
	}
	//cout<<ans<<endl;
	ans/=n;
	cout<<ans*n*n<<endl;
	return 0;
}
