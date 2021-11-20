#include<bits/stdc++.h>
using namespace std;
int n,a[10010];
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
int ans=INT_MAX;
int calc(){
	int s=0,sum=0;
	for (int i=1;i<=n;i++)s+=a[i];
	for (int i=1;i<=n;i++){
		sum=sum+a[i]*a[i]*n-2*a[i]*s;
		//cout<<sum<<endl;
	}
	sum+=s*s;
	return sum;
}
int h[410];
int cnt=0;
void dfs(int dep){
	ans=min(ans,calc());
	if (cnt>=50000000){
		cout<<ans<<endl;
		exit(0);
    }
    for (int i=2;i<n;i++)
    {
    	cnt++;
       if (h[i]<=3){
       	  h[i]++;
       	  int y=a[i];
       	  a[i]=a[i-1]+a[i+1]-a[i];
       	  dfs(dep+1);
       	  h[i]--;
       	  a[i]=y;
	   }
   }
	return ;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	dfs(1);
	cout<<ans<<endl;
	return 0;
}


