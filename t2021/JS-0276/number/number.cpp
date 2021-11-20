#include <iostream>

using namespace std;

long long read() {
	long long x=0,f=1;
	char c;
	while(c=getchar(),c<'0'||c>'9')
		if(c=='-')
			f=-1;
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return x*f;
}

void write(long long x) {
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10|48);
}

const long long INF=10000010;

bool has7(long long x) {
	while(x) {
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int *next=new int[INF+10] {1},*before=new int[INF+10],T=read(),x;
	bool *vis=new bool[INF+10] {};
	for(int i=1; i<=INF+5; i++)
		next[i]=i+1,before[i]=i-1;
	for(int i=1; i<INF; i=next[i])
		if(has7(i))
			for(int j=i; j<INF; j+=i)
				if(!vis[j])
					vis[j]=true,next[before[j]]=next[j],before[next[j]]=before[j];
	while(T--) {
		x=read();
		write(vis[x]?-1:next[x]);
		putchar('\n');
	}
	return 0;
}
