#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d,ans;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	if(n==2){
		scanf("%d%d",&a,&b);
		int p=a+b;
		a*=2,b*=2;
		ans=((a-p)*(a-p)+(b-p)*(b-p))/2;
	}
	if(n==3){
		scanf("%d%d%d",&a,&b,&c);
		int p=a+b+c;
		a*=3,b*=3,c*=3;
		ans=((a-p)*(a-p)+(b-p)*(b-p)+(c-p)*(c-p))/3;
		b=a+c-b;
		p=(a+b+c)/3;
		ans=min(ans,((a-p)*(a-p)+(b-p)*(b-p)+(c-p)*(c-p))/3);
	}
	if(n==4){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a*=4;b*=4;c*=4;d*=4;
		int p=(a+b+c+d)/4;
		ans=((a-p)*(a-p)+(b-p)*(b-p)+(c-p)*(c-p)+(d-p)*(d-p))/4;
		int bb=a+c-b;
		p=(a+bb+c+d)/4;
		ans=min(ans,((a-p)*(a-p)+(bb-p)*(bb-p)+(c-p)*(c-p)+(d-p)*(d-p))/4);
		int cc=a+d-b;
		p=(a+bb+cc+d)/4;
		ans=min(ans,((a-p)*(a-p)+(bb-p)*(bb-p)+(cc-p)*(cc-p)+(d-p)*(d-p))/4);
		bb=a+d-c;
		p=(a+bb+cc+d)/4;
		ans=min(ans,((a-p)*(a-p)+(bb-p)*(bb-p)+(cc-p)*(cc-p)+(d-p)*(d-p))/4);
		cc=b+d-c;
		p=(a+bb+cc+d)/4;
		ans=min(ans,((a-p)*(a-p)+(bb-p)*(bb-p)+(cc-p)*(cc-p)+(d-p)*(d-p))/4);
		p=(a+b+cc+d)/4;
		ans=min(ans,((a-p)*(a-p)+(b-p)*(b-p)+(cc-p)*(cc-p)+(d-p)*(d-p))/4);
	}
	printf("%d\n",ans);
	return 0;
}
