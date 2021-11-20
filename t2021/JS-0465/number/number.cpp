#include<bits/stdc++.h>
using namespace std;
int t,x,ans;
bool p[20000005],p2[20000005];
int read(){
	char c=' ';
	int x=0,y=1;
	while(c==' '||c=='\n')c=getchar();
	while(c!=' '&&c!='\n'){
		if(c!='-')x=x*10+c-'0';
		else y=-1;
		c=getchar();
	}
	return x*y;
}
void put(int x,char y){
	string s="";
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x!=0){
		s=s+char(x%10+'0');
		x/=10;
	}
	for(int i=s.size()-1;i>=0;i--){
		putchar(s[i]);
	}
	putchar(y);
}
void doi(int i){
	int b=i;
	while(b!=0){
		if(b%10==7){
			p2[i]=1;
			p[i]=1;
			return;
		}
		b/=10;
	}
}
bool check(int x){
	if(p2[x])return p[x];
	if(x%7==0||p[x]){
		p[x]=1;
		p2[x]=1;
		return 1;	
	}
	for(int i=1;i*i<=x;i++){
		if(x%i!=0)continue;
		if(!p2[i]){
			doi(i);
		}
		if(!p2[x/i]){
			doi(x/i);
		}
		if(p[i]){
			p2[x]=1;
			p[x]=1;
			return 1;
		}
		if(p[x/i]){
			p2[x]=1;
			p[x]=1;
			return 1;
		}
	}
	p2[x]=1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
//	for(int i=1;i<=1e6;i++){
//		if(check(i)){
//			p[i]=1;
//		}
////		cout<<i<<' '<<p[i]<<'\n'; 
//	}
	while(t--){
		x=read();
		if(check(x)){
			ans=-1;
			put(ans,'\n');
			continue;
		}
		x++;
		while(check(x)){
			x++;
		}
		put(x,'\n');
	}
	return 0;
}

