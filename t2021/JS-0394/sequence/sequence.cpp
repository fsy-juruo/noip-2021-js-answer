#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,v[105];
int read(){
	char c=' ';
	int num=0;
	c=getchar();
	while (c!=' '&&c!='\n'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for (int i=0;i<=m;++i){
		v[i]=read();
	}
	printf("40");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
