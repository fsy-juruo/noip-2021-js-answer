#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int x[200005],t,z[10005];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f*x;
}
inline void write(int x){
	stack<int>s;char ch;
	if(x==0){putchar('0');return;}
	if(x<0){putchar('-');x=-x;}
	while(x!=0){s.push(x%10);x/=10;}
	while(!s.empty()){ch=s.top();s.pop();putchar(ch^48);}
	return;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=200000;i++){
		if(x[i]!=2)x[i]=1;
		if(i%10==7)x[i]=0;
		if(i%100-i%10==70)x[i]=0;
		if(i%1000-i%100==700)x[i]=0;
		if(i%10000-i%1000==7000)x[i]=0;
		if(i%100000-i%10000==70000)x[i]=0;
		if(i%1000000-i%100000==700000)x[i]=0;
		if(i%10000000-i%1000000==7000000)x[i]=0;
		if(x[i]==0){
			int q=0;
			while(q<200000){
				x[q]=2;
				q+=i;
			}
		}
	}
	t=read();
	for(int i=1;i<=t;i++){
		z[i]=read();
		if(x[z[i]]==2){cout<<"-1"<<endl;}
		else{
			z[i]++;
			while(x[z[i]]!=1)z[i]++;
			write(z[i]);
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
