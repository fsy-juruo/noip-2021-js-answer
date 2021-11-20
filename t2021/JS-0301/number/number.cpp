#include<bits/stdc++.h>
using namespace std;
int check(int mid){
	while(mid>0){
		if(mid%10==7) return 1;
		mid=mid/10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		bool flgg=false;
		for(int j=1;j*j<=n;j++){
			if(n%j==0){
				if(check(j)){
					flgg=true;
					break;
				}
				if(check(n/j)){
					flgg=true;
					break;
				}
			}
		}
		if(flgg==true){
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=n+1;;i++){
			bool flg=false;
			if(check(i)){
				flg=true;
			}
			for(int j=1;j*j<=i;j++){
				if(i%j==0){
					if(check(i/j)){
						flg=true;
						break;
					}
					if(check(j)){
						flg=true;
						break;
					}
				}
			}
			if(flg==false){
				cout<<i<<endl;
				break;
			}
		}
	}

	return 0;
}

