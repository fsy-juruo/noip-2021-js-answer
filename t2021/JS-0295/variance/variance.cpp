#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <random>
using namespace std;

int n;
int x[10001];
int p[10001],s[10001];
long long ans=0x3fffffffffffffffll;
int as[11];
long long count(int *a)
{
	long long s1=0,s2=0;
	for(int i=0;i<n;i++)
	{
		s1+=a[i],s2+=a[i]*a[i];
	}
	return n*s2-s1*s1;
}
void check()
{
	static int a[11];
	a[0]=0;
	for(int i=1;i<n;i++)
		a[i]=a[i-1]+p[s[i]];
	if(count(a)<ans)
	{
		ans=count(a);
		for(int i=1;i<n;i++)
			as[i]=s[i];
	}
}

long long car(int *re)
{
	long long p=0,s1=0,s2=0;
	for(int i=1;i<n;i++)
	{
		p+=re[i];
		s1+=p;
		s2+=p*p;
	}
	return n*s2-s1*s1;
}

double T=6000,rt=0.9989;
mt19937 rnd(114514);

void work(istream &ins,ostream &ous)
{
	ins>>n;
	for(int i=1;i<=n;i++)
		ins>>x[i];
	for(int i=1;i<n;i++)
	{
		p[i]=x[i+1]-x[i];
		s[i]=i;
	}
	if(n<=10)
	{
		int c=1;
		for(int i=2;i<n;i++)
			c*=i;
		for(int i=1;i<=c;i++)
		{
			check();
			next_permutation(s+1,s+n);
		}
		ous<<ans<<endl;
	}
	else
	{
		for(;T>0.0000001;T*=rt)
		{
			long long nw=car(p);
			for(int j=1;j<=100;j++)
			{
				int wp=rnd()%(n-1)+1,wq=rnd()%(n-1)+1;
				swap(p[wp],p[wq]);
				if(car(p)<nw)
					break;
				else
					if(rnd()<=0xffffffffu*(1-exp(-T)))
						break;
					else
						swap(p[wp],p[wq]);
			}
		}
		for(int i=1;i<=100;i++)
		{
			long long nw=car(p);
			for(int j=1;j<=100;j++)
			{
				int wp=rnd()%(n-1)+1,wq=rnd()%(n-1)+1;
				swap(p[wp],p[wq]);
				if(car(p)<nw)
					break;
				else
					if(rnd()<=0xffffffffu*(1-exp(-T)))
						break;
					else
						swap(p[wp],p[wq]);
			}
		}
		ous<<car(p);
	}
	//for(int i=1;i<n;i++)
	//	cout<<p[i]<<' ';
	//for(int i=1;i<=n;i++)
	//	cout<<rnd()<<endl;
	return;
}

int main()
{
	ifstream fin("variance.in");
	ofstream fout("variance.out");
	work(fin,fout);
	return 0;
}
