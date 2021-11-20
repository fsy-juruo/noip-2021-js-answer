#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
typedef long long ll;
typedef pair<int,int> pii;
inline bool cmax(int &x,int y){if(x<y){x=y;return true;}return false;}
inline bool cmin(ll &x,ll y){if(x>y){x=y;return true;}return false;}
inline int fastin(){int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}return x*f;}

int n;
const int Maxn=1e4+5;
ll a[Maxn],cf[Maxn],b[Maxn],mp[605],maxd,tmp[Maxn];

int p[20];
ll ans=1e17;

vector<int>r1,r2;

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n=fastin();
	for(int i=1;i<=n;i++){
		a[i]=fastin();
		cf[i]=a[i]-a[i-1];
	}
	
	if(n<=10){
		p[1]=1;
		for(int i=2;i<=n;i++)p[i]=i;
		do{
			for(int i=1;i<=n;i++)tmp[i]=cf[p[i]];
	//		cout<<"tmp:";for(int i=1;i<=n;i++)cout<<tmp[i]<<' ';cout<<endl;
			
			ll sum1=0,sum2=0;
			for(int j=1;j<=n;j++){
				b[j]=b[j-1]+tmp[j];
				sum1+=b[j]*b[j];
				sum2+=b[j];
			}
			
//			cout<<"sum1:"<<sum1<<' '<<"sum2:"<<sum2<<endl;
	//		cout<<"b:";for(int i=1;i<=n;i++)cout<<b[i]<<' ';cout<<endl;
			
//			if(cmin(ans,sum1*n-sum2*sum2) ){
//				r1.clear(); r2.clear();
//				for(int i=1;i<=n;i++)r1.push_back(b[i]);
//				for(int i=1;i<=n;i++)r2.push_back(tmp[i]);
//			}
			ans=min(ans,sum1*n-sum2*sum2);
		}while(next_permutation(p+2,p+n+1));
		printf("%lld\n",ans);
		
//		for(int i=1;i<=n;i++)cout<<r1[i-1]<<' ';cout<<endl;
//		for(int i=1;i<=n;i++)cout<<r2[i-1]<<' ';cout<<endl;
		return 0;
	}
	
	sort(cf+2,cf+n+1);
	
	for(int mask=0;mask<(1<<(n-1));mask++){
		vector<int>v1,v2;
		for(int i=2;i<=n;i++){
			if(mask>>(i-2)&1){
				v1.push_back(cf[i]);
			}else{
				v2.push_back(cf[i]);
			}
		}
		tmp[1]=cf[1];
		for(int cnt=SZ(v1)-1,i=2;i<=1+SZ(v1);i++,cnt--){
			tmp[i]=v1[cnt];
		}
		for(int cnt=0,i=1+SZ(v1)+1;i<=n;i++,cnt++){
			tmp[i]=v2[cnt];
		}
		ll sum1=0,sum2=0;
		for(int j=1;j<=n;j++){
			b[j]=b[j-1]+tmp[j];
			sum1+=b[j]*b[j];
			sum2+=b[j];
		}
		ans=min(ans,sum1*n-sum2*sum2);
	}
	printf("%lld\n",ans);
	
	return 0;
}
