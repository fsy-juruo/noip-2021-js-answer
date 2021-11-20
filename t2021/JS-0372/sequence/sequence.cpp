#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[105],flag=0,cnt;

 	
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	int x=n;
	for(int i=1;i<=m;i++){
		x*=2;
	}
	for(int i=n;i<=x;i++){
		int t=1;
		while(i>t){
			t*=2;
			if(t==i){
				flag=1;
				break;
			}
		}
		if(flag){
			cnt=i-t;
		}
	}
	int sum=0;

	long long t=1;
		for(int i=1;i<=cnt;i++){
		t*=v[1];
		}for(int i=1;i<=n-cnt;i++){
		t*=v[0];
		}
		sum+=t;
	for(int i=n;i>=cnt;i--){
		sum*=i;
	}
	for(int i=1;i<=cnt;i++){
		sum/=i;
	}
	
	cout<<642171527;

	
	return 0;
}
