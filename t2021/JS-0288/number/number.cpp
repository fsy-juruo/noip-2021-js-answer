#include<bits/stdc++.h>
using namespace std;
int T,a[200001][2],ma,y[10000001],k[10000001],w[200001],o;
void yay(){
	for(int i=1;i<=ma||o!=0;i++){
		if(y[i]==0){
			if(i==7){
				for(int j=7;j<=ma;j+=7)y[j]=1;
			}else{
				int t=i,ff=0;
				while(t>0){
					if(t%10==7){
						ff=1;
						break;
					}
					t/=10;
				} 
				if(ff){
					for(int j=i;j<=max(ma,i);j+=i)y[j]=1;
				}
			}
		}
		if(y[i]==0&&o!=0){
			for(int j=1;j<=o;j++){
				a[k[w[j]]][2]=i;
				w[j]=0;
			}
			o=0;
		}
		if(k[i]!=0&&y[i]==1){
			a[k[i]][2]=-1;
		}else if(k[i]!=0){
			o++;
			w[o]=i;
		} 
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[i][1];
		k[a[i][1]]=i;
		ma=max(a[i][1],ma);
	}
	yay();
	for(int i=1;i<=T;i++){
		cout<<a[i][2]<<endl;
	}
	return 0;
} 
