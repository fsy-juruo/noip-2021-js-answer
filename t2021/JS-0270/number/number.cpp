#include<bits/stdc++.h>
using namespace std;

short a[10000010];
bool b[10000010];
void workk(int n){
	if(n>=40000) return;
	if(a[n]==-1||b[n]) workk(n+1);
	else{
		bool f=false;int k=n;
		while(k>0){
			if(k%10==7) f=true;
			k/=10;
		}
		if(f){
			a[n]=-1;
			for(int i=2;n*i<=40000;i++)
				a[n*i]=-1,b[n*i]=true;
		}
		b[n]=true;
		workk(n+1);
	}
	return;
}

int t,x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	workk(7);
	scanf("%d",&t);
	for(;t;--t){
		scanf("%d",&x);
		if(a[x]==-1) printf("-1\n");
		else{
			int k=x+1;
			while(a[k]==-1) k++;
			printf("%d\n",k);
		}
	}
	return 0;
}

