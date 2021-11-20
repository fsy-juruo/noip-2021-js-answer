#include<bits/stdc++.h>
using namespace std;
int T;
bool check(int x){
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0){
			int y=x/i;
			while(y>0){
				int m=y%10;
				if(m==7)return 1;
				else y/=10;
			}
		}
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	while(T--){
		int x;
		cin>>x;
		if(check(x))
			cout<<-1<<endl;
		else{
			while(1){
				if(!check(x+1))
				break;
				else x++;
			}
			cout<<x+1<<endl;
		}
	}
return 0;
}

