#include<bits/stdc++.h>
using namespace std;
template<typename _T>
void read(_T &x){
	int f=1;x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
int main()
{
    freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		int t;
		read(t);
	}
	printf("%d\n",n*n);
	return 0;
}
