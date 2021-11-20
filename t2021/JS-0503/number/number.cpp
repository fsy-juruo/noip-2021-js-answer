#include<bits/stdc++.h>
using namespace std;
int t,a[200005],k,wes,cf[8];
bool vis[10000005];
void qws(int k){
	int gjl=k;
	while(gjl!=0){
		gjl/=10;
		wes++;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
    	cin >> a[i];
    	k=max(k,a[i]);
	}
	k=min(k+k/2,10000000);
	qws(k);
	for(int i=0;i<=wes;i++){
	cf[i]=1;
	for(int j=1;j<=i;j++)
	cf[i]*=10;
	}
	memset(vis,true,sizeof(vis));
	for(int i=1;i<=wes;i++){
		int cnt=7*cf[i-1];
		for(int j=1;j*cnt<=k;j++){
			for(int q=0;q*cf[i]*j+cnt*j<=k;q++){
				int opt=q*cf[i]*j+cnt*j;
				for(int p=0;p<cf[i-1]&&opt+p*j<=k;p++){
					vis[opt+p*j]=false;
				}
			}
		} 
	}
	for(int i=1;i<=t;i++){
		if(!vis[a[i]])
		cout << "-1" << endl;
		else
		for(int j=a[i]+1;;j++){
			if(vis[j]){
				cout << j << endl;
				break;
			}
		}
	}
	return 0;
}
