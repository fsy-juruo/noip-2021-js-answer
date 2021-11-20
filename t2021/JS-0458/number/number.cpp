#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		w=(w<<3)+(w<<1)+c-48;
		c=getchar();
	}
	return w*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
bool x[10000003];
int ans[10000003];
bool include7(int p){
	while(p!=0){
		if(p%10==7)return true;
		p/=10;
	}
	return false;
}
void deletee(int p){
	for(int i=1;i<=10000001/p;i++)x[i*p]=false;
}
void check(){
	for(int i=7;i<=10000001;i++){
		if(x[i]==false)continue;
		if(include7(i))deletee(i);
	}
}
void make_out_ans(){
	int p=10000001;
	for(int i=10000000;i>=0;i--){
		if(x[i+1]==true)p=i+1;
		ans[i]=p;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(x,true,sizeof(x));
	check();
	make_out_ans();
	int T=read(),a;
	for(int TTT=1;TTT<=T;TTT++){
		a=read();
		if(x[a]==false)puts("-1");
		else{
			write(ans[a]);
			putchar('\n');
		}
	}
	return 0;
}

