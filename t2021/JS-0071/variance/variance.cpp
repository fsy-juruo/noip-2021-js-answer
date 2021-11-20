#include<bits/stdc++.h>
#define int long long
using namespace std;
//  n <=20
//a[i]<=40

int n,ans;
vector<int>a;
class Seq{
public:
	vector<int>a;
	int v,m;
	//m=ave*n
	//v=D*n
	void calc(){
		m=0;
		v=0;
		for(int i:a)m+=i;
//		assert(m%n==0);
//		m/=n;
		for(int i:a){
			v+=(i*n-m)*(i*n-m);
		}
	}
	void create(Seq&n,int i){
		n.a=a;
		n.a[i]=n.a[i-1]+n.a[i+1]-n.a[i];
		n.calc();
	}
	void show(){
		cout<<m<<":"<<v<<"\n";
	}
	void print(){
		for(int i:a){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	friend bool operator < (const Seq& lef,const Seq& rig){
		return lef.v<rig.v;
	}
	friend bool operator == (const Seq& lef,const Seq& rig){
		if(lef.v!=rig.v||lef.m!=rig.m)return 0;
		for(int i=0;i<n;i++)if(lef.a[i]!=rig.a[i])return 0;
		return 1;
	}
	friend bool operator != (const Seq& lef,const Seq& rig){
		for(int i=0;i<n;i++)if(lef.a[i]==rig.a[i])return 0;
		return 1;
	}
};
class Set{
public:
	map<int,vector<Seq> >a;
	int insert(const Seq& n){
		vector<Seq>&seq=a[n.v];
		for(const Seq&i:seq){
			if(i==n){
				return 0;
			}
		}
		seq.push_back(n);
		return 1;
	}
};
queue<Seq>q;
Set s;
void bfs(){
	Seq st;
	st.a=a;
	st.calc();
//	cout<<st.m<<":"<<st.v<<"\n";
	q.push(st);
	s.insert(st);
	while(!q.empty()){
		Seq f=q.front();
		q.pop();
		ans=min(ans,f.v);
//		cout<<"\n";
//		f.show();
//		f.print();
		for(int i=1;i<n-1;i++){
			Seq n;
			f.create(n,i);
			if(s.insert(n)){
				q.push(n);
			}
		}
	}
//	assert(ans%n==0);
	cout<<ans/n<<"\n";
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	ans=INT_MAX;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	bfs();
	
	return 0; 
}
/*
4
1 2 4 6
*/
/*
13
52
*/
