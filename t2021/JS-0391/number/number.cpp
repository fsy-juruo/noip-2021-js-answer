#include<bits/stdc++.h>
using namespace std;
int n,T,a[200086],b[200086];
int che(int nw){
	while(nw>0){
		if(nw%10==7) return 2;
		nw/=10;
	}
	return 0;
}
int f(int nw){
	if(b[nw]) return -1;
	for(int i=nw+1;i<=10000+nw;i++){
		if(!b[i]) return i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=1;i<=10000;i++){
		if(!b[i]) b[i]=che(i);
		if(b[i]==2){
			//printf("%d\n",i);
			for(int j=2*i;j<=10000+i;j+=i){
				b[j]=1;
			}
		}
	}
	scanf("%d",&T);
	for(int i=1;i<=10000;i++){
		a[i]=f(i);
	}
	
	while(T>0){
		T--;
		scanf("%d",&n);
		printf("%d\n",a[n]);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

