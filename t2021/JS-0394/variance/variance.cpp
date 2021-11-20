#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,a[10005];
int read(){
	char c=' ';
	int num=0;
	c=getchar();
	while (c!='\n'&&c!=' '){
		num=num*10+c-'0';
		c=getchar();
	}
	return num;
}
int find(int ch,int ans){
	if (ch>=n||ch<=1) return min(100000000,ans);
	int tmp=a[ch];
	a[ch]=a[ch-1]+a[ch+1]-a[ch];
	int sum=0;
	for (int i=1;i<=n;++i){
		sum+=a[i];
	}
	double avg=sum/n,var=0;
	for (int i=1;i<=n;++i){
		var+=n*(a[i]-avg)*(a[i]-avg);
	}
	ans=min(ans,(int)(round(var)));
	ans=min(ans,find(ch-1,ans));
	ans=min(ans,find(ch+1,ans));
	a[ch]=tmp;
	return ans;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i){
		a[i]=read();
	}
	int ans=100000000;
	for (int i=2;i<n-1;++i){
		int sum=0;
		for (int i=1;i<=n;++i){
			sum+=a[i];
		}
		double avg=sum/n,var=0;
		for (int i=1;i<=n;++i){
			var+=n*(a[i]-avg)*(a[i]-avg);
		}
		ans=min(ans,(int)(round(var)));
		ans=min(ans,find(2,1e8));
		ans=min(ans,find(3,1e8));
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
