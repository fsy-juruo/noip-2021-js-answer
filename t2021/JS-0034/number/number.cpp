#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	char ch=getchar();
	int res=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res;
} 
inline void pr(int res){
	if(res==0){
		putchar('0');
		return;
	}
	int a[10],len=0;
	while(res>0){
		a[len++]=res%10;
		res/=10;
	}
	for(int i=len-1;i>=0;i--)
		putchar(a[i]+'0');
}
int t;
int n;
bool ok[10000010];
int nxt[10000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(ok,true,sizeof(ok));
	for(int i=1;i<=10000000;i++){
		int tmp=i;
		while(tmp>0){
			if(tmp%10==7){
				ok[i]=false;
				break;
			}
			tmp/=10;
		}
	}
	for(int i=1;i<=10000000;i++){
		if(ok[i])continue;
		for(int j=i;j<=10000000;j+=i)ok[j]=false;
	}
	int j=1;
	for(int i=1;i<10000000;i++){
		j=max(j,i+1);
		while(!ok[j])j++;
		nxt[i]=j;
	}
	nxt[10000000]=10000001;
	t=rd();
	while(t--){
		int x=rd();
		if(!ok[x]){
			putchar('-');
			putchar('1');
		}else{
			pr(nxt[x]);
		}
		putchar('\n');
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
/*
4
6
33
69
300
*/
