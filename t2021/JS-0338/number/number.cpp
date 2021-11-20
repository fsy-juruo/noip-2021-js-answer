#include<bits/stdc++.h>
using namespace std;
#define For(i,sta,en) for(int i=sta;i<=en;++i)
const int N=10010,M=10000010;
int T;
bool p[M];
inline int read(){
	int s=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
bool check(int x){
	int a=x%10;
	if(a==7)return true;
	int b=x/10;
	if(b==0)return false;
	return check(b);	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(p,1,sizeof(p));
	For(i,1,M){
		if(!p[i])continue;
		if(check(i)){
			p[i]=0;
			int j=i;
			while(j<M){
				p[j]=0;
				j+=i;				
			}
		}
		else continue;
	}
	T=read();
	while(T>0){
		T--;
		int x=read();
		if(!p[x]){cout<<-1<<endl;continue;}
		x++;
		while(!p[x])x++;
		cout<<x<<endl;
	}
	return 0;
}
