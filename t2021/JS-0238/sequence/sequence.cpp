#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[31],o_ava[31];
long long v[105],ans,o_ans;
void _count(int step){
	if(step==n+1){
		++o_ans;
	}
	else{
		for(int i=0;i<=m;++i){
			if(o_ava[i]){
				o_ava[i]-=1;
				_count(step+1);
				o_ava[i]+=1;
			}
		}
	}
}
long long _o(){
	o_ans=0;
	memset(o_ava,0,sizeof(o_ava));
	for(int i=1;i<=n;++i)
		++o_ava[a[i]];
	_count(1);
	return o_ans;
}
long long sub_ans(){
	long long _ans=1;
	for(int i=1;i<=n;++i)
		_ans=_ans*v[a[i]]%998244353%998244353;
	_ans*=_o();
	return _ans;
}
int S(){
	int _sum=0,_sub;
	for(int i=1;i<=n;++i){
		_sub=1;
		for(int j=1;j<=a[i];++j)_sub=_sub<<1;
		_sum+=_sub;
	}
	return _sum;
}
bool _ava(int x){
	int ans=0;
	while(x!=0){
		if(x%2)++ans;
		x=x>>1;
	}
	return bool(ans<=k);
}
void go(int step){
	if(step==n+1){
		if(_ava(S()))ans=(ans+sub_ans())%998244353%998244353;
	}
	else{
		for(int i=a[step-1];i<=m;++i){
			a[step]=i;
			go(step+1);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i)
		scanf("%lld",&v[i]);
	go(1);
	printf("%lld\n",ans);
	return 0;
}
