#include<bits/stdc++.h>
using namespace std;
int T,x; 
int ok[10001000];
char c;
void qrd(){
	x=0;
	c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}
void solve(){
	qrd();
	printf("%d\n",ok[x]);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=1;i<=10000000;i++) ok[i]=1;
    for(int i=1;i<=10000000;i++) if(ok[i]){
    	if(i%7==0){
			ok[i]=0;
			continue;
		}
    	int nok=0,ti;
    	ti=i;
    	while(ti){
    		if(ti%10==7){
    			nok=1;
    			break;
			}
			ti/=10;
		}
		if(nok==1){
			for(int j=i;j<=10000000;j+=i) ok[j]=0;
			continue;
		}
	}
	int lst=10000001;
	for(int i=10000000;i>=1;i--){
		if(!ok[i]) ok[i]=-1;
		else{
			ok[i]=lst;
			lst=i;
		}
	}
	qrd();
	T=x;
    while(T--) solve();
    return 0;
}
