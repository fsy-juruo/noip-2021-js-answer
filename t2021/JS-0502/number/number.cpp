#include<bits/stdc++.h>
#define LL long long
using namespace std;
int p[10100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000000;i++){
		int x=i;
		while(x){
			if(x%10==7){
				p[i]=1;
				break;
			}
			x/=10;
		}
	}
	int T;
	cin>>T;
	while(T--){
		int x;
		cin>>x;
		int flg=0;
		for(int i=1;i*i<=x;i++){
			if(x%i==0){
				if(p[i]||p[x/i])flg=1;
			}
		}
		if(flg)cout<<-1<<endl;
		else{
			while(++x){
				flg=0;
				for(int i=1;i*i<=x;i++){
					if(x%i==0){
						if(p[i]||p[x/i])flg=1;
					}
				}
				if(!flg){
					cout<<x<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
