#include<bits/stdc++.h>
#define LL long long
#define MP  make_pair
#define mo 1000000007
using namespace std;
void read(int &sum){
	sum=0;char ch=getchar();int p=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')p=-1;
	for(; isdigit(ch);ch=getchar())sum=sum*10+ch-'0';
	sum=sum*p;
}
void write(int sum){
	if(sum<0){
		putchar('-');
		sum=0-sum;
	}
	if(sum>=10){
		write(sum/10);
		sum=sum%10;
	}
	putchar(sum+'0');
}
struct Edge{
	int v,Next;
}edge[200010];
int head[100010],tot=0;
void add(int x,int y){
	tot++;
	edge[tot].v=y;
	edge[tot].Next=head[x];
	head[x]=tot;
}
int a[10010];
LL b[10010],sum=0;
deque<vector<int> >q;
deque<int>p;
map<vector<int>,bool>ma;
LL ans=0x3f3f3f3f3f;
int n;
void work1(){
	vector<int>v;
	int i;
	for(i=1;i<=n;i++){
		v.push_back(a[i]);
	}
	q.push_back(v);
	ma[v]=1;
	while(q.size()){
		vector<int>v=q.front();
		q.pop_front();
		LL sum=0,s=0;
		for(i=0;i<n;i++){
			s+=v[i]*1ll; 
//			cout<<v[i]<<" ";
		}
//		cout<<endl;
		for(i=0;i<n;i++){
			sum+=(s-v[i]*1ll*n*1ll)*(s-v[i]*1ll*n*1ll);
		}
//		cout<<sum/(n*1ll)<<endl;
		ans=min(ans,sum/(n*1ll));
		for(i=1;i<=n-2;i++){
			if(v[i]==v[i-1]+v[i+1]-v[i]){
				continue;
			}
			v[i]=v[i-1]+v[i+1]-v[i];
			if(!ma.count(v)){
				q.push_back(v);
				ma[v]=1;
			}
			v[i]=v[i-1]+v[i+1]-v[i];
		}
	}	
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
//	int maxn=0;
int i;
	for(i=1;i<=n;i++){
		read(a[i]);
		b[i]=a[i]*1ll;
		b[i]*=n*1ll;
		sum+=b[i];
//		maxn=max(a[i],maxn);
	}
//	if(n<=4&&a[n]<=10){
		work1();		
//	}
	cout<<ans<<endl;
	return 0;
}


