#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
const int MAXM=1e7+5;

int t,x[MAXN],mx;
int p[MAXM];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	memset(p,0,sizeof(p));
	for(int i=1;i<=t;i++){
		scanf("%d",&x[i]);
		mx=max(mx,x[i]);
	}
	for(int i=1;i<=mx*2;i++){
		int k=i,q=0;
		while(k!=0){
			q=k%10;
			if(q==7){
				p[i]=1;
//				printf("%d:%d ",i,p[i]);
				break;
			}
			else  k/=10;
		}
	}
	int j=1;
	for(int i=1;i<=mx*2;i++){
		if(p[i]==1){
//			printf("%d ",i);
			while(i*j<=mx){
				p[i*j]=1;
//				printf("%d ",i*j);
				j++;
			}
			j=1;
		}
	}
//	for(int i=1;i<=mx;i++)  printf("%d:%d ",i,p[i]);
	for(int i=1;i<=t;i++){
		if(p[x[i]]==1)  printf("-1\n");
		else{
			int k=x[i]+1;
			while(p[k]!=0)  k++;
			printf("%d\n",k);
		}
	}
	return 0;
}
/*
4
6
33
69
300

5
90
99
106
114
169
*/
