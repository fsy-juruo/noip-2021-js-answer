#include<iostream>
#include<cctype>
#define N 10000001
#define inf 1145141919
#define wt if(p(i)&&Hash[i]!=inf)for(j=i;j<N;j+=i)Hash[j]=inf;
using namespace std;
int Hash[N];
inline int qread()
{
	int x=0;
	bool sgn=0;
	char ch;
	ch=getchar();
	if(ch=='-')
		sgn=1;
	else
		x=ch-'0';
	while(1)
	{
		ch=getchar();
		if(ch==' '||ch=='\n')
			break;
		x=(x<<1)+(x<<3)+ch-'0';
	}
	if(sgn)x=-x;
	return x;
}
inline void qwrite(int x)
{
	int high=1000000000;
	while(x/high==0)
		high/=10;
	while(high)
	{
		putchar((x/high)+'0');
		x%=high;
		high/=10; 
	}
	putchar('\n');
}
inline int p(int x)
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,x,i,j;
	i=7;
	wt
	i=17;
	wt
	i=27;
	wt
	i=37;
	wt
	i=47;
	wt
	i=57;
	wt
	i=67;
	wt
	i=71;
	wt
	i=72;
	wt
	i=73;
	wt
	i=74;
	wt
	i=75;
	wt
	i=76;
	wt
	i=78;
	wt
	i=79;
	wt
	i=87;
	wt
	i=97;
	wt
	for(i=47;i<N;i++)
		wt
	for(i=1;i<N;)
		if(Hash[i]!=inf)
		{
			j=i;
			i++;
			while(Hash[i]==inf)
				i++;
			Hash[j]=i;
		}
		else
			i++;
	T=qread();
	while(T--)
	{
		x=qread();
		if(Hash[x]==inf)
			puts("-1");
		else
			qwrite(Hash[x]); 
	}
}
