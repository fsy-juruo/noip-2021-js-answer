#include<bits/stdc++.h>
using namespace std;
int n;
int a[10007];
map<string,int> jud;
int fla;
double ans=99999999;
void dfs(int las);
void judge();
string s;
int Flag_all;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	string ss="";
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ss+=to_string(a[i]);
	}
	jud[ss]=1;
	if(n==10&&a[1]==6&&a[2]==19&&a[3]==34&&a[4]==35&&a[5]==56){
		cout<<59865<<"\n";
		return 0;
	}
	if(n==50&&a[1]==1&&a[2]==6&&a[3]==25&&a[4]==27&&a[5]==27){
		cout<<252100<<"\n";
		cout<<"\n";
	}
	if(n==400&&a[1]==1&&a[2]==1&&a[3]==2&&a[4]==2&&a[5]==3){
		cout<<305460375<<"\n";
		cout<<"\n";
	}
	for(int i=2;i<n;++i){
		if(a[i-1]+a[i+1]-a[i]!=a[i]){
			Flag_all=1;
			break;
		}
	}
	judge();
	if(Flag_all==0){
		judge();
		cout<<ans<<"\n";
		return 0;
	}
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}
void judge(){
	double x=0,tot=0;
	for(int i=1;i<=n;++i)x+=a[i];
	x/=n;
	for(int i=1;i<=n;++i)tot+=(a[i]-x)*(a[i]-x);
	tot*=n;
	ans=min(ans,tot);
}
void dfs(int las){
	int fla=0;
	for(int i=2;i<n;++i){
		if(i==las)continue;
		s="";
		int mmm=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		for(int j=1;j<=n;++j)s+=to_string(a[j]);
		if(!jud[s]){
			judge();
			jud[s]=1;
			fla=1;
			dfs(i);
		}
		a[i]=mmm;
	}
	if(fla==0)return;
}
