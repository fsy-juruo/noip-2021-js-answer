#include<bits/stdc++.h>
using namespace std;
int c=0;
int check(int m){
	for(int i=1;i<=sqrt(m);i++){
		int e;
		c=0;
		if(m%i==0){
			e=m/i;
			if(e%7==0){
				c=1;
				break;
			}
			int b=e;
			while(b!=0){
				if(b%10==7){
					c=1;
					return 0;
				}
				b/=10;
			}
			if(i%7==0){
				c=1;
				break;
			}
			 b=i;
			while(b!=0){
				if(b%10==7){
					c=1;
					return 0;
				}
				b/=10;
			}
		}
		else{
			continue;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		c=0;
		check(a);
		if(c==1){
			cout<<"-1"<<endl;
			continue;
		}
		else{
			while(1){
				a+=1;
				c=0;
				check(a);
				if(c==0){
					cout<<a<<endl;
					break;
				}
			}
		}
	}
}
