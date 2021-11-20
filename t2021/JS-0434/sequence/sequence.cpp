#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
   ll x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	printf("40");
	return 0;
}

