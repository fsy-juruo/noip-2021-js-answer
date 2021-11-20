//by jr GYF
#include<bits/stdc++.h>
using namespace std;
int t,x;
int a[200005];
int h[200005];
int fr,rr;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(h,0,sizeof(h));
	a[1]=7;
	fr=1;rr=1;
	int num=1;
	while(a[rr]<=20005){
		num*=10;
		for(int i=1;i<num;i++){
			if(i==7){
				for(int j=0;j<num;j++){
					a[++rr]=num*i+j;
				}
				i++;
			}
			int j=1;
			while(a[j]<=num){
				a[++rr]=a[j]+num*i;
				j++;
			}
		}
		fr++;
	}
	for(int i=1;i<=5005;i++){
		for(int j=1;j<=10;j++){
			int xx=a[i]*j;
			//cout<<xx<<endl;
			h[xx]=1;
		}
	}
	for(int i=1;i<=28572;i++) h[7*i]=1;
	cin>>t;
	//for(int i=1;i<=5000;i++) if(h[i]==1) cout<<i<<endl;
	while(t--){
		cin>>x;
		if(h[x]==1) cout<<-1<<endl;
		else if(h[x]!=1){
			//cout<<h[x];
			int l=x+1;
			while(h[l]==1) l++;
				cout<<l<<endl;
			}
			
		}
	return 0;
}
