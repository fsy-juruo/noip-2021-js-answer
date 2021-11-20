#include<bits/stdc++.h>
using namespace std;
bool CF(int n){
	int x=n;
	while(x){
		if(x%10==7){
			return false;
		}
		x/=10;
	}
	return true;
} 
bool check(int n){
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(!CF(i)){
				return false; 
			}else if(!CF(n/i)){
				return false;
			}
		}
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	cin>>T;
	
	for(int p=1;p<=T;p++){
		int r;
		cin>>r;
		if(!check(r)){
			cout<<"-1"<<endl;
		}else{
			while(!check(r+1)){
				r++;
			}
			cout<<r+1<<endl;
		}
	} 
	return 0;
}

