#include<bits/stdc++.h>
using namespace std;
int n,a[10005],s,S;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		S+=a[i]*a[i];
	}
	if(n==1)cout<<0<<endl;
	else if(n==2)cout<<S*n-s*s<<endl;
	else if(n==3){
		int ans1=S*n-s*s;
		int x=a[1]+a[3]-a[2];
		int ans2=n*(a[1]*a[1]+x*x+a[3]*a[3])-(a[1]+x+a[3])*(a[1]+x+a[3]);
		cout<<max(ans1,ans2)<<endl;
	}
	else if(n==4){
		int ans4=INT_MAX;
		for(int i=1;i<=6;i++){
			if(i%2==1)a[2]=a[1]+a[3]-a[2];
			else a[3]=a[2]+a[4]-a[3];
			s=0;
			S=0;
			for(int j=1;j<=4;j++){
				s+=a[j];
				S+=a[j]*a[j];
			}
			ans4=min(ans4,n*S-s*s);
		}
		cout<<ans4<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
