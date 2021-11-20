#include<bits/stdc++.h>
using namespace std;
#define cnt sjihfaiohi
#define min shuioah
#define signed unsigned long long
signed a[10000+5];
signed b[10000+5];
char mrk[10000+5];
signed brn[10000+5];
signed n;
signed cnt()
{
	signed ans=0;
	for(signed i=1;i<=n;++i)
	{
		ans+=a[i]*a[i];
	}
	signed t=0;
	for(signed i=1;i<=n;++i)
	{
		t+=a[i];
	}
	return n*ans-t*t;
}
signed min(signed a,signed b)
{
	if(a<b)return a;
	return b;
}

signed ans;

void force(signed tr)
{
	if(tr==n+1)
	{
		for(signed i=2;i<=n;++i)
	{
		a[i]=a[i-1]+brn[i];
	}
		ans=min(ans,cnt());
		//cout<<cnt();
		
	}
	for(signed i=2;i<=n;++i)
	{
		if(mrk[i]==0)
		{
			mrk[i]=1;
			brn[tr]=b[i];
			force(tr+1);
			mrk[i]=0;
		}
	}
}


int main()
{
	
	
	ios::sync_with_stdio(0);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	
	cin>>n;
	for(signed i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	
	ans=cnt();
	//cout<<ans<<endl;
	
	
	for(signed i=2;i<=n;++i)
	{
		b[i]=a[i]-a[i-1];
	}
	
	force(2);
	

	cout<<ans<<endl;
	
	return 0;
}
