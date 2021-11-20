#include <bits/stdc++.h>
using namespace std;
const int maxm=10000002;
int T,x;
bool num[maxm];
int aft[maxm];
bool if7(int n){
	while(n){
		if(n%10==7)return true;
		n/=10;
	}
	return false;
}
void pre(){
	for(int i=maxm/2+1;i>=1;i--){
		if(num[i]){
			for(int j=i;j<=maxm-1;j+=i){
				num[j]=true;
			}
		}
	}
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	for(int i=1;i<=maxm-1;i++){
		if(if7(i))num[i]=true;
	}
	pre();
	for(int i=maxm-1;i>=1;i--){
		if(!num[i])aft[i]=i;
		else aft[i]=aft[i+1];
	}
	while(T--){
		scanf("%d",&x);
		if(num[x])cout<<-1<<endl;
		else cout<<aft[x+1]<<endl;
	}
	return 0;
}
