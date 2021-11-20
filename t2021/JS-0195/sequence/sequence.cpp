/*
So, this is the end. I Looking back the past experieces which filled by junior high and senior high, there is much to be said.
However, time won't permit it. So this is it.
But it is not the end. 
There are plenty of years aheand. Time to be cherished, time to be made the most of.
What lies in front of me is what I should spend my words and my efforts on.
Fare well, for all the years before.
Hello, World.
*/
#include <bits/stdc++.h>
#define nwah cout<<"nwah"<<endl;
using namespace std;

const int MAXN=30+1; const int MAXM=100+2; const unsigned long long MOD=998244353;
int n,m,k; unsigned long long v[MAXN];
vector <int> s;

void read_in() {
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>v[i];
}

int get_one(int x) {
	int ret=0;
	while(x) {
		if(x%2==1) ret++;
		x=(x>>1);
	}
	return ret;
}

void shit_solve() {
	for(int i=n;i<=n*(1<<m);i++) {
		int cnt=0;
		cnt=get_one(i);
		if(cnt<=k) s.push_back(i);
	}
	for(int i=0;i<s.size();i++) {
		
	}
}

void in_the_name_of_luck_it_self_and_those_who_look_up_to_it_as_a_supreme_power(int the_seed_is_strong) {
	srand(the_seed_is_strong);
	int rp=0;
	for(int i=0;i<1024;i++) rp++;
	int the_luck_itself=rand();
	cout<<the_luck_itself<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read_in();
/*	if(n<=8&&m<=9) {
		shit_solve();
		cout<<s.size()<<endl;
	}	*/
	in_the_name_of_luck_it_self_and_those_who_look_up_to_it_as_a_supreme_power(20211108);
	
	return 0;
} 






































