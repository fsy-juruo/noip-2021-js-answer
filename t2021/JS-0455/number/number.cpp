#include<bits/stdc++.h>
using namespace std;
int i;
bool check1(int k){
	int sta=1;
	int tmpk=k;
	while(tmpk){
		if(tmpk%10==7){
			i/=sta;
			i++;
			i*=sta;
			return false;
		}
		tmpk/=10;
		sta*=10;
	}
	return true;
}
bool check2(int k){
	while(k){
		if(k%10==7)return false;
		k/=10;
	}
	return true;
}
int fun[10010][3];
void divide(int k){
	memset(fun,0,sizeof(fun));
	for(int i=2;i<=k&&k!=1;i++){
		if(k%i==0){
			fun[0][0]++;
			fun[fun[0][0]][1]=i;
			while(k%i==0){
				fun[fun[0][0]][2]++;
				k/=i;
			}
		}
	}
}
bool ss(int dep,int sum){
	if(dep>fun[0][0])return check2(sum); 
	bool flg=ss(dep+1,sum);
	for(int i=1;i<=fun[dep][2];i++){
		sum*=fun[dep][1];
		flg&=ss(dep+1,sum);
	}
	return flg;
}
bool check3(int k){
	divide(k);
	if(ss(1,1)==false)return false;
	return true;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	
	int x;
	for(int q=1;q<=n;q++){
		cin>>x;
		i=x+1;
		if(check1(x)==false||check3(x)==false){
			cout<<-1<<endl;
			continue;
		}
		while(1){
			if(check1(i)==false)continue;
			if(check3(i)==false){
				i++;
				continue;
			}
			break;
		}
		cout<<i<<endl;
	}
	return 0;
}
