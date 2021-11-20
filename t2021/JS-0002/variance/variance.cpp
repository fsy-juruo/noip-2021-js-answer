#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define mp pair<int,int>
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
int n,b[10000+1],a[10000+1];
vector<unsigned int> dp[2][601];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	if(n==1){
		printf("0\n");
		return 0;
	}
	rb(i,2,n) a[i]-=a[1];
	rb(i,1,n-1) a[i]=a[i+1];
	--n;
	rb(i,1,n) b[i]=a[i]-a[i-1];
	sort(b+1,b+1+n);
	reverse(b+1,b+1+n);
//	rb(i,1,n) cout<<b[i]<<' ';
//	cout<<endl;
	int maxsum=0;
	rb(i,1,n) a[i]=a[i-1]+b[i];
	int mxval=a[n];
	rb(i,1,n) maxsum+=a[i];
	rb(i,0,mxval) dp[0][i]=vector<unsigned int>(maxsum+1,(unsigned int)(4e9));
	dp[0][0][0]=0;
	int tot=0;
	int cnt=0;
	rb(i,1,n){
		rb(j,0,mxval) dp[i&1][j]=vector<unsigned int>(maxsum+1,(unsigned int)(4e9));
		rb(j,0,tot){
			rb(k,0,maxsum){
				if(dp[(i&1)^1][j][k]<4e9){
					unsigned int val=dp[(i&1)^1][j][k];
//					cout<<i-1<<' '<<j<<" "<<k<<" "<<val<<' '<<mxval<<endl;
//					cout<<i<<" "<<++cnt<<endl;
					check_min(dp[i&1][j+b[i]][k+j+b[i]],val+(j+b[i])*(j+b[i]));
					int bk=tot-j;
					check_min(dp[i&1][j][k+a[n]-bk],val+(a[n]-bk)*(a[n]-bk));
				}
			}
		}
		tot+=b[i];
	}
	long long answer=1e18;
	rb(j,0,tot){
		rb(k,0,maxsum){
			long long tmp=dp[n&1][j][k];
			check_min(answer,-1ll*k*k+tmp*(n+1));
		}
	}
	cout<<answer<<endl;
	return 0;
}
