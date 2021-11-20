#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,mm=INT_MAX,a[15];
struct uu
{
	int a,b,c,d;
};
vector<int>v[maxn];
bool operator<(uu a,uu b)
{
	return a.a<b.a||(a.a==b.a&&a.b<b.b)||(a.a==b.a&&a.b==b.b&&a.c<b.c)||(a.a==b.a&&a.b==b.b&&a.c==b.c&&a.d<b.d);
}
bool operator<(vector<int>v,vector<int>u)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<u[i])return true;
		else if(u[i]<v[i])return false;
	}
	return false;
}
map<uu,bool>m;
map<vector<int>,bool>mu;
deque<uu>q;
int op[16];
void read(int &s)
{
	s=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+(c-48);
		c=getchar();
	}
	s=s*f;
}
int gf(uu a)
{
	int s=a.a+a.b+a.c+a.d;
	return ((a.a*4-s)*(a.a*4-s)+(a.b*4-s)*(a.b*4-s)+(a.c*4-s)*(a.c*4-s)+(a.d*4-s)*(a.d*4-s))/n;
}
int gf2()
{
	int fc=0;
	int s=0;
	for(int i=1;i<=n;i++)s+=op[i];
	for(int i=1;i<=n;i++)fc+=(op[i]*n-s)*(op[i]*n-s);
	return fc/n;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	v[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		v[0].push_back(a[i]);
	}
	if(n==1)
	{
		cout<<0<<endl;
	}
	else if(n==2)
	{
		int s=a[1]+a[2];
		cout<<((a[1]*n-s)*(a[1]*n-s)+(a[2]*n-s)*(a[2]*n-s))/n<<endl;
	}
	else if(n==3)
	{
		int s=a[1]+a[2]+a[3];
		mm=min(mm,((a[1]*n-s)*(a[1]*n-s)+(a[2]*n-s)*(a[2]*n-s)+(a[3]*n-s)*(a[3]*n-s))/n);
		a[2]=a[3]+a[1]-a[2];
		s=a[1]+a[2]+a[3];
		mm=min(mm,((a[1]*n-s)*(a[1]*n-s)+(a[2]*n-s)*(a[2]*n-s)+(a[3]*n-s)*(a[3]*n-s))/n);
		cout<<mm<<endl;
	}
	else if(n==4)
	{
		q.push_back({a[1],a[2],a[3],a[4]});
		while(!q.empty())
		{
			uu w=q.front();
			q.pop_front();
			mm=min(mm,gf(w));
			uu b=w;
			b.b=b.c+b.a-b.b;
			if(!m[b])
			{
				m[b]=true;
				q.push_back(b);
			}
			b=w;
			b.c=b.b+b.d-b.c;
			if(!m[b])
			{
				m[b]=true;
				q.push_back(b);
			}
		}
		cout<<mm<<endl;
	}
	else if(n>=5&&n<=15)
	{
		int ts=0,i=0;
		while(i<=ts)
		{
			for(int j=1;j<=n;j++)op[j]=v[i][j];
			mm=min(mm,gf2());
			for(int j=2;j<n;j++)
			{
				int t=op[j];
				op[j]=op[j+1]+op[j-1]-op[j];
				ts++;
				v[ts].push_back(0);
				for(int k=1;k<=n;k++)
				{
					v[ts].push_back(op[k]);
				}
				for(int k=1;k<=n;k++)cout<<v[ts][k]<<' ';
				cout<<endl;
				if(!mu[v[ts]])
				{
					mu[v[ts]]=true;
				}
				else ts--;
				op[j]=t;
			}
		}
		cout<<mm<<endl;
	}
	return 0;
}
