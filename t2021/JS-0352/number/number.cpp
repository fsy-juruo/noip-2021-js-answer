#include<bits/stdc++.h>

using namespace std;
const int MAXN=1e4+100;
int T;
int num[MAXN];
void pc(){
	num[7]=1;
	for(int i=7;i<MAXN;i++){
		int p=i;
		while(p>0){
			if(num[p%10]==1){
				for(int k=1;k*i<MAXN;k++){
					num[k*i]=1;
				}
				break;
			}
			else{
				p/=10;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	pc();
	while(T--){
		int n;
		cin>>n;
		if(num[n]==1){
			cout<<"-1"<<endl;
		}
		else{
			int i=n+1;
			while(num[i]==1){
				i++;
			}
			cout<<i<<endl;
		}
	}
	return 0;
}

