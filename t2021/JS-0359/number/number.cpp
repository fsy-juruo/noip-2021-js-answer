#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
#define FIO "number"
#define ll long long
int cnt;
int read(){
	char c=getchar();int x=0;
	while(c!=' '&&c!='\n'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
bool check7(int x){
	while(x){
		if(x%10==7) return true;
		x/=10;
	}
}
bool check(int x){
	if(check7(x)) return true;
	for(int i=1;i<=sqrt(x);i++) if(x%i==0){
		if(check7(i)) return true;
		if(check7(x/i)) return true;
	}
}
int main(){
	freopen(FIO".in","r",stdin);
	freopen(FIO".out","w",stdout);
	int t;
	t=read();
	for(int k=1;k<=t;k++){
		int x;
		x=read();
		if(check(x)) cout<<-1<<endl;
		else{
			x++;
			while(check(x)){
				x++;
			}
			write(x);
			putchar('\n');
		}
	}
	return 0;
}









