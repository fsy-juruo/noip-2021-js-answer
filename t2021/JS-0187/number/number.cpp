#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=200000;i++){
		int tmp=i;
		while(tmp){
			if(tmp%10==7){
				s.insert(i);
				for(int j=2;i*j<=200000;j++){
					s.insert(i*j);
				}
				break;
			}
			tmp/=10;
		}
	}
	int T;
	scanf("%d",&T);
	int tmp;
	for(int i=1;i<=T;i++){
		scanf("%d",&tmp);
		if(s.find(tmp)!=s.end()){
			printf("-1\n");
		}
		else{
			tmp++;
			while(s.find(tmp)!=s.end())tmp++;
			printf("%d\n",tmp);
		}
	}
	return 0;
}
