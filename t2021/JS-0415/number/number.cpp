#include <bits/stdc++.h>
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
bool nok[10000050];
int nxt[10000050];
int tac;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=1;i<10000005;i++)
	{
		if (nok[i]) continue;
		int x=i;
		while (x)
		{
			if (x%10==7)
			{
				for (int j=i;j<10000005;j+=i) nok[j]=1;
				break;
			}
			x/=10;
		}
	}
	nxt[10000005]=-1;
	for (int i=10000004;i>=1;i--) nxt[i]=(!nok[i] ? i : nxt[i+1]);
	scanf("%d",&tac);
	//tac=0;
	while (tac--)
	{
		int x;
		scanf("%d",&x);
		if (nok[x]) printf("-1\n");
		else printf("%d\n",nxt[x+1]);
	}
	return 0;
}
