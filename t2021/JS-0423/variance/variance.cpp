#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##__##akioi=n;i<i##__##akioi;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,i##__##aknoi=n;i<=i##__##aknoi;++i)
#define per1(i,n) for(int i=n;i>=1;--i)
#define y0 ak_csp_ak_noip
#define y1 i_love_luogu
#define pq priority_queue
#define np next_permutation
typedef long long ll;
typedef unsigned long long ull;
const ll mod1=998244353;
const ll mod2=1000000007;
using namespace std;
set<vector<int> > s;
queue<vector<int> > q;
int mx;
int var(const vector<int> &v)
{
	int n=v.size();
	int S1=0,S2=0;
	rep(i,n)
	{
		S1+=v[i];S2+=v[i]*v[i];
	}
	return n*S2-S1*S1;
}
int mnvar;
vector<int> trans(vector<int> v,int pos)
{
	v[pos]=v[pos+1]+v[pos-1]-v[pos];
	return v;
}
int n;
vector<int> a,b;
int main()
{
	#ifndef DEBUG
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	#else
	#endif
	cin>>n;
	a.resize(n);
	rep(i,n) cin>>a[i];
	s.insert(a);
	q.push(a);
	mnvar=var(a); 
	while(!q.empty())
	{
		a=q.front();q.pop();
		for(int i=1;i<n-1;++i)
		{
			b=trans(a,i);
			if(!s.count(b))
			{
				s.insert(b);
				mnvar=min(mnvar,var(b));
				q.push(b);
			}
		}
	}
	cout<<mnvar<<endl;
	return 0;
}
/*
visit me qwq: www.luogu.com.cn/user/483824
I have contestId 56666 !(this is not factorial
www.luogu.com.cn/contest/56666
friends(have met): @huagaohan @sszcdjr @littlewave
//freopen ".ans" "1.in" "1.out" ".txt"
ccf ak ioi

*/


