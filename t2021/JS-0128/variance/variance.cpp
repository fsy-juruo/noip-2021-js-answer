#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
int n;
int a[10010];int d[10010];int t[10010];
int b[10010];int c[10010];
deque<int>v;
long long sol(){
	long long val=0;long long sum=0;
	rep(i,1,n)sum+=c[i];
	sum/=n;
	rep(i,1,n)val+=1ll*(sum-c[i])*(sum-c[i]);
	val/=n;
	return val;
}
int t1[10010];int t2[10010];
bool Okay(double x,double y){
	if(x<=0)return true;
	return rand()<=exp((-x)/y)*RAND_MAX*2;
}
long long SA(){
	double T=400000;
	rep(i,1,n-1)t1[i]=i;
	random_shuffle(t1+1,t1+n);
	rep(i,1,n-1)t2[i]=t1[i];
	rep(i,0,n-1)c[i+1]=c[i]+d[t1[i]+1];
	long long nop1=sol();long long nop2=nop1;
	long long ret=nop1;
	while(T>0.01){
		int x=rand()%(n-1)+1;int y=rand()%(n-1)+1;
		while(x==y)y=rand()%(n-1)+1;
		swap(t2[x],t2[y]);
		rep(i,0,n-1)c[i+1]=c[i]+d[t2[i]+1];
		nop2=sol();chkmin(ret,nop2);
		if(Okay(nop2-nop1,T)){swap(t1[x],t1[y]);nop1=nop2;}
		else{swap(t2[x],t2[y]);}
		T*=0.9999;
	}
	return ret;
}
int dp[10010][610];bool vis[10010];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	srand(time(NULL));
	read(n);
	rep(i,1,n){read(a[i]);d[i]=a[i]-a[i-1];d[i]*=n;}
	
	long long ans=1e18;
	if(n<=10){
		rep(i,1,n)t[i]=i;
		do{
			rep(i,1,n)c[i]=c[i-1]+d[t[i]];
			if(t[1]==1)chkmin(ans,sol());
		}while(next_permutation(t+1,t+n+1));
		write(ans);
	}else{
		rep(i,2,n)c[i-1]=d[i];
		sort(c+1,c+n);
		for(int i=1;i<n;i+=2){
			if((i/2)%2==0){
				v.push_back(c[i]);
				if(i+1<n)v.push_back(c[i+1]);
			}else{
				v.push_front(c[i]);
				if(i+1<n)v.push_front(c[i+1]);
			}
		}
		v.push_front(d[1]);
		rep(i,1,n)c[i]=c[i-1]+v[i-1];
		chkmin(ans,sol());
		
		v.clear();
		rep(i,2,n)c[i-1]=d[i];
		sort(c+1,c+n);
		for(int i=1;i<n;i+=2){
			if((i/2)%2==0){
				v.push_front(c[i]);
				if(i+1<n)v.push_front(c[i+1]);
			}else{
				v.push_back(c[i]);
				if(i+1<n)v.push_back(c[i+1]);
			}
		}
		v.push_front(d[1]);
		rep(i,1,n)c[i]=c[i-1]+v[i-1];
		chkmin(ans,sol());
		
		rep(i,2,n)b[i]=d[i];
		sort(b+2,b+n+1);
		rep(i,2,min(n,40)){
			rep(j,i+1,min(n,40)){
				v.clear();
				rep(k,2,i)v.push_back(b[k]);
				rep(k,i+1,j)v.push_front(b[k]);
				rep(k,j+1,n){
					if((k-j-1)&1){v.push_front(b[k]);}
					else{v.push_back(b[k]);}
				}
				v.push_front(d[1]);
				rep(k,1,n)c[k]=c[k-1]+v[k-1];
				chkmin(ans,sol());
			}
		}
		
		if(n<=400){
			rep(i,1,4)chkmin(ans,SA());
		}
		rep(i,2,n)b[i-1]=d[i]/n;
		sort(b+1,b+n);
		dp[0][0]=1;
		rep(i,1,n-1){
			rep(j,0,a[n])dp[i][j]=dp[i-1][j];
			rep(j,b[i],a[n])dp[i][j]|=dp[i-1][j-b[i]];
		}
		rep(i,1,a[n]){
			if(!dp[n-1][i])continue;
			rep(j,1,n-1)vis[j]=0;
			v.clear();
			int sum=i;
			rep2(j,n-1,1){
				if(b[j]<=sum&&dp[j][sum]!=0&&dp[j-1][sum-b[j]]!=0){
					vis[j]=1;v.push_front(b[j]*n);
					sum-=b[j];
				}
			}
			rep(j,1,n-1){
				if(vis[j])continue;
				v.push_front(b[j]*n);
			}
			v.push_front(d[1]);
			rep(j,0,n-1)c[j+1]=c[j]+v[j];
			chkmin(ans,sol());
		}
		write(ans);
	}
	return 0;
}
/*
252100
305460375
*/
