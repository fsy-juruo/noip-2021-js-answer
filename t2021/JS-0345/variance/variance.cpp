#include<bits/stdc++.h>
using namespace std;
int a[10005],sum,ans;
char c[10005];
string s="";
int n;
map<string,int> mp;
/*int bfs(int i) {//调不出来 
	while(i<n-1) {
		sum=0;
		int var=0;
		char ch=s[i];
		int b=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		s[i]=char(a[i]);
		if(mp[s]==1){
			a[i]=b;
			s[i]=ch;
			continue;
		}
		mp[s]=1;
		for(int j=1; j<=n; j++) {
			var+=n*a[j]*a[j];
			sum+=a[j];
		}
		var=var-sum*sum;
		ans=min(ans,var);
		i++;
	}
	return ans;
}*/
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
		ans+=n*a[i]*a[i];
		s+=char(a[i]);
	}
	mp[s]=1;
	ans=ans-sum*sum;
	//int k=bfs(1);
	printf("%d\n",ans);
	return 0;
}
