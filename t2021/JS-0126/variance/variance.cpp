#include <bits/stdc++.h>
using namespace std;

const int maxn=110;

int n,ans=2e9;
set<vector<int> > st;

inline int calc(vector<int> a)
{
	int ret=0,sum=0;
	for(int i=0;i<n;i++) ret+=n*a[i]*a[i],sum+=a[i];
	ret-=sum*sum;
	
	return ret;
}

inline void bf(vector<int> a)
{
	if(st.count(a)) return;
	st.insert(a);
	
	ans=min(ans,calc(a));
	
	for(int i=1;i<n-1;i++)
	{
		a[i]=a[i-1]+a[i+1]-a[i];
		bf(a);
		a[i]=a[i-1]+a[i+1]-a[i]; 
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	scanf("%d",&n);
	
	vector<int> a(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	bf(a);
	
	printf("%d",ans);
	
	return 0; 
}
