#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##__##akioi=n;i<i##__##akioi;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,i##__##aknoi=n;i<=i##__##aknoi;++i)
#define per1(i,n) for(int i=n;i>=1;--i)
#define y0 ak_csp_ak_noip
#define y1 i_love_luogu
#define pq priority_queue
#define np next_permutation
typedef long long ll;
typedef unsigned long long ull;
const ll mod1=998244353;
const ll mod2=1000000007;
using namespace std;
bool have71[10000007];
bool have72[10000007];
int nx[10000007];
const int N=10000001;
int t,n;
clock_t a,b;
void init()
{
	for(int i=1;i<=N;++i)
	{
		if(have71[i]=have71[i/10]||(i%10==7))
		{
			if(have72[i]) continue;
			for(int j=i;j<=N;j+=i)
			{
				have72[j]=1;
			}
		}
	}
	nx[N-1]=N;
	for(int i=N-2;i>0;--i)
	{
		if(!have72[i+1]) nx[i]=i+1;
		else nx[i]=nx[i+1];
	}
}
int main()
{
	#ifndef DEBUG
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#else
	//freopen("number4.in","r",stdin);
	//freopen("number4.out","w",stdout);
	#endif
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(have72[n]) printf("-1\n");
		else printf("%d\n",nx[n]);
	}
	return 0;
}
/*
visit me qwq: www.luogu.com.cn/user/483824
you may know me as JS-00059 in CSP2021-J or JS-00068 in CSP2021-S
I have contestId 56666 !(this is not factorial
www.luogu.com.cn/contest/56666
friends(have met): @huagaohan @sszcdjr @littlewave
//freopen "number.ans" "number1.in" "bumber1.out" "number.out.txt"
freopen("number.in","r",stdout);
freopen("number.in","w",stdin);
freopen("number.in","w",stdout);
freopen("number.out","r",stdin);
freopen("number.out","w",stdin);
freopen("number.out","r",stdout);
Never gOnna gIve you uP
ccf ak ioi
i love u u love me mixue ice cream and tea~
super idol de xiao rong dou mei ni de tian
wo shai gan le chengmo hui de heng chongdong
NOIP2021 rp++
unsigned long long rp=-1;
rand() srand() mt19937
  _________________
 / bilibilitdasc  /|
/________________/ |
|                | |
| you hai la ji  | |
|________________|/
*/

