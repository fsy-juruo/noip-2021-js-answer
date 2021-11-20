#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool b[10000101];
int ans[10000101];
int T,x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	for(int i=1;i<=10000001;i++)b[i]=1;
	for(int i=7;i<=10000001;i++) if(i%10==7||(i%100)/10==7||(i%1000)/100==7||
	(i%10000)/1000==7||(i%100000)/10000==7||(i%1000000)/100000==7||i/1000000==7){
		for(int j=i;j<=10000000;j+=i)b[j]=0;
	}
	int a=1;
	for(int i=2;i<=10000101;i++) if(b[i]){
		ans[a]=i;
		a=i;
	}
	while(T--){
		cin>>x;
		if(!b[x])cout<<"-1\n";
		else cout<<ans[x]<<endl;
	}
	return 0;
}
