#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int read(){
	int xx=0,ff=1;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-')ff=-1;
		ch=getchar();
	}
	while (isdigit(ch)){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return ff*xx;
}
void write(int x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9)write(x/10);
	putchar(x%10+'0');
}
bool check(int x){
	while (x!=0){
		int y=x%10;
		if (y==7)return 1;
		x/=10;
	}
	return 0;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	while (T--){
		int x=read();
		bool flag=0;
		for (int i=1;i*i<=x;i++)
		   if (x%i==0)if (check(i)||check(x/i)){
		   	 flag=1;
		   	 break;
		   }
		if (flag){
			cout<<-1<<endl;
			continue;
		}
		for (int i=x+1;i<=1e8;i++){
			flag=0;
			for (int j=1;j*j<=i;j++)
			   if (i%j==0)if (check(j)||check(i/j)){
			   	flag=1;
			   	break;
			   }
			if (flag)continue;
			else{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}


