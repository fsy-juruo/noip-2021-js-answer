#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],h[110000][110],num;
long long ans=-1;
int read(){
	int xx=0,ff=1;char ch=getchar();
	while (!isdigit(ch)) {if (ch=='-') ff=-1; ch=getchar();}
	while (isdigit(ch)) {xx=(xx<<1)+(xx<<3)+ch-'0';ch=getchar();}
	return xx*ff;
}
void dfs(){
//	if (clock()>900){
//		cout<<ans<<endl;
//		exit(0);
//	}
	long long s=0,ss=0;
	for (int i=1; i<=n; i++) ss+=a[i];//,cout<<a[i]<<' 'cout<<endl;
	for (int i=1; i<=n; i++){
		s+=(n*a[i]-ss)*(n*a[i]-ss);
	}
	s/=n;
	if (ans==-1||s<ans) ans=s;
//	else deep++;//cout<<'!'<<ans<<' '<<s<<endl;
//	if (deep>10) return;
	for (int i=2; i<n; i++)
	{
		if (a[i]!=a[i-1]+a[i+1]-a[i]){
			int t=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
		//	if (abs(a[i]*n-ss)<abs(t*n-ss)) 
		  //  int f=1;
		    for (int ii=1; ii<=num; ii++){
		    	int f=1;
		    	for (int j=1; j<=n; j++){
		    		if (a[j]!=h[ii][j]) f=0; 
				}
				if (f==1) return;
			}
			++num;
			for (int j=1; j<=n; j++)
			  h[num][j]=a[j];
			dfs();
			a[i]=t;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for (int i=1; i<=n; i++){
		a[i]=read();
	}
	num=1;
	for (int i=1; i<=n; i++)
	  h[1][i]=a[i];
	dfs();
//	cout<<'!';
//	for (int i=1; i<=num; i++){
//		for (int j=1; j<=n; j++)
//	    cout<<h[i][j]<<' ';cout<<endl;
//	}
//	  
	cout<<ans<<endl;
	return 0;
}
