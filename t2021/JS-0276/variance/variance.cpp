#include <iostream>
#include <queue>

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

int n;

struct aa {
	int *a;
};

queue<aa> q;

long long va(aa av) {
	long long ass=0,sa=0;
	for(int i=1; i<=n; i++)
		ass+=av.a[i]*av.a[i],sa+=av.a[i];
	return n*ass-sa*sa;
}

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	aa av;
	av.a=new int[n+1];
	for(int i=1; i<=n; i++)
		av.a[i]=read();
	q.push(av);
	long long mi=va(av);
	while(q.size()) {
		aa av=q.front();
		q.pop();
		for(int k=2; k<n; k++) {
			aa av2;
			av2.a=new int[n];
			for(int i=1; i<=n; i++)
				av2.a[i]=av.a[i];
			av2.a[k]=av2.a[k-1]+av2.a[k+1]-av2.a[k];
			if(va(av2)<=mi)
				q.push(av2);
			mi=min(mi,va(av2));
		}
	}
	write(mi);
	return 0;
}
