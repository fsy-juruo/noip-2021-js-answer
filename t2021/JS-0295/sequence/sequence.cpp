#include <iostream>
#include <fstream>
using namespace std;

int n,m,k;
long long v[110];
const long long mod=998244353;
void init(istream& ins)
{
	ins>>n>>m>>k;
	for(int i=0;i<=m;i++)
		ins>>v[i];
	return;
}

namespace hf{
	long long dp[32][130000];
	int bitcount(int x)
	{
		int cnt=0;
		while(x!=0)
		{
			x&=x-1;
			cnt++;
		}
		return cnt;
	}
	void work(ostream& ous)
	{
		dp[0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=n*(1<<m);j++)
				if(dp[i][j]!=0)
					for(int l=0;l<=m;l++)
					{
						dp[i+1][j+(1<<l)]+=dp[i][j]*v[l]%mod;
						dp[i+1][j+(1<<l)]%=mod;
					}
		}
		long long ans=0;
		for(int i=0;i<=n*(n<<m);i++)
			if(bitcount(i)<=k)
				ans=(ans+dp[n][i])%mod;
		ous<<ans<<endl;
	}
}

int main()
{
	ifstream fin("sequence.in");
	ofstream fout("sequence.out");
	init(fin);
	hf::work(fout);
	return 0;
}
