#include<bits/stdc++.h>
using namespace std;
#define M 10001
int n,head=0,tail=0;
int ANS=0x7fffffff;
//bool st;
struct seq{
	int sum;
	int a[401];
	int calc(){
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=(a[i]*n-sum)*(a[i]*n-sum);
		return ans/n;
	}
}s[100001],tmp;
//bool ed;

void BFS(){
	int a,b,pre,aft;
	while(head<=tail){
		tmp=s[head];
		pre=s[head].calc();
		for(int i=1;i<n-1;i++){
			a=tmp.a[i];
			b=tmp.a[i-1]-tmp.a[i]+tmp.a[i+1];
			tmp.a[i]=tmp.a[i-1]-tmp.a[i]+tmp.a[i+1];
			tmp.sum+=b-a;
			aft=tmp.calc();
			if(aft<pre)
				memcpy(&s[++tail],&tmp,sizeof(seq));
			tmp.a[i]=s[head].a[i];
			tmp.sum=s[head].sum;
		}
		head++;
		ANS=min(ANS,pre);
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
//	cout<<(&ed-&st)/1024.0/1024;
	int a,b,ans=0;
	scanf("%d",&n);
	s[0].sum=0;
	for(int i=0;i<n;i++) {
		scanf("%d",&s[0].a[i]);
		s[0].sum+=s[0].a[i];
	}
	BFS();
	printf("%d\n",ANS);
	return 0;
}
