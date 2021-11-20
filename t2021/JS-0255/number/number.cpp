#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n[MAXN];

bool right7(int num){
	if(num%7==0){
		return false;
	}
	while (num>0){
		int y=num%10;
		if(y==7){
			return false;
		}
		num/=10;
	}
	return true;
}

int init7(int ni){
	int id=0;
	for(int i=7;i<=ni+5;i++){
		for(int j=1;j<=10005;j++){
			if(j>i/2){
				break;
			}
			if(i%j==0){
				if(right7(i/j)==false){
					n[id++]=i;
					break;
				}
			}
		}
	}
	return id;
}

int number(int z,int mode,int idn){
	if(mode==1){
	int ans=z;
	int id=0;
	if(right7(z)==false){
		return -1;
	}
	for(int i=0;i<idn;i++){
		if(z==n[i]){
			return -1;
		}
		if(z<=n[i]){
			id=i;
			break;
		}
	}
	bool flag=true;
	while(true){
		ans+=1;
		flag=true;
		if(n[id]==ans){
			id+=1;
			flag=false;
		}
		if(right7(ans)==true&&flag){
			break;
		}
	}
	return ans;
}
else{
		if(right7(z)==false){
		return -1;
	}
	int ans=z;
	while(right7(ans)==false){
		ans+=1;
	}
	return ans;
}}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	int ni=2e5;
	if(t<=10){
		ni=100;
	}
	else if(t<=100){
		ni=1000;
	}
	else if(t<=1000){
		ni=10000;
	}
	int id=init7(ni);
	for(int i = 0;i<t;i++){
		int z;
		scanf("%d",&z);
		if(z<=2e5)
		{
			printf("%d\n",number(z,1,id));
		}
		else
		{
			printf("%d\n",number(z,2,id));
		}
	}
	return 0;
}
