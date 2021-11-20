#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
typedef long long ll;
int n,m,k,ans,s,ss;
int c[110];
ll v[110];
bool cnt[110];
ll ksm(int a,int b){
	if(b==0) return 1;
	else if(b==1) return a;
	else return (b&1)?((ll)ksm(a,b>>1)*ksm(a,b>>1)%P)*a%P:(ll)ksm(a,b>>1)*ksm(a,b>>1)%P;
}
int read(){
	char ch=getchar();
	int f=1,ans=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+(ch-'0');
		ch=getchar();
	}
	return f*ans;
}
void add(int op){
	if(cnt[op]){
		cnt[op]=false;
		s--;
		add(op+1);
		return ;
	}
	else{
		cnt[op]=true;
		s++;
		return ;
	}
}
void era(int op){
	if(cnt[op]){
		cnt[op]=false;
		s--;
		return ;
	}
	else{
		cnt[op]=true;
		s++;
		era(op+1);
		return ;
	}
}
void search(int op){
	if(op>n){
		if(s<=k){
			ss=1;
			for(int i=0;i<=m;i++) ss=ss*ksm(v[i],c[i])%P;
			ans=(ans+ss)%P;
		}
		return ;
	}
	for(int i=0;i<=m;i++){
		add(i);
		c[i]++;
		search(op+1);
		c[i]--;
		era(i);
	}
	return ;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++) v[i]=ll(read());
	search(1);
	printf("%d\n",ans%P);
	return 0;
} 
