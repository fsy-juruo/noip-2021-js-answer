#include<bits/stdc++.h>
using namespace std;
struct node{
	int xh;
	double sum;
};
int ans=9999999;
const int maxn=400+5;
node a[maxn];
int cmp(node a,node b)
{
	return abs(a.sum)>abs(b.sum);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	double pj=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i].sum;
	a[i].xh=i;
	pj+=a[i].sum;
    }
	pj/=n;
	for(int i=1;i<=n;i++)
	a[i].sum=pj-a[i].sum;
	sort(a+2,a+n,cmp);
	int m=100;
	while(m--)
	{
		a[2].sum=a[a[2].xh+1].sum+a[a[2].xh-1].sum-a[2].sum;
		for(int i=1;i<=n;i++) pj+=a[i].sum;
		pj/=n;
		for(int i=1;i<=n;i++)
	     a[i].sum=pj-a[i].sum;
	    sort(a+2,a+n,cmp);
	    int kkk=0;
	    for(int i=1;i<=n;i++)
	    kkk+=a[i].sum*a[i].sum;
	    ans=min(ans,kkk);
	}
     cout<<ans*n;
     return 0;
}

