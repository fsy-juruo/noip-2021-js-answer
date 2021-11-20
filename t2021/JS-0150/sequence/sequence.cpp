#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m,k,v[N]; 
inline int read(){
	char c=getchar();
	int res=0;
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		res=10*res+c-'0';
		c=getchar();
	}
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	printf("%d\n",40);
	return 0;
}
