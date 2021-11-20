#include<bits/stdc++.h>
using namespace std;
const int N=10000050;
int t,r[N],maxx;
bool p[N*2];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%d",&r[i]);
		maxx=max(maxx,r[i]);
	}
	for(int i=1;i<=maxx*2;i++){
		int m=i;
		if(!p[i])while(m){
			if(m%10==7){
				p[i]=true;
				for(int j=2;j*i<=maxx*2;j++){
					p[i*j]=true;
				}
				break;
			}
			m/=10;
		}
	}
	for(int i=1;i<=t;i++){
		if(p[r[i]])cout<<"-1"<<endl;
		else {
			int j=1;
			while(p[r[i]+j]==true)j++;
			printf("%d\n",r[i]+j);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
