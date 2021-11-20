#include<bits/stdc++.h>
#define ll long long
#define rep(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
template <typename T> void read(T&x){
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int N=1e7+5e6+5;
bool is_7[N],d7[N];
int T,x,ne[N];
void init(){
	int la=0;
	for(int i=1;i<=N-5;i++){
		if(i%10==7||d7[i/10]){
			d7[i]=1;
			if(!is_7[i]){
				is_7[i]=1;
				for(int j=i;j<=N-5;j+=i){
					is_7[j]=1;
				}
			}
		}
		else if(!is_7[i])ne[la]=i,la=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	read(T);
	while(T--){
		read(x);
		if(is_7[x])puts("-1");
		else printf("%d\n",ne[x]);
	}
	return 0;
}

