#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename TT>void read(TT &x){
	x=0;int f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}
typedef unsigned long long ull;
typedef long long LL;
gp_hash_table<ull,bool> mp;
queue<vector<int> > q;
const ull p=1331;
const int maxn=1e4+100;
int n;
LL a[maxn];

ull hs(vector<int> vec){
	ull ret=0;
	for(int i=0;i<vec.size();i++)ret=ret*p+vec[i];
	return ret;
}
LL ans=LONG_LONG_MAX/2;
void bfs(){
	vector<int> vec;
	for(int i=1;i<=n;i++)vec.push_back(a[i]);
	mp[hs(vec)]=1;
	q.push(vec);
	while(!q.empty()){
		LL ll;
		vec=q.front();q.pop();
//		for(int i=0;i<vec.size();i++)printf("%d ",vec[i]);
//		cout<<endl;
		LL ret=0,sig=0;
		for(int i=0;i<vec.size();i++){
			sig+=vec[i];
			ret+=vec[i]*vec[i];
		}
		ret=n*ret-sig*sig;
		ans=min(ans,ret);
		for(int i=1;i<vec.size()-1;i++){
			ll=vec[i];
			vec[i]=vec[i-1]+vec[i+1]-vec[i];
			LL hss=hs(vec);
			if(mp.find(hss)==mp.end()){
				mp[hss]=1;
				q.push(vec);
			}
			vec[i]=ll;
		}
	}
}


int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);

	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	bfs();
	printf("%lld",ans);
	return 0;
}

