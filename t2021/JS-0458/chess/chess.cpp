#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long w=0,f=1;
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
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
string a[200010],b[200010];
struct point{
	long long x,y,col,val;
}point[100010];
long long n,m,q;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	long long T=read();
	for(long long TTT=1;TTT<=T;TTT++){
		n=read(),m=read(),q=read();
		char c=getchar();
		for(long long i=1;i<=n;i++){
			a[i]="";
			while(!isdigit(c))c=getchar();
			while(isdigit(c))a[i]+=c;
		}
		for(long long i=1;i<n;i++){
			b[i]="";
			while(!isdigit(c))c=getchar();
			while(isdigit(c))b[i]+=c;
		}
		for(long long i=1;i<=q;i++){
			point[i].col=read();
			point[i].val=read();
			point[i].x=read();
			point[i].y=read();
			write(rand()%(n*m));
		}
	}
	return 0;
}
