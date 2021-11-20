#include<bits/stdc++.h>
using namespace std;
int T;
const int MAXN=10000005;
bool shai[MAXN];
inline bool pd(int x){
	if(x<7)return false;
	if(x==7)return true;
	int c;
	while(x){
		c=x%10;
		if(c==7)return true;
		x/=10;
	}
	return false;
}
inline void ini(){
	memset(shai,0,sizeof(shai));
	for(int i=7;i<MAXN;++i){
		if(!shai[i]&&pd(i)){
			shai[i]=1;
			for(int j=i<<1;j<MAXN;j+=i){
				shai[j]=1;
			}
		}
	}
}
inline bool legal(const int& x){
	return !shai[x];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	stringstream ss;
	ini();
	while(T){
		--T;
		int x;
		scanf("%d",&x);
		if(!legal(x))
			ss<<-1<<"\n";
		else{
			for(int i=x+1;i<MAXN;++i)
			{
				if(!shai[i]){
					ss<<i<<"\n";
					break;
				}
			}
		}
	}
	cout<<ss.str();
	return 0;
}


