#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
typedef long long ll;

template<typename T>inline void rd(T &x){
	x=0;ll f=1;char c=gc();
	for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=gc())x=x*10+c-'0';
	x*=f;
}

ll n,h[10010],ans=2147483647;
map<string,bool> vis;
string s0,ss;

inline ll calc(string st){
	ll tot=0,sum=0;
	for(int i=0;i<n;i++)tot+=st[i]-'0';
	for(int i=0;i<n;i++)sum+=((st[i]-'0')*n-tot)*((st[i]-'0')*n-tot);
	return sum/n;
}

struct nd{
	string s;
	ll v;
	nd(string _s,ll _v){s=_s,v=_v;}
};

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	rd(n);
	for(int i=0;i<n;i++)cin>>ss,s0+=ss;
	//for(int i=0;i<n;i++)printf("%lld %c\n",h[i],h[i]+'0');
	queue<nd>q;vis[s0]=1;
	q.push(nd(s0,calc(s0)));
	while(!q.empty()){
		//cout<<q.front().s<<' '<<q.front().v<<endl;
		string st=q.front().s;
		//for(int i=0;i<n;i++)cout<<st[i];cout<<endl;
		ans=min(ans,q.front().v);
		q.pop();
		for(int i=1;i<n-1;i++){
			st[i]=st[i-1]+st[i+1]-st[i];
			if(vis.find(st)==vis.end())vis[st]=1,q.push(nd(st,calc(st)));
		}
	}
	printf("%lld\n",ans);
	return 0;
}

