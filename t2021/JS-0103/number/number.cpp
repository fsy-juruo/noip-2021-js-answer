#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
vector<ak>zs;
ak zyz[10000100],ans[10000100];
bool ill[10000100];
bool cxk(ak xx){
	ak x=xx;
	while(x>1){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
bool fj(ak n){
	if(ill[n])return 1;
	for(ak i=2;i*i<=n;i++){
		if(n%i)continue;
		if((ill[i])||(ill[n/i]))return 1;
	}
	return 0;
}
int main(){
	#ifndef lpcak
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	ak t,n;
	ios::sync_with_stdio(0);
//	ans[1]=2;
//	F(i,2,n){
//		if(ill[i]||cxk(i))ill[i]=1;
//		if(zyz[i]==0){zyz[i]=i,zs.push_back(i);}
//		F(j,0,zs.size()-1){
//			if((zs[j]>zyz[i])||(zs[j]*i>n))break;
//			zyz[zs[j]*i]=zs[j];
//			if(ill[zs[j]]||ill[i])ill[zs[j]*i]=1;
//		}
//	}
	
//	cout<<ill[6135]<<"\n"<<ill[27]<<"\n"<<ill[27*29]<<"\n"<<ill[78]<<"\n"<<ill[62]<<"\n"<<ill[10000001];
//	
//	ak cur=10000001;
//	G(i,10000000,1){
//		if(ill[i]){
//			ans[i]=-1;continue;
//		}
//		ans[i]=cur;
//		if(ill[i]==0){
//			cur=i;
//		}
//	}
//	cin>>t;
//	F(jb,1,t){
//		ak n;cin>>n;cout<<ans[n]<<"\n";
//	}

//	F(i,1,6135)if(6135%i==0)cout<<i<<"\n";

	F(i,1,200200)if(cxk(i))ill[i]=1;
	F(i,7,200200){
		if(fj(i))ill[i]=1;
	}
	ak cur=200200;
	G(i,200200,1){
		if(ill[i]){
			ans[i]=-1;continue;
		}
		ans[i]=cur;
		if(ill[i]==0){
			cur=i;
		}
	}
	cin>>t;
	F(jb,1,t){
		cin>>n;
		cout<<ans[n]<<"\n";
	}
	
	return 0;
}
/*

4 6 33 69 300

5 90 99 106 114 169

*/
