#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long w=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		w=(w<<3)+(w<<1)+c-48;
		c=getchar();
	}
	return w*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
long long n,ans=INT_MAX;
vector<long long> a;
vector<vector<long long> > x;
queue<vector<long long> > q;
void work_ans(){
	long long S=0,answer=0;
	for(long long i=0;i<n;i++)S+=a[i];
	for(long long i=0;i<n;i++)answer+=(n*a[i]-S)*(n*a[i]-S);
	answer/=n;
	ans=min(ans,answer);
}
void check(){
	for(long long i=0;i<(long long)x.size();i++){
		if(x[i]==a)return;
	}
	x.push_back(a);
	q.push(a);
	work_ans();
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(long long i=1;i<=n;i++){
		a.push_back(read());
	}
	x.push_back(a);
	q.push(a);
	work_ans();
	while(!q.empty()){
		a=q.front();
		q.pop();
		for(long long i=1;i<=n-2;i++){
			long long tmp=a[i+1]+a[i-1]-a[i],before=a[i];
			if(tmp==a[i])continue;
			else{
				a[i]=tmp;
				check();
				a[i]=before;
			}
		}
	}
	write(ans);
	return 0;
}

