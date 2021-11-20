#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define mp pair<int,int>
using namespace std;
const int MAXN=1e7+1;
bool p[MAXN+1];
int nex[MAXN+2];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rb(i,1,MAXN){
		if(!p[i]){
			int tmp=i;
			while(tmp){
				if(tmp%10==7){
					p[i]=1;
					break;
				}
				tmp/=10;
			}
			if(p[i]){
				for(int j=i+i;j<=MAXN;j+=i) p[j]=1;
			}
		}
	}
	rl(i,MAXN,1){
		if(p[i]==0) nex[i]=i;
		else nex[i]=nex[i+1];	
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		if(p[x]) printf("%d\n",-1);
		else printf("%d\n",nex[x+1]);
	}
	return 0;
}
