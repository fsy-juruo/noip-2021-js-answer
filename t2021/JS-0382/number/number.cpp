#include<bits/stdc++.h>
using namespace std;
int q[200001];
bool p(int x){
	while(x){
		if(x%10==7){
			return 1;
		}
		x=x/10;
	}
	return 0;
}
int fj(int n){
	bool flag=false;
	int q=2;
	while(n>1){
		flag=false;
		if(n%q==0){
			if(p(q)==1||p(n/q)==1){
				return 1;
			}
			else{
			n=n/q;
			flag=true;
			}			
		}
		if(flag==false){
			q++;
		}
	}
	return 0;	
}
int t;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	int k=1;
	while(t){
		t--;
		cin>>n;
		if(fj(n)==1){
			q[k]=-1;
			k++;
			continue;
		}
		else{
			int ans=n+1;
			while(1){
			if(p(ans)==0){
				if(fj(ans)==0){
					q[k]=ans;
					k++;
					break;
				}
			}
				ans++;
			}
		}
	}
	for(int i=1;i<k;i++){
		cout<<q[i]<<endl;
	}
	return 0;
}

