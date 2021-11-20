#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<vector<int>,bool> mp;
double ans=1e5;
vector<int> a;
queue<vector<int> > q;
queue<int> w;
int read(){
	int sum=0; bool flag=false; char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		sum=(sum*10)+c-'0';
		c=getchar();
	}
	if(flag) return -sum;
	else return sum;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read(); int l=0,x;
	for(int i=0;i<n;i++) {cin>>x;a.push_back(x);l+=a[i];}
	q.push(a); w.push(l); mp[a]=1;
	while(!q.empty())
	{
		a.clear();
		a=q.front(); q.pop();
		l=w.front(); w.pop();
		ll sum=0;
		for(int i=0;i<n;i++) {sum+=pow(a[i]*n-l,2);}
		ans=min(ans,(double)sum/n);
		for(int i=1;i<n-1;i++)
		{
			if(a[i]==a[i-1]+a[i+1]-a[i]) continue;
			else
			{
				int c=a[i];
				a[i]=a[i-1]+a[i+1]-a[i];
				if(mp[a]==1) continue;
				q.push(a);
				w.push(l+a[i]-c);
				a[i]=c;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
