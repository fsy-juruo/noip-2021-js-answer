#include<bits/stdc++.h>
using namespace std;

int n;
int a[10010];

bool check(int o,int p,int c,int s) {
	if ((2*a[p-1]*c+c*c)*o<2*s*c+c*c) return true;
	else if ((2*a[p-1]*c+c*c)*o==2*s*c+c*c&&a[p-2]+a[p]-2*a[p-1]>0) return true;
	else return false;
}

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	int S=a[1]+a[2];
	
	for(int i=3;i<=n;i++) {
		S+=a[i];
		
		int j=i;
		int cha=abs(a[j-2]+a[j]-2*a[j-1]);
		
		while(check(i,j,cha,S)&&j>=3) {
			S-=a[j-1];
			a[j-1]=a[j]+a[j-2]-a[j-1];
			S+=a[j-1];
			
			j--;
			cha=abs(a[j-2]+a[j]-2*a[j-1]);
		}
	}
	
	int fac_pow=0,fac=0;
	
	for(int i=1;i<=n;i++) {
		fac_pow+=a[i]*a[i];
		fac+=a[i];
	}
	
	cout<<n*fac_pow-fac*fac;
	
	return 0;
}

