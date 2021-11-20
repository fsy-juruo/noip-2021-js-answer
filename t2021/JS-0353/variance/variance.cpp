#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node 
{
	int f,s,t,si;
	bool operator<(const node a)
	{
		return (f<a.f)&&(s<a.s)&&(t<a.t)&&(si<a.si);
	}
};
const int maxn=1e4+10;
queue<double> fc;
node a;
set<node> s;

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	int temp=0;
	cin>>n;
	cin>>a.f>>a.s>>a.t>>a.si;
	temp=a.f+a.s+a.t+a.si;
	double fc_temp=temp*1.0/n;
	fc.push(fc_temp);
	for(int i=1;i<=10;i++)
	{
		double ot=0.0;
		s.insert(node{a.f,a.f+a.t-a.s,a.t,a.si});
		a.s=a.f+a.t-a.s;
		temp=a.f+a.s+a.t+a.si;
		fc_temp=temp*1.0/n;
		ot=(a.f*1.0-fc_temp)*(a.f*1.0-fc_temp)+(a.s*1.0-fc_temp)*(a.s*1.0-fc_temp)+(a.t*1.0-fc_temp)*(a.t*1.0-fc_temp)+(a.si*1.0-fc_temp)*(a.si*1.0-fc_temp);
		fc.push(ot*n);
		s.insert(node{a.f,a.s,a.s+a.si-a.t,a.si});
		a.t=a.s+a.si-a.t;
		temp=a.f+a.s+a.t+a.si;
		ot=(a.f*1.0-fc_temp)*(a.f*1.0-fc_temp)+(a.s*1.0-fc_temp)*(a.s*1.0-fc_temp)+(a.t*1.0-fc_temp)*(a.t*1.0-fc_temp)+(a.si*1.0-fc_temp)*(a.si*1.0-fc_temp);
		fc.push(ot*n);
	}
	double ans=100000.0;
	while (!fc.empty())
	{
		ans=min(ans,fc.front());
	}
	cout<<ans<<endl;
	return 0;
}

