#include<bits/stdc++.h>
using namespace std;
bool can[10050003];
int nxt[10050003];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<10050003;i++)
		can[i]=1;
	for(int pw=10;pw<=10000000;pw*=10){
		int pw10=pw/10,pw7=pw10*7;
		for(int i=0;i<10050003;i+=pw)
			for(int j=0;j<pw10;j++)
				if(i+j+pw7<10050003)
					can[i+j+pw7]=0;
	}
	for(int i=10050002;i>=0;i--)
		if(!can[i])
			for(int j=i;j<10050003;j+=i)
				can[j]=0;
	int lst=-1;
	for(int i=10050002;i>=0;i--)
		if(can[i])
			nxt[i]=lst,
			lst=i;
	int T,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		if(!can[x])
			printf("-1\n");
		else
			printf("%d\n",nxt[x]);
	}
	return 0;
}
