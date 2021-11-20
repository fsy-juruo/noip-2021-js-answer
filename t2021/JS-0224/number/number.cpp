#include<bits/stdc++.h>
#define N 10000010
using namespace std;
bool flag[N*2];
int nxt[N*2];
bool p(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int read(){
	int res=0,flag=1;
	char ch;ch=getchar();
	while((ch<'0')||(ch>'9')){
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while((ch>='0')&&(ch<='9')){
		res=(res<<3)+(res<<1)+ch-48;
		ch=getchar();
	}
	return res*flag;
}
void write(int x){
	if(!x)return;
	write(x/10);
	putchar(x%10+48);
}
void print(int x){
	if(x<0){
		putchar('-');
		write(-x);
	}
	else write(x);
	putchar('\n');
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N+100;i++){
		if(p(i)){
			if(flag[i]==1)continue;
			for(int j=1;i*j<=N+100;j++){
				flag[i*j]=1;
			}
		}
	}
	int tmp=N;
	while(flag[tmp])tmp--;
	nxt[tmp]=tmp+1;
	while(flag[nxt[tmp]])nxt[tmp]++;
	int cur=tmp;
	for(int i=tmp-1;i>=1;i--){
		if(flag[i])continue;
		else{
			nxt[i]=cur;
			cur=i;
		}
	}
	int T;cin>>T;
	while(T--){
		int x;x=read();
		if(flag[x]){
			//printf("-1\n");
			print(-1);
		}
		else{
			//printf("%d\n",nxt[x]);
			print(nxt[x]);
		}
	}
	return 0;
}
