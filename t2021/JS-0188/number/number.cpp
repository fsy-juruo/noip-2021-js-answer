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

bool chkdigt(int x)
{
	while(x>0)
	{
		if(x%10==7)
		{
			return true;
			break;
		}
		x/=10;
	}
	return false;
}
const int SIZE=1e7+3;
int isok[SIZE];
void sieve()
{
	REP(i,SIZE)isok[i]=1;
	REP(i,SIZE)if(isok[i]==1)
	{
		if(chkdigt(i))
			for(int j=i;j<SIZE;j+=i)isok[j]=0;
	}
}

void solve()
{
	int n;
	cin>>n;
	if(!isok[n] || chkdigt(n))cout<<-1<<endl;
	else
	{
		n++;
		while(!isok[n] || chkdigt(n))n++;
		cout<<n<<endl;
	}
}

int main()
{
	#ifdef LOCAL
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
	#endif
	sieve();
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
//check long long
//think twice
//read all the problems
//check array

