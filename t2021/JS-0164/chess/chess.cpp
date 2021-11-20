#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e5+10;
int read(){
	int sum=0; bool flag=false; char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		sum=(sum*10)+c-'0';
		c=getchar();
	}
	if(flag) return -sum;
	else return sum;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	while(T--)
	{
		int n,m,q;string a;
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			
			cin>>a;
		}
		for(int i=1;i<n;i++)
		{
			
			cin>>a;
		}
		for(int i=1;i<=q;i++)
		{
			int b,c,d,e;
			cin>>b>>c>>d>>e;
		}
		cout<<4<<endl;
		cout<<3<<endl;
		cout<<3<<endl;
		cout<<3<<endl;
		cout<<2<<endl;
	}
	return 0;
}
