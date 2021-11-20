#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<bitset>
using namespace std;

unsigned long long p2[]={1ull,2ull,4ull,8ull,16ull,32ull,64ull,128ull,256ull,512ull,1024ull,2048ull,4096ull,8192ull,16384ull,32768ull,65536ull,131072ull,262144ull,524288ull,1048576ull,2097152ull,4194304ull,8388608ull,16777216ull,33554432ull,67108864ull,134217728ull,268435456ull,536870912ull,1073741824ull,2147483648ull,4294967296ull,8589934592ull,17179869184ull,34359738368ull,68719476736ull,137438953472ull,274877906944ull,549755813888ull,1099511627776ull,2199023255552ull,4398046511104ull,8796093022208ull,17592186044416ull,35184372088832ull,70368744177664ull,140737488355328ull,281474976710656ull,562949953421312ull,1125899906842624ull,2251799813685248ull,4503599627370496ull,9007199254740992ull,18014398509481984ull,36028797018963968ull,72057594037927936ull,144115188075855872ull,288230376151711744ull,576460752303423488ull,1152921504606846976ull,2305843009213693952ull,4611686018427387904ull,9223372036854775808ull};
unsigned long long n,m,k;
unsigned long long v[1200];
unsigned long long ans=0;
inline unsigned long long calc_1( unsigned long long i)
{
	unsigned long long ans=0;
	while(i!=0)
	{
		ans+=i&1;
		i=i>>1;
	}
	return ans;
}
void dfs(unsigned long long pos,unsigned long long S,unsigned long long Val)
{
	if(pos>n)
	{
		if(calc_1(S)<=k)
		{
			//cout<<S<<' '<<Val<<endl;
			ans+=Val;
			ans%=998244353;
		}
		return;
	}
	for(unsigned long long i=0;i<=m;i++)
	{
		dfs(pos+1,S+p2[i],(Val*v[i])%998244353);
	}
}
int main()
{
	//freopen("2n.txt","w",stdout);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(unsigned long long i=0;i<=m;i++)
	{
		cin>>v[i];
	}
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}
