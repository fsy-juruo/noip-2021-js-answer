#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template <typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
		x*=f;
	}
	template <typename T>inline void write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}
	template <typename T>inline void writeln(T x){
		write(x);putchar('\n');
	}
	template <typename T>inline void writesp(T x){
		write(x);putchar(' ');
	}
}
using namespace IO;
bool f[10000010];
int a[200002],maxx; 
void mychange(int x){
	for(int i=1;i*x<=maxx+10;++i){
		int tmp=i*x;
		//if(f[tmp])return;
		f[tmp]=1;
	}
}
bool check(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	int n;
	read(n);
	//int m=n;
//	int maxx=0;
	for(int i=1;i<=n;++i){
		read(a[i]);maxx=max(maxx,a[i]);
	}
	
	for(int i=7;i<=maxx+10;++i){
		if(f[i])continue;
		if(check(i)){
			mychange(i);
		}
	}
	
	for(int i=1;i<=n;++i){
		if(f[a[i]]){
			writeln(-1);
		//	p[i]=-1;
			continue;
		}
		int x=a[i]+1;
		while(f[x])++x;
		writeln(x);
		//p[i]=x;
	}
	
	//int j=0; 
//	while(n--){
//		int x;
//		read(x);
//		if(f[x]){
//			writeln(-1);
//		//	a[++j]=-1; 
//			continue;
//		} 
//		++x;
//		while(f[x])++x;
//		writeln(x);
//	//	a[++j]=x;
//	}
	
//	for(int i=1;i<=m;++i){
//		int x;
//		read(x);
//		if(x!=p[i]){
//			cout<<"wrong"<<endl;return 0;	
//		}
//	}
	return 0;
}
