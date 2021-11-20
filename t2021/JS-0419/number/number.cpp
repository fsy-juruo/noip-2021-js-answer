#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fr first
#define se second
#define pb push_back()
#define is insert()
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e7+20;
int T,n,m,f[MAXN],cnt,nxt[MAXN];
int p[MAXN];
int check(int num){
	while(num){
		if(num%10==7)return 1;
		num/=10;
	}
	return 0;
}
void Read(int& num){
	char ch;
	while((ch=getchar()) && !isdigit(ch));
	num=ch-'0';
	while((ch=getchar()) && isdigit(ch))num=num*10+ch-'0';
}
void output(int num){
	if(num>=10)output(num/10);
	putchar('0'+(num%10));
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	m=1e7+10;
	rep(i,1,m){f[i]|=check(i);}
	rep(i,2,m){
		if(!p[i]){
			rep(j,2,m){
				if(i*j>m)break;
				if(f[i] || f[j])f[i*j]=1;
				p[i*j]=1;
			}
		}
	}
	nxt[m]=m;
	per(i,m-1,1){
		if(!f[i])nxt[i]=i;
		else nxt[i]=nxt[i+1];
	}
	Read(T);
	while(T--){
		Read(n);
		if(f[n]==1){
			putchar('-');putchar('1');putchar('\n');
		}else{
			output(nxt[n+1]);putchar('\n');
		}
	}
	
	return 0;
}
/*
1
9389
*/
