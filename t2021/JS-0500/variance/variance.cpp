#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005],b[10005];
int fang(){
	int s=0,ans=0;
	for(int i=1;i<=n;i++){
		s+=b[i];
	}
	for(int i=1;i<=n;i++){
		ans+=(n*b[i]-s)*(n*b[i]-s);
	}
	ans=ans/n;
	return ans;
}
void ch(int x){
	b[x]=b[x-1]+b[x+1]-b[x];
}
void pre(){
	for(int i=1;i<=n;i++)b[i]=a[i];
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	pre();
	int ans1=0,ansm=0;
	if(n==4){
		ans1=fang();
		ansm=ans1;
		int ans=0;
		int nm=1,cha=2;
		while(ans!=ans1){
			ch(cha);cha+=nm;nm*=-1;
			ans=fang();
			ansm=min(ans,ansm);
		}
		ans=0;nm=-1;cha=3;
		while(ans!=ans1){
			ch(cha);cha+=nm;nm*=-1;
			ans=fang();
			ansm=min(ans,ansm);
		}
		cout<<ansm;
	}
	else{
		cout<<"wobuhui";
	}
	return 0;
}
