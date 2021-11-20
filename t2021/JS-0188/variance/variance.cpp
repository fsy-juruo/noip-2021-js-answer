#include<bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOCAL
using namespace std;

inline int read()
{
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'|| c>'9')if(c=='-'){f=-1;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return f*ret;
}
const int INF=0x3f3f3f3f;
int ans=INF,tim=0;
int n;
void dfs(int last,vector<int> a)
{
	tim++;
	int tot1=0,tot2=0;
	for(int u:a)
		tot1+=u,tot2+=u*u;
	//cout<<endl;
	//cout<<tot2*n-tot1*tot1<<endl;
	ans=min(ans,tot2*n-tot1*tot1);
	if(tim>(1<<n)-2)return;
	for(int i=1;i<a.size()-1;i++)if(i!=last)
	{
		vector<int> v=a;
		v[i]=v[i+1]+v[i-1]-v[i];
		dfs(i,v);
	}
}

int main()
{
	#ifdef LOCAL
		freopen("variance.in","r",stdin);
		freopen("variance.out","w",stdout);
	#endif
	cin>>n;
	vector<int> a;
	REP(i,n)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	dfs(0,a);
	cout<<ans<<endl;
	return 0;
}
//check long long
//think twice
//read all the problems
//check array

