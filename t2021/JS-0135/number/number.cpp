#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	int y=1;
	char a;
	a=getchar();
	while(a<'0'||a>'9'){
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=y;
}
vector<int>fz;
int fff(int x){
	if(x%10==7)return true;
	x/=10;
	if(x%10==7)return true;
	x/=10;
	if(x%10==7)return true;
	x/=10;
	if(x%10==7)return true;
	x/=10;
	if(x%10==7)return true;
	x/=10;
	if(x%10==7)return true;
	x/=10;
	if(x%10==7)return true;
	x/=10;
	if(x%10==7)return true;
	return false;
}
bool qfz[10000008];
vector<int>fans;
int find(int x){
	int l=0,r=fans.size()-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(fans[mid]==x)return mid;
		if(fans[mid]<x)l=mid+1;
		if(fans[mid]>x)r=mid-1;
	}
}
int t,x,n;
vector<int>fx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(t);
	while(t--){
		read(x);
		n=max(n,x);
		fx.push_back(x);
	}
	n=min(n+1000002,10000001);
	for(int i=1;i<=n;++i){
		if(fff(i))fz.push_back(i),qfz[i]=1;
	}
	for(int i=1;i<=n/7;++i){
		for(int j=0;j<fz.size();++j){
			if(fz[j]*i>n)break;
			qfz[fz[j]*i]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(qfz[i]==0)fans.push_back(i);
	}
	for(int i=0;i<fx.size();++i){
		x=fx[i];
		if(qfz[x]){
			cout<<-1<<endl;
			continue;
		}
		cout<<fans[find(x)+1]<<endl;
	}
	return 0;
}


