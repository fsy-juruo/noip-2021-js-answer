#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define pll pair<long long,long long>
#define pb push_back
#define mp make_pair
using namespace std;
template<typename T>inline void read(T &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<typename T>inline void wrt(T x){
	if(x>9)wrt(x/10);
	putchar(x%10+'0');
}
template<typename T>inline void write(T x){
	if(x<0){putchar('-');x=-x;}
	wrt(x);
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
const int MAXN=1e7+30;
bool can[MAXN];
bool check(int x){
	if(x==0)return false;
	if(x%10==7)return true;
	return check(x/10);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1e7+20;i++){
		if(can[i])continue;
		if(check(i)){
			for(int j=i;j<=1e7+20;j+=i){
				can[j]=true;
			}
		}
	}
	int T,x; 
	read(T);
	while(T--){
		read(x);
		if(can[x]){
			puts("-1");
		}
		else{
			for(int i=x+1;i<=1e7+20;i++){
				if(!can[i]){
					writeln(i);
					break;
				}
			}
		}
	}
	return 0;
}
/*
正确文件
bat对拍
输出调试
特判0/-1
YES/NO大小写
*/

