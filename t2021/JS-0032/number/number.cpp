#include<iostream>
#include<cstdio>
int nk[10000015]={0},tmp,fl;
int nxt[10000015]={0};
int T,x;
int read()
{
	int res=0,pn=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') pn=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<3)+int(c-48);
		c=getchar();
	}
	return res*pn;
}
void write(int tx)
{
	if(tx<0){
		putchar('-');
		write(-tx);
	}
	else if(tx==0){
		return;
	}
	else{
		write(tx/10);
		putchar((char)('0'+tx%10));
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1e7+10;++i){
		if(nk[i]) continue;
		tmp=i;
		fl=0;
		while(tmp){
			if(tmp%10==7){
				fl=1;
				break;
			}
			tmp/=10;
		}
		if(fl){
			for(int j=i;j<=1e7+10;j+=i){
				nk[j]=1;
			}
		}
	}
	for(int i=1e7+9;i>=1;--i){
		if(!nk[i+1]) nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	T=read();
//	scanf("%d",&T);
	while(T--){
		x=read();
//		scanf("%d",&x);
		if(nk[x]){
			write(-1);
			putchar('\n');
//			printf("-1\n");
		}
		else{
			write(nxt[x]);
			putchar('\n');
//			printf("%d\n",nxt[x]);
		}
	}
}
