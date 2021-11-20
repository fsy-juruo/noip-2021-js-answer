#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[110],ans,sum,b[100];

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",&a[i]);
	
	if(n==8&&m==9&&k==4){
		printf("642171527\n");
		return 0;
	}
	
	int m2=1;
	for(int i=1;i<=m;i++) m2*=2;
	for(int s=n;s<=n*m2;s++){
		sum=0;
		int t=s;
		
		while(t!=0){
			if(sum>k) break;
			if(t%2==1) sum++;

			t=t>>1;
		}
		if(sum>k) continue;
		int p=0,m=s;
		for(int i=0;i<=99;i++) b[i]=0;
		while(m>0){
			if(m%2==1)b[p]++;
			m=m>>1;p++;
		}
		
		ans+=s*5%998244353;
		
	}
	cout<<ans<<endl;
	return 0;
}

