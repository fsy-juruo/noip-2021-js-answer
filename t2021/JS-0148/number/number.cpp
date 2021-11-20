#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
	return s*f;
}
int T,x,t,s,ans[20000001];
bool Hash[20000001];
bool P(int x){
	while(x>0){
		int y=x%10;
		if(y==7)return 1;
		x/=10;
	}
	return 0;
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void writeln(int x){
	write(x);
	puts("");
}
int main(){
int N;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
T=read();
if(T<=10000)N=300050;
else N=10100000;
for(int i=1;i<=N;i++){
	if(P(i)==1){
		t=i;
		while(t<N){
			Hash[t]=1;
			t+=i;
		}
	}
}
s=0;
for(int i=N;i>=1;i--){
	if(Hash[i-1]==0)ans[i-1]=s,s=0;
	if(Hash[i-1]==1)ans[i-1]=s;
	s++;
}
/*
for(int i=1;i<=100;i++){
	cout<<ans[i]<<' ';
}
*/

while(T--){
	x=read();
	if(Hash[x]==1)cout<<-1<<endl;
	else writeln(x+ans[x]);
}
return 0;
}
