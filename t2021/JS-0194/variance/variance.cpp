#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define dg() printf("114514\n")
int read() { 
	int s=0,w=1; char ch=getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w=-1; ch=getchar();}
	while(ch <= '9' && ch >= '0') s=s*10+ch-'0',ch=getchar();
	return s*w; 
} 
const int N=10010;
const int cnt=10000;
const int Inf=0x3f3f3f3f;
int n,a[N],b[N];
LL sum1,sum2,ans; 
void solve() {
	int delta=0,add=0; 
	for(int js=1;js<=cnt;js++) { 
		delta=Inf;
		int k=0;
		for(int i=2;i<n;i++) { 
			add=a[i+1]+a[i-1]-a[i]*2; 
		    int xxx=2*add*(n*a[i]-sum2)+(n-1)*add*add; 
		    if(delta > xxx) { 
		    	delta=xxx; k=i;    
			} 
		} 
		//printf("%d %d \n",ans+delta,k);
		if(delta >= 0) return;
		ans=min(ans,ans+delta);
		sum2=sum2-a[k]+a[k+1]+a[k-1]-a[k];
		a[k]=a[k+1]+a[k-1]-a[k];
	} 
} 
int main() { 
	freopen("variance.in","r",stdin);   
	freopen("variance.out","w",stdout); 
	n=read();        
	for(int i=1;i<=n;i++) a[i]=read(); 
	for(int i=1;i<=n;i++) {  
		sum1+=a[i]*a[i];
		sum2+=a[i]; 
		b[i]=a[i];  
	} 
	
	ans=n*sum1-sum2*sum2;
	
	if(n == 2) { 
		printf("%lld ",ans); 
		return 0; 
	} 
	//dfs(1);
	solve(); 
	printf("%lld\n",ans); 
	return 0;
} 
/*
4
1 2 4 6

10                            
6 19 34 35 56 63 82 82 83 99  

*/

//f[N][2];
/*void dfs(int x) {
	ans=min(ans,sum1*(LL)n-sum2*sum2);
	//printf("%lld %lld\n",sum1,sum2);
	//for(int i=1;i<=n;i++) printf("%d ",b[i]); printf("\n");
	if(x == 5) return; //1 3 4 6
	int add1=b[1]+b[3]-b[2]*2,add2=b[n]+b[n-2]-b[n-1]*2,xx1=b[2],xx2=b[n-1];
	//printf("%d ",add1);
	b[2]+=add1;
	sum1=sum1-xx1*xx1+b[2]*b[2];
	sum2=sum2-xx1+b[2];
	dfs(x+1);
	sum1=sum1+xx1*xx1-b[2]*b[2];
	sum2=sum2+xx1-b[2];
	b[2]-=add1;
	
	b[n-1]+=add2;
	sum1=sum1-xx2*xx2+b[n-1]*b[n-1];
	sum2=sum2-xx2+b[n-1];
	dfs(x+1);
	sum1=sum1+xx2*xx2-b[n-1]*b[n-1];
	sum2=sum2+xx2-b[n-1];
	b[n-1]-=add2;	
} */

	//for(int js=1;js<=cnt;js++) {
		//int add1=(a[i])
	//}
	/*for(int i=1;i<=n;i++) f[i][0]=ans;
	for(int js=1;js<=cnt;js++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				f[i][js&1]=min(f[i][js&1],f[j][(js+1)&1])
			}
		}
	}*/
