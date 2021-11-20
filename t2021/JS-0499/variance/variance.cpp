#include<bits/stdc++.h>
using namespace std;
int a[10005];
set<vector<int> >s;
queue<vector<int> >q;
vector<int>v1;
int n;
void bfs(){
	for(int i=0;i<n;i++)v1.push_back(a[i]);
	q.push(v1);
	s.insert(v1);
	while(!q.empty()){
		v1=q.front();q.pop();
//		for(int i=0;i<n;i++)printf("%d ",v1[i]);
//		printf("\n");
		for(int i=1;i<n-1;i++){
			v1[i]=v1[i-1]+v1[i+1]-v1[i];
			if(s.find(v1)==s.end()){
				s.insert(v1);
				q.push(v1);
			}
			v1[i]=v1[i-1]+v1[i+1]-v1[i];
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	bfs();
	int mn=0x3f3f3f3f;
	for(set<vector<int> >::iterator it=s.begin();it!=s.end();it++){
		v1=*it;
		int sum=0,ans=0;
		for(int i=0;i<n;i++)sum+=v1[i];
		for(int i=0;i<n;i++)ans+=n*v1[i]*v1[i];
		ans-=sum*sum;
		mn=min(mn,ans);
	}
	printf("%d",mn);
	return 0;
}
