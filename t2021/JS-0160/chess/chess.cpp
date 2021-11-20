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
	int v,w,Next;
}edge[400010];
int head[200010],tot=0;
void add(int x,int y,int z){
	tot++;
	edge[tot].v=y;
	edge[tot].Next=head[x];
	head[x]=tot;
	edge[tot].w=z;
}
int n,m,Q;
int vlv[200010],vcol[200010];
bool vis[200010];
int calc(int x,int y){
	return x*m-m+y;
} 
int ans=0;
bool vv[200010];
map<pair<int,pair<int,int> >,bool>ma;
void dfs(int dep,int col,int lv,int kin,int addnum){
//	cout<<(dep-1)/m+1<<' '<<(dep-1)%m+1<<' '<<kin<<' '<<addnum<<endl;
	int i;
	vis[dep]=1;
//	ans++;
	if(ma.count(MP(dep,MP(kin,addnum)))){
		vis[dep]=0;
		return ;
	}
	ma[MP(dep,MP(kin,addnum))]=1;
	vv[dep]=1;
	for(i=head[dep];i;i=edge[i].Next){
		
		int v=edge[i].v,w=edge[i].w;
//		cout<<" v "<<v<<" "<<w<<" "<<vis[v]<<endl;
		
		if(vis[v]){
			continue;
		}
//		cout<<"UF \n";
		if(kin!=0&&kin!=w){
			continue;
		}
//		cout<<" "<<vlv[v]<<' '<<vcol[v]<<endl;
		if(vlv[v]>lv||vcol[v]==col){
//			cout<<"have\n";
			continue;
		}
		if(w==1){
//			ans++;
			vv[v]=1;
//			vis[v]=1;
//			cout<<(v-1)/m+1<<" "<<(v-1)%m+1<<endl;
			continue;
		}
		if(w==2){
			if(v==dep+addnum||addnum==0){
				if(vlv[v]>=0){
//					ans++;
					vv[v]=1;
//					vis[v]=1;
//					cout<<(v-1)/m+1<<" "<<(v-1)%m+1<<endl;
					continue;
				}
				else{
					dfs(v,col,lv,2,v-dep);
				}
			}
		}
		if(w==3){
			if(vlv[v]>=1){
//				vis[v]=1;
//				cout<<(v-1)/m+1<<" "<<(v-1)%m+1<<endl;
				vv[v]=1;
//				ans++;
				continue;
			}
			else{
				dfs(v,col,lv,3,m+1);
			}
		}
	}
	vis[dep]=0;
}
void work1(){
	int i,j;
	for(i=1;i<=n*m;i++){
		vlv[i]=vcol[i]=-1;
	}
	for(i=1;i<=Q;i++){
		ma.clear();
		int x,y,col,lv,k;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=m;j++){
				vv[calc(k,j)]=0;
			}
//			cout<<endl;
		}
		read(col);read(lv);read(x);read(y);
		ans=0;
		dfs(calc(x,y),col,lv,0,0);
		for(k=1;k<=n;k++){
			for(j=1;j<=m;j++){
//				cout<<vv[calc(k,j)]<<" ";
				ans+=vv[calc(k,j)];
			}
//			cout<<endl;
		}
		write(ans-1);
		putchar('\n');
		vlv[calc(x,y)]=lv;
		vcol[calc(x,y)]=col;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T,i,j;
	read(T);
	while(T--){
//		cout<<"DDD\n";
		read(n);read(m);read(Q);
		tot=0;
		for(i=1;i<=n*m;i++){
			head[i]=0;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<m;j++){
				char ch=getchar();
				while(ch<'0'||ch>'3'){
					ch=getchar();
				}
				if(ch=='0'){
					continue;
				}
				add(calc(i,j),calc(i,j+1),ch-'0');
				add(calc(i,j+1),calc(i,j),ch-'0');
//				cout<<ch-'0'<<" ";
			}
//			cout<<endl;
		} 	
		for(i=1;i<n;i++){
			for(j=1;j<=m;j++){
				char ch=getchar();
				while(ch<'0'||ch>'3'){
					ch=getchar();
				}
				if(ch=='0'){
					continue;
				}
				add(calc(i+1,j),calc(i,j),ch-'0');
				add(calc(i,j),calc(i+1,j),ch-'0');
			}
		}	
		work1();	
	}

	return 0;
}


