#include<bits/stdc++.h>
using namespace std;
const int pr[]={2,3,5,7,11,13,17,19,23,29};
const int ppr=10;
long long mod=998244353;
int n,m,k;
long long v[105];
long long fct[50][50];
long long ans;
int sp[105];
int s[505],maxp;
long long ccres[50];
long long quickpow(long long bas,long long tim)
{
	long long res=1;
	while(tim)
	{
		if(tim&1)
		{
			res*=bas;
			res%=mod;
		}
		bas*=bas;
		bas%=mod;
		tim>>=1;
	 }
	return res;
}
long long cc(long long adn,long long aup)//c52=cc(5,2)
{
	//res=fct(adn)/(fct(adn-aup)*fct(aup))
	long long res=1;
	for(int i=0;i<ppr;i++)
	{
		ccres[pr[i]]=fct[adn][pr[i]]-fct[adn-aup][pr[i]]-fct[aup][pr[i]];
		long long tmp=quickpow(pr[i],ccres[pr[i]]);
		res*=tmp;
		res%=mod;
	}
	return res;
}
void czh()
{
	//zhs->gr
	long long gr=1;
	long long lft=n;
	for(int i=0;i<=m;i++)
	{
		if(sp[i]!=0)
		{
			long long tem=cc(lft,sp[i]);
			lft-=sp[i];
			tem%=mod;
			gr*=tem;
			gr%=mod;
		}
	}
	//cout<<"gr:"<<gr<<"\n";
	//v->val
	long long val=1;
	for(int i=0;i<=m;i++)
	{
		if(sp[i]!=0)
		{
			long long tem=quickpow(v[i]%mod,sp[i]);
			/*
			for(int j=1;j<=sp[i];j++)
			{
				tem*=v[i];
				tem%=mod;
			}
			*/
			val*=tem;
			val%=mod;
		}
	}
	//cout<<"val:"<<val<<"\n";
	long long res=(gr*val)%mod;
	ans+=res;
	ans%=mod;
	//cout<<res<<" "<<ans<<"\n";
}
void chek()
{
	//check
	maxp=-1;
	memset(s,0,sizeof(s));
	for(int i=0;i<=m;i++)
	{
		//if(i<=5)cout<<sp[i]<<" ";
		int x=sp[i];
		int p=0;
		while(x)
		{
			if(x&1)
			{
				s[p+i]++;
				maxp=max(maxp,p+i);
			}
			x>>=1;
			p++;
		}
	}
	//cout<<"\n";
	//cout<<"maxp:"<<maxp<<"\n";
	//check
	int cntk=0;
	for(int i=0;i<=maxp;i++)
	{
		//cout<<s[i]<<" ";
		s[i+1]+=s[i]>>1;
		if(i+1>maxp&&s[i+1]!=0)maxp++;
		if(s[i]&1)cntk++;
	}
	//cout<<"\n";
	//cout<<"cntk:"<<cntk<<"\n"; 
	if(cntk>k)return;
	czh();
}
void dfs(int dpth,int lft)
{
	//cout<<dpth<<" "<<lft<<"\n";
	if(dpth==m+1)
	{
		if(lft!=0)return;
		chek();
		return;
	}
	for(int i=0;i<=lft;i++)
	{
		sp[dpth]=i;
		dfs(dpth+1,lft-i);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>v[i];
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int x=j;
			for(int k=0;k<ppr;k++)
			{
				while(x%pr[k]==0)
				{
					x/=pr[k];
					fct[i][pr[k]]++;
				}
			}
		}
	}
	/*
	for(int i=1;i<=30;i++)
	{
		cout<<i<<"!:";
		for(int k=0;k<ppr;k++)
		{
			cout<<pr[k]<<"^"<<fct[i][pr[k]]<<"*";
		}
		cout<<"\n";
	}
	*/
	//cout<<cc(10,1)<<" "<<cc(5,2)<<" "<<cc(7,5)<<" "<<cc(10,10)<<"\n";
	//cout<<quickpow(2,10)<<" "<<quickpow(3,5)<<" "<<quickpow(10,10)<<"\n";
	dfs(0,n);
	cout<<ans;
	return 0;
}
