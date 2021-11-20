#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=(ch=='-');
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

inline void write(int _x){
	if(_x/10>0) write(_x/10);
	putchar(_x%10+'0');
}
inline void writeln(int _x){
	if(_x<0){
		putchar('-');
		_x=-_x;
	}
	write(_x);
	putchar('\n');
}

const int X=1e6+5;

int T,x;
int f[X];

bool have_7(int _a){
	int s;
	while(_a){
		s=_a%10;
		_a/=10;
		if(s==7) return true;
	}
	return false;
}
void pre_f(){
	memset(f,true,sizeof(f));
	for(int i=1; i<X; i++)
		if(have_7(i)||!f[i]) for(int j=1; i*j<X; j++)
			f[i*j]=false;
}

bool judge(){
	
}

int main(){
//	freopen("in.txt","r",stdin);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	pre_f();
	
	cin>>T;
	while(T--){
		x=read();
		
		if(x<X){
			if(!f[x]){
				writeln(-1);
				continue ;
			}
			for(int i=x+1; ; i++){
				if(f[i]){
					writeln(i);
					break;
				}
			}
			continue ;
		}
		
//		if(!judge(x)){
//			cout<<"-1\n";
//			continue ;
//		}
		
		cout<<"-1\n";
		
	}
	
	return 0;
}

