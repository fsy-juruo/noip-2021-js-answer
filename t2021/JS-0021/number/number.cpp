#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
bool Mbe;
//func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func
namespace fastio{
char buf_[1<<23],*st_=buf_,*ed_=buf_,wbuf_[1<<23],*wed_=wbuf_; 
//#define getchar() (st_==ed_&&(ed_=(st_=buf_)+fread(buf_,1,1<<22,stdin),st_==ed_)?EOF:*st_++) 
//#define putchar(x) (*wed_++=(x))
void putchar_final(){
	#ifdef putchar
	fwrite(wbuf_,1,wed_-wbuf_,stdout);
	wed_=wbuf_;
	#endif
}
void read(int &x){
	x=0;char c=getchar();bool ne=false;
	while(!isdigit(c))ne|=c=='-',c=getchar();
	while(isdigit(c))x=10*x+(c^48),c=getchar(); 
	if(ne)x=-x;
}
void prt(int x){
	x<0&&(putchar('-'),x=-x);
	x>9&&(prt(x/10),0);
	putchar(x%10^48);
}
}using fastio::putchar_final;using fastio::read;using fastio::prt;
const int N=1e7+1000;
bool ok[N];
int nxt[N];
//main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main
bool Med;
signed main(){
	fprintf(stderr,"size: %.3lfMB\n",1.*(&Mbe-&Med)/(1<<20));
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	for(int i=1;i<N;i++)ok[i]=true;
	for(int i=1;i<N;i++)if(!(i%10!=7&&i/10%10!=7&&i/100%10!=7&&i/1000%10!=7&&i/10000%10!=7&&i/100000%10!=7&&i/1000000%10!=7))
		for(int j=i;j<N;j+=i)ok[j]=false;
	for(int i=N-1;i;i--)nxt[i]=ok[i]?i:nxt[i+1];
	int qu;
	read(qu);
	while(qu--){
		int x;
		read(x);
		if(!ok[x])putchar('-'),putchar('1'),putchar('\n');
		else prt(nxt[x+1]),putchar('\n'); 
	} 
	return putchar_final(),0;
}
