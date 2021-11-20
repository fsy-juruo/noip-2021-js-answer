#include<bits/stdc++.h>
#define LL long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define DF(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define mp make_pair
using namespace std;
int read(){
	char ch=getchar();int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
mt19937 rnd(time(0));
const int M=1e4+10,inf=1e9;
int n,a[M],d[M];
namespace BF{
	int p[M],b[M],ans=inf;
	void solve(){
		F(i,1,n-1) p[i]=i;
		do{
			int ts=0;
			F(i,2,n) b[i]=b[i-1]+d[p[i-1]],ts+=(n-i+1)*d[p[i-1]];
			int var=0,sm=0;
			F(i,1,n){
//				sm+=b[i];
				sm+=(n-i+1)*(d[p[i-1]]);
				var+=n*b[i]*b[i];
			}
			var-=sm*sm;
			ans=min(var,ans);
		}
		while (next_permutation(p+1,p+n));
		
		F(i,1,n-1) p[i]=i;
		
		do{
			F(i,2,n) b[i]=b[i-1]+d[p[i-1]];
			int var=0,sm=0;
			F(i,1,n){
//				sm+=b[i];
				sm+=(n-i+1)*(d[p[i-1]]);
				var+=n*b[i]*b[i];
			}
			var-=sm*sm;
			if (var==ans){
				F(i,1,n-1){
					cout<<d[p[i]]<<" ";
				}
				cout<<"  delta\n";
				bool fl=1;
				F(i,2,n-1){
					
					if (d[p[i]]>d[p[i-1]]){
						fl=0;
					}
					else{
						if (d[p[i]]<d[p[i-1]]) assert(fl==1);
					}
				}
				cerr<<" OK \n";
			}
		}
		while (next_permutation(p+1,p+n));
		
		
		cout<<ans<<"\n";
	}
	void test(){
		while (1){
			ans=inf;
			F(i,1,n-1) d[i]=rnd()%20;
			solve();
		}
	}
}
namespace Smart{
	const int M=5e5+10;
	int dp[2][M],ct[M];
	int s2(int x){
		return x*(x+1)*(2*x+1)/6;
	}
	int s1(int l,int r){
		return (l+r)*(r-l+1)/2;
	}
	//dp : minimum ( sum a[i]^2 )
	void solve(){
		F(i,1,n-1) ct[d[i]]++;
		int nd=0,sd=0,lim=0;
		int now=1,pre=0;
		ms(dp,60);
		dp[now][0]=0; nd=ct[0];
		F(i,1,600){
			if (ct[i]){
				swap(now,pre);
				ms(dp[now],60);
				F(j,0,lim){//j=sum a[i]
					if (dp[pre][j]<inf){
						F(k,0,ct[i]){//k front , ct[i]-k back
							
							int pd=k*i;
							int del=2*j*pd+pd*pd*nd;//mid
							del+=s2(k)*i*i;//front
							int sn=pd+sd,bn=ct[i]-k;
							del+=sn*sn*bn+s2(bn)*i*i+2*sn*i*s1(1,bn);
							
							int nj=j+s1(1,k)*i+pd*nd+sn*bn+s1(1,bn)*i;
//							cerr<<" tot num : "<<nd<<" a[nd]="<<sd<<" sum a[i]^2 = "<<dp[pre][j]<<" sum a[i]= "<<j<<" "<<" add "<<i<<" pre "<<k<<" suf "<<bn<<"\n";
//							cerr<<" sum a[i]^2 = "<<dp[pre][j]+del<<" sum a[i]= "<<nj<<"  after\n\n";
							//     org + pre + mid + suf
							
							//+(i^2+(2i)^2)
							//+(sd+i)^2+(sd+2i)^2
							
							dp[now][nj]=min(dp[now][nj],dp[pre][j]+del);
						} 
					}
				}
				
				//sd : cur last
				F(j,1,ct[i]){
					nd++;
					lim+=nd*i;
					sd+=i;
				}
//				cerr<<lim<<"\n";
			}
		}
		LL ans=1ll*inf*inf;
		F(i,0,lim){
			if (dp[now][i]<=inf){
				ans=min(ans,1ll*dp[now][i]*n-1ll*i*i);
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
//	BF::test();
	F(i,1,n) a[i]=read(),d[i-1]=a[i]-a[i-1];
	d[0]=0;
//	if (n<=11){
//		BF::solve();
//		return 0;
//	}
	Smart::solve();
	return 0;
}
/*

*/

