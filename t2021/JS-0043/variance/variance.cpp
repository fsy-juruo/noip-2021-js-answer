/*
NOIP 2021
By XGN from HHS
It is strictly prohibited to upload this file to Luogu without the author's consent
Especially for certain "analyzing" purpose.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
/*
I am a wolf, a fox, and a rabbit!
- Wulpit
*/

template<typename T1,typename T2> ostream& operator<<(ostream& os,pair<T1,T2> p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<typename T> ostream& operator<<(ostream& os,vector<T> v){
	os<<"[";
	for(auto x:v){
		os<<x<<" ";
	}
	os<<"]";
	return os;
}

int n;
int a[10005];
int now[10005];

ll calcV(){
	int avg=0;
	for(int i=0;i<n;i++){
		avg+=now[i]*n;
	}
	avg/=n;
	
	ll v=0;
	for(int i=0;i<n;i++){
		ll delta=(now[i]*n-avg);
		v+=delta*delta;
	}
	
	return v/n;
}

ll glbV=1000000000000000000ll;

void SA(){
	ll nowV=calcV();
	for(double t=1000000;t>=1e-7;t*=0.9999){
		int id=rand()%(n-1)+1;
		int tmp=now[id];
		now[id]=now[id-1]+now[id+1]-now[id];
		ll newV=calcV();
		if(newV<nowV){
			nowV=newV;
			glbV=min(glbV,nowV);
		}else{
			if(rand()/32768.0>=pow(2.718,-t*(newV-nowV))){
				nowV=newV;
			}else{
				now[id]=tmp;
			}
		}
		
	}
}

int main(){
	srand(time(0));
	
	freopen("variance.in","r",stdin);
	#ifndef XGN
	freopen("variance.out","w",stdout);
	#endif
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		now[i]=a[i];
	}
	
	while(clock()<CLOCKS_PER_SEC*0.8){
		memcpy(now,a,sizeof(a));
		SA();
//		cout<<glbV<<endl;
	}
	
	
	cout<<glbV<<endl;
	return 0;
}
/*
Discarded Program:

int n;
int a[10005];
int now[10005];
ll glbV=1000000000000000000ll;
map<ll,bool> vis;

ll calcV(){
	int avg=0;
	for(int i=0;i<n;i++){
		avg+=now[i]*n;
	}
	avg/=n;
	
	ll v=0;
	for(int i=0;i<n;i++){
		ll delta=(now[i]*n-avg);
		v+=delta*delta;
	}
	
	return v/n;
}

ll calcHash(){
	ll x=0;
	for(int i=0;i<n;i++){
		x=(x+now[i])*999983;
	}
	return x;
}


void dfs(){
	
	ll myV=calcV();
	glbV=min(glbV,myV);
	cout<<glbV<<endl;
	
	vis[calcHash()]=true;
	
	for(int i=1;i<n-1;i++){
		int tmp=now[i];
		now[i]=now[i-1]+now[i+1]-now[i];
		if(!vis[calcHash()] && calcV()<myV){
			dfs();
		}
		
		now[i]=tmp;
	}
	
	for(int i=1;i<n-1;i++){
		int tmp=now[i];
		now[i]=now[i-1]+now[i+1]-now[i];
		if(!vis[calcHash()] && calcV()>=myV){
			dfs();
		}
		
		now[i]=tmp;
	}
}

int main(){
	freopen("variance.in","r",stdin);
	#ifndef XGN
	freopen("variance.out","w",stdout);
	#endif
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		now[i]=a[i];
	}
	
	dfs();
	
	cout<<glbV<<endl;
	return 0;
}

Another discarded program:

int n;
int a[10005];

ll calcHash(){
	ll x=0;
	for(int i=0;i<n;i++){
		x=(x+now[i])*999983;
	}
	return x;
}

ll calcV(){
	int avg=0;
	for(int i=0;i<n;i++){
		avg+=now[i]*n;
	}
	avg/=n;
	
	ll v=0;
	for(int i=0;i<n;i++){
		ll delta=(now[i]*n-avg);
		v+=delta*delta;
	}
	
	return v/n;
}

int main(){
	freopen("variance.in","r",stdin);
	#ifndef XGN
	freopen("variance.out","w",stdout);
	#endif
	
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	
	queue<int> q;
	
	return 0;
}
                                                
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
*/
