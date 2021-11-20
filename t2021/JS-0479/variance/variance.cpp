//niconiconiconi
//1145141rljukcgfy598yr5987397tkdjfkl;asdfghjkl9/ rfljglfj55085-065646/-*-+=5-90-258 bvjflkogjgjgjgjgut785486464x5r cbg-hn
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define endl "\n"
int main() {
	freopen("variance.in","r",stdin); freopen("variance.out","w",stdout);
	int N; cin>>N;
	vector <int> v;
	for(int i=0;i<N;i++) {
		int x; cin>>x; v.push_back(x);
	}
	queue <vector <int> > q; q.push(v);
	int cnt=0;
	int mn=1e9;
	while(!q.empty()&&cnt<=1e5) {
		double AVerage=0;
		for(int i=0;i<v.size();i++) AVerage+=v[i];
		AVerage/=(double)N;
		double D=0;
		for(int i=0;i<N;i++) D+=((double)v[i]-AVerage)*((double)v[i]-AVerage);
		D/=(double)N;
		int d=D*N*N;
		mn=min(mn,d);
		v=q.front(); q.pop();
		for(int i=1;i<v.size()-1;i++) {
			vector <int> tmp=v; tmp[i]=v[i-1]+v[i+1]-v[i];
			cnt++; q.push(tmp);
		}
	}
	cout<<mn<<endl;
	return 0;
}

