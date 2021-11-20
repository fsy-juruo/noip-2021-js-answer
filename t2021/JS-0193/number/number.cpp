#include<bits/stdc++.h>
using namespace std;
#define N 10000007
int T;
bool num[N];
int a[N],b[N];
void judge(int x){
	for(int i=1;i*x<=N;i++){
		num[i*x]=true;
	}
}
void pre1(){
	for(int i=7;i<=N;i++){
		if(!num[i]){
//			bool flag=false;
			int x=i;
			while(x){
				if(x%10==7){
					judge(i);
					break;
				}
				x/=10;
			}
		}
	}
}
int cnt=1;
void pre2(){
	for(int i=1;i<=N;i++){
		if(!num[i]){
			b[cnt]=i;
			a[i]=cnt++;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	pre1();
	pre2();
	while(T--){
		int x;
		cin>>x;
//		for(int i=1;i<=100;i++){
//			cout<<b[i]<<" ";
//		}
		if(num[x]){
			cout<<-1<<'\n';
		}
		else{
			cout<<b[a[x]+1]<<'\n';
		}
	}
	return 0;
}

