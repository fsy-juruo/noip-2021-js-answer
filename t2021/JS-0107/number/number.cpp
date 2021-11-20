#include<bits/stdc++.h>
using namespace std;
int t,a[200005],cnt=0,nxt[200005];
bool b[200005];
bool check(int x){
	while(x){
		int i=x%10;
		if(i==7) return false;
		x/=10;
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	if(t<=1000){
		for(int i=1;i<=10000;i++){
			if(!check(i)) {
				cnt++;
				a[cnt]=i;
				b[i]=1;
			}
		}
		for(int i=1;i<=cnt;i++){
			int j=2;
			while(a[i]*j<=10000){
				b[a[i]*j]=1;
				j++;
			}
		}
		int m=0;
		for(int i=1;i<=10000;i++){
			if(b[i]==1) nxt[i]=-1;
			else {
				nxt[m]=i;
				m=i;
			}
		}
		for(int i=1;i<=t;i++){
			int x;
			scanf("%d",&x);
			cout<<nxt[x]<<endl;
		}
	}
	else{
		for(int i=1;i<=200005;i++){
			if(!check(i)) {
				cnt++;
				a[cnt]=i;
				b[i]=1;
			}
		}
		for(int i=1;i<=cnt;i++){
			int j=2;
			while(a[i]*j<=200005){
				b[a[i]*j]=1;
				j++;
			}
		}
		int m=0;
		for(int i=1;i<=200005;i++){
			if(b[i]==1) nxt[i]=-1;
			else {
				nxt[m]=i;
				m=i;
			}
		}
		for(int i=1;i<=t;i++){
			int x;
			scanf("%d",&x);
			cout<<nxt[x]<<endl;
		}
	}
	return 0;
}

