#include <bits/stdc++.h>
using namespace std;

bool ok1(int x){
	while(x>0){
		if(x%10==7) return 0;
		x/=10;
	}
	return 1;
}

bool ok2(int x){
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			if(!ok1(i)||!ok1(x/i)) return 0;
		}
	}
	return 1;
}

int T,k,x;

int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
    scanf("%d",&T);
    for(k=1;k<=T;k++){
    	scanf("%d",&x);
    	if(!ok2(x)) cout<<-1<<endl;
    	else{
    		for(int i=x+1;;i++){
    			if(ok2(i)){
    				cout<<i<<endl;
    				break;
				}
			}
		}
	}
	
	
	return 0;
}
