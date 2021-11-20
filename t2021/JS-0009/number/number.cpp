#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

template <typename T1,typename T2>
ostream & operator << (ostream &cout,const pair<T1,T2> &o)
{
	cout<<'('<<o.first<<','<<o.second<<')';
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,const vector<T> &v)
{
	cout<<'{';
	for(int i=0;i<(int)v.size();i++)
	{
		cout<<v[i];
		if(i!=(int)v.size()-1) cout<<',';
	}
	cout<<'}';
	return cout;
}
const int N=1.001e7;
int p[N+5];
int bad[N+5];
int nxt[N+5];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=1;i<=N;i++)
    {
        if(p[i/10] || i%10==7) p[i]=1;
    }
    for(int i=1;i<=N;i++)
    {
    	if(!p[i]) continue;
        for(int j=i;j<=N;j+=i) bad[j]=1;
    }
    for(int i=N;i>=1;i--)
    {
        if(bad[i]) nxt[i]=nxt[i+1];
        else nxt[i]=i;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int x;
        scanf("%d",&x);
        if(bad[x]) puts("-1");
        else printf("%d\n",nxt[x+1]);
    }
	return 0;
}
