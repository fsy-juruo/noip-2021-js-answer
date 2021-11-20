#include<bits/stdc++.h>
#define fo(x,m) for(i[x]=0;i[x]<=m;i[x]++)
using namespace std;
const int N=1e7;
bool p[N+10];
int num[N+10];
int idx[N+10];
int n,t,cnt,i[10];
inline int conb(){
	int sum=0;
	for(int k=1;k<=7;k++)
		sum=sum*10+i[k];
	return sum;
}
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void write(int x){
	if(x==0) return;
	write(x/10);
	putchar(x%10+'0');
}
inline void prework(){
	fo(1,9)
		fo(2,9)
			fo(3,9)
				fo(4,9)
					fo(5,9)
						fo(6,9)
							fo(7,9)
							if(i[1]==7||i[2]==7||i[3]==7||i[4]==7||i[5]==7||i[6]==7||i[7]==7)
								p[conb()]=1;
									
	for(int k=1;k<=N;k++){
		if(p[k]==0){
			num[++cnt]=k;
			idx[k]=cnt;
			continue;
		}
		for(int j=1;k*j<=N;j++){
			p[k*j]=1;
		} 
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	prework();
	while(t--){
		int x=read();
		if(p[x]){
			putchar('-');
			putchar('1');
		} 
		else{
			write(num[idx[x]+1]);
		}
		putchar('\n');
	}
	return 0;
}
