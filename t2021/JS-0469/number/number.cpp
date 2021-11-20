#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,ans=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<3)+(ans<<1)+c-'0';c=getchar();}
	return f*ans;
}
void print(int xx){
	if(xx<0){
		putchar('-');
		print(-xx);
		return;
	}
	if(xx>9)print(xx/10);
	putchar(xx%10+'0');
	return;
}
int a[800010];
bool b[10000010];
bool p(int xx){
	if(xx%7==0)return false;
	while(xx){
		if(xx%10==7)return false;
		xx/=10;
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	int t=0;
	for(int i=1;i<=10000001;i++){
		b[i]=true;
	}
	for(int i=1;i<=10000001;i++){
		if(b[i]){
			if(p(i)){
				t++;
				a[t]=i;
			}else{
				b[i]=false;
				for(int j=i;j<=10000001;j+=i){
					b[j]=false;
				}
			}
		}
	}
	n=read();
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		if(b[x]==0){
			print(-1);
			putchar('\n');
			continue;
		}
		int l=1,r=t;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid]>x){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		print(a[r+1]);
		putchar('\n');
	}
	return 0;
}
