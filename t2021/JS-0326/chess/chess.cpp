#include<bits/stdc++.h>
using namespace std;
inline void file(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
//规定数字与方向对应关系：上下左右 
const int dx[5]={0,-1,1,0,0};
const int dy[5]={0,0,0,-1,1};

#define maxn 200007
int n,m,q;
int dd[5];
char a[maxn];
struct node{
	int x,y,col,lv;//这个点已有的 
	int c[5];
}t[maxn];
int cnt;
int vis[maxn];
int ans;
inline void dfs(int x,int y,int col,int lv,int fx,int fy,int from){
	if(vis[x*n+y-n]==0)ans++;vis[x*n+y-n]=1;
	if(t[x*n+y-n].lv){
		if(t[fx*n+fy-n].lv>=t[x*n+y-n].lv&&t[fx*n+fy-n].col!=t[x*n+y-n].col){
		}else{
			ans--;
		//	vis[x*n+y-n]=0;
//			cout<<"fuck"<<' '<<x<<' '<<y<<' '<<fx<<' '<<fy<<' '<<from<<endl;
	
		}
		return;
	}
//	cout<<"fuck"<<' '<<x<<' '<<y<<' '<<fx<<' '<<fy<<' '<<from<<endl;
	
	for(register int i=1;i<=4;i++){
		if((from==2&&i==1)||(from==1&&i==2))continue;
		if((from==3&&i==4)||(from==4&&i==3))continue;
		if(x+dx[i]>n||x+dx[i]<=0||y+dy[i]>m||y+dy[i]<=0){
			continue;
		}//cout<<"dick6"<<' '<<x<<' '<<y<<' '<<i<<endl;
		if(t[x*n+y-n].c[i]!=t[fx*n+fy-n].c[from]){
//			cout<<t[x*n+y-n].c[i]<<' '<<t[fx*n+fy-n].c[from]<<endl;
			continue;
		}//cout<<"dick7"<<' '<<x<<' '<<y<<' '<<i<<endl;
		if(t[x*n+y-n].c[i]==1||t[x*n-n+y].c[i]==0){
			continue;
		}//cout<<"dick8"<<' '<<x<<' '<<y<<' '<<i<<endl;
		if(t[x*n+y-n].c[i]==2){
			if(i!=from)continue;
			else{
		//		if(vis[n*(x+dx[i]-1)+y+dy[i]])continue;
				dfs(x+dx[i],y+dy[i],col,lv,fx,fy,from);
			}
		}
//		cout<<"dick"<<' '<<x<<' '<<y<<' '<<i<<endl;
		if(t[x*n+y-n].c[i]==3){
		//	if(vis[n*(x+dx[i]-1)+y+dy[i]])continue;
//			cout<<"suck"<<' '<<x<<' '<<y<<endl;
			dfs(x+dx[i],y+dy[i],col,lv,fx,fy,i);
			//此处from其实没有意义 
		}
	}
}//}}
int main(){
	ios::sync_with_stdio(0);
	file();
	int T;
	cin>>T;
	while(T--){
		
	cin>>n>>m>>q;
	dd[1]=-m;dd[2]=m;dd[3]=-1;dd[4]=1;//
	for(register int i=1;i<=n;i++){
		cin>>a;
		int len=strlen(a);
		cnt++;
		t[cnt].y=i;t[cnt].x=1;
		t[cnt].c[3]=-1;//此路不通 
		t[cnt].c[4]=a[0]-'0';
		for(register int j=1;j<strlen(a);j++){
			cnt++;
			t[cnt].y=i;t[cnt].x=j+1;
			t[cnt].c[3]=a[j-1]-'0';
			t[cnt].c[4]=a[j]-'0';
		}
		cnt++;
		t[cnt].y=i;t[cnt].x=m;
		t[cnt].c[3]=a[m-2]-'0';t[cnt].c[4]=-1;
	}
	for(register int i=1;i<=m;i++){
		t[i].c[1]=-1;
		t[i+(n-1)*m].c[2]=-1;
	}
	//从第二列做起
	for(register int i=2;i<=n;i++){
		cin>>a;
		int len=strlen(a);
		for(register int j=0;j<len;j++){
			t[(i-2)*m+j+1].c[2]=a[j]-'0';
			t[(i-1)*m+j+1].c[1]=a[j]-'0';
		}
	} 
//	for(register int i=1;i<=cnt;i++){
//		cout<<t[i].x<<' '<<t[i].y<<' '<<t[i].c[1]<<' '<<t[i].c[2];
//		cout<<' '<<t[i].c[3]<<' '<<t[i].c[4]<<endl;
//	}
//可算调对了
//	swap(n,m);
	 for(register int i=1;i<=q;i++){
	 	int x,y,col,lv;ans=0;
	 	memset(vis,0,sizeof(vis));
	 	cin>>col>>lv>>x>>y;
	 	t[x*n+y-n].col=col;
	 	t[x*n+y-n].lv=lv;
	 	vis[x*n+y-n]=1;
	 	for(register int j=1;j<=4;j++){
	 		if(x+dx[j]>=1&&x+dx[j]<=n){
	 			if(y+dy[j]>=1&&y+dy[j]<=m){
	 				if(t[x*n+y-n].c[j]==0)continue;
	 				if(t[x*n+y+dd[j]-n].lv){
	 					if(t[x*n+y-n].lv>=t[x*n+y+dd[j]-n].lv&&t[x*n+y-n].col!=t[x*n+y+dd[j]-n].col){
	 						ans++;
						}
						continue;
					}
//					cout<<x+dx[j]<<' '<<y+dy[j]<<endl;
	 				dfs(x+dx[j],y+dy[j],col,lv,x,y,j);
				}
			}
		 }
	 	cout<<ans<<endl;
//	 	for(register int j=1;j<=n;j++){
//	 		for(register int di=1;di<=m;di++){
//	 			cout<<vis[(j-1)*m+di]<<' ';
//			 }cout<<endl;
//		 }
	 }}
	return 0;
}

