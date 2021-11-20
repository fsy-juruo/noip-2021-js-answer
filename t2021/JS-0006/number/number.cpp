#include<bits/stdc++.h>
using namespace std;
const int N=10100000;
int T,pri[11000000],nex[11000000],nn;
bool a[11000000];
namespace FIFO{
//char buf[1<<23],*p1=buf,*p2=buf;
//#define gc() (p1==p2&&(p2=buf+fread(p1=buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define gc() getchar()
void read(int&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
void print(int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
void sieve(){
	for(int i=2;i<=N;i++){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			pri[i*pri[j]]=true;
			if(!(pri[j]%i))break;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T),sieve();
	for(int i=1;i<=N;i++)for(int j=i;j;j/=10)if(j%10==7)a[i]=true;
	for(int i=1;i<=pri[0];i++)for(int j=1;j*pri[i]<=N;j++)a[j*pri[i]]|=a[j];
	nn=-1;
	for(int i=N;i;i--){
		nex[i]=nn;
		if(!a[i])nn=i;
	}
	for(int n;T--;){
		read(n);
		if(a[n])putchar('-'),putchar('1');
		else print(nex[n]);
		putchar('\n');
	}
	return 0;
}
