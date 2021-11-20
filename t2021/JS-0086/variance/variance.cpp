#include<iostream>
#include<vector>
#include<cstdio>
#include<iomanip>
using namespace std;
vector<int> v;

int n;
void calc()
{
	double pj=0;
	double fc=0;
	for(auto &i:v)
	{
		pj+=i;
	}
	pj/=n;
	int pos=0;
	for(int i=0;i<v.size();i++)
	{
		pos++;
		fc+=(v[i]-pj)*(v[i]-pj);
		int lx1=labs(pj-(v[i]));
		int lx2=labs(pj-(v[i-1]+v[i+1]-v[i]));
		cout<<"pos:"<<pos<<" num:"<<v[i]<<" fc:"<<(v[i]-pj)*(v[i]-pj)<<" ope:"<<v[i-1]+v[i+1]-v[i]<<" to_pjz:"<<lx1-lx2<<endl;
	}
	fc/=n;
	cout<<pj<<endl;
	cout<<fc<<endl;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	
	
//	calc();
//	int pos;
//	while(cin>>pos)
//	{
//		v[pos-1]=v[pos-2]+v[pos]-v[pos-1];
//		calc();
//	}
//	

	long double pj=0;
	long double fc_raw=0;
	while(1)
	{
		pj=0;
		fc_raw=0;
		for(auto &i:v)
		{
			pj+=i;
		}
		pj/=n;
		long double maxlx_pos,maxlx_value=0;
		for(int i=1;i<v.size()-1;i++)
		{
			//fc_raw+=(v[i]-pj)*(v[i]-pj);
			long double lx1=(pj-v[i])>0?(pj-v[i]):(v[i]-pj);
			long double lx2=(pj-(v[i-1]+v[i+1]-v[i]))>0?(pj-(v[i-1]+v[i+1]-v[i])):((v[i-1]+v[i+1]-v[i])-pj);
			//cout<<"pos:"<<i+1<<" num:"<<v[i]<<" fc:"<<(v[i]-pj)*(v[i]-pj)<<" ope:"<<v[i-1]+v[i+1]-v[i]<<" to_pjz:"<<lx1-lx2<<endl;
			//cout<<lx1-lx2<<endl;
			if(lx1-lx2>maxlx_value)
			{
				maxlx_pos=i;
				maxlx_value=lx1-lx2;
			}
		}
		if(maxlx_value>0.1)
		{
			v[maxlx_pos]=v[maxlx_pos-1]+v[maxlx_pos+1]-v[maxlx_pos];
			//cout<<"opeA:"<<maxlx_pos<<endl;
		}
		else
		{
			break;
		}
	}
	
	pj=0;
	for(auto &i:v)
	{
		pj+=i;
	}
	pj/=n;
	for(auto &i:v)
	{
		fc_raw+=(i-pj)*(i-pj);
	}
	cout<<int(n*fc_raw)<<endl;
	return 0;
}
