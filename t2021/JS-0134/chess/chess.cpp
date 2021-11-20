#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<int> roat[5][200005],roa[5][200005];
char c[200005];
int q[200005][5],res[200005];
bool vis[200005];
pair<int,int> al[200005];
int fa1[200005],mi1[200005],ma1[200005];
int fin1(int x){
	if(fa1[x]==x) return x; else return fa1[x]=fin1(fa1[x]);
}
int fa2[200005],mi2[200005],ma2[200005];
bool had21[200005],had22[200005];
int fin2(int x){
	if(fa2[x]==x) return x; else return fa2[x]=fin2(fa2[x]);
}
string  print(int x){
	stringstream ss;
	ss<<x/3+1<<","<<x%3+1;
	string s;
	ss>>s;
	return s;
}
int main(){
	int TT;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&TT);
	while(TT--){
		int n,m,T;
		scanf("%d %d %d",&n,&m,&T);
		memset(had21,0,sizeof had21);
		memset(had22,0,sizeof had22);
		memset(q,0,sizeof q);
		memset(res,0,sizeof res);
		int dx[]={-1,1,m,-m};
		for(int i=0;i<n;i++){
			scanf("%s",c);
			for(int j=0;j<m-1;j++){
				roat[c[j]-'0'][i*m+j].push_back(i*m+j+1);
				roat[c[j]-'0'][i*m+j+1].push_back(i*m+j);
				if(c[j]-'0'==2) had21[i*m+j]=1;
			}
		}
		for(int i=0;i<n-1;i++){
			scanf("%s",c);
			for(int j=0;j<m;j++){
				roat[c[j]-'0'][i*m+j].push_back(i*m+j+m);
				roat[c[j]-'0'][i*m+j+m].push_back(i*m+j);
				if(c[j]-'0'==2) had22[i*m+j]=1;
			}
		}
		for(int i=0;i<T;i++){
			int x,y;
			scanf("%d %d %d %d",&q[i][0],&q[i][1],&x,&y);
			q[i][2]=(x-1)*m+y-1;
		}
		if(n*m<=10000){
			for(int i=0;i<T;i++){
				queue<int> qu;
				memset(vis,0,sizeof vis);
				int ans=0;
				qu.push(q[i][2]);
				vis[q[i][2]]=1;
				while(!qu.empty()){
					int v=qu.front();
					qu.pop();
					for(int j=0;j<(int)roat[3][v].size();j++){
						int u=roat[3][v][j];
						if(vis[u]) continue;
						if(al[u]==make_pair(0,0)){
							vis[u]=1;
							ans++;
							qu.push(u);
						//	cout<<u/m+1<<","<<u%m<<"ha1"<<endl;;
						}
						else if(al[u].first!=q[i][0]&&al[u].second<=q[i][1]){
							vis[u]=1;
							ans++;//cout<<u/m+1<<","<<u%m<<"hae1"<<endl;;
						}
					}
				}
				const int v=q[i][2];
				for(int j=0;j<(int)roat[1][v].size();j++){
					int u=roat[1][v][j];
					if(vis[u]) continue;
					if(al[u]==make_pair(0,0)||(al[u].first!=q[i][0]&&al[u].second<=q[i][1])){
						vis[u]=1;
						ans++;
					//	cout<<u/m+1<<","<<u%m<<"ha2"<<endl;;
					}
				}
				for(int d=0;d<4;d++){
					int u=v;
					while(u!=-1){
						bool flag=0;
						for(int j=0;j<(int)roat[2][u].size();j++){
							int u2=roat[2][u][j];
							if(u2==u+dx[d]){
								if(al[u2]==make_pair(0,0)){
									flag=1;
									if(!vis[u2]){
										vis[u2]=1;
										ans++;
								//		cout<<u2/m+1<<","<<u2%m<<"ha3"<<" "<<al[u2].second<<" "<<d<<endl;;
									}u=u2;
								}
								else if(al[u2].first!=q[i][0]&&al[u2].second<=q[i][1]){
									if(!vis[u2]){
										vis[u2]=1;
										ans++;
//										cout<<u2/m+1<<","<<u2%m<<"hae3"<<endl;;
									}
								}
								break;
							}
						}
						if(!flag) u=-1;
					}
				}
				printf("%d\n",ans);
				al[v]=make_pair(q[i][0],q[i][1]);
			}
			
		}
		else{
			memset(fa1,0,sizeof fa1);
			memset(fa2,0,sizeof fa2);
			memset(mi1,0,sizeof mi1);
			memset(mi2,0,sizeof mi2);
			memset(ma1,0,sizeof ma1);
			memset(ma2,0,sizeof ma2);
			for(int i=0;i<=n*m;i++){
				fa1[i]=fa2[i]=mi1[i]=mi2[i]=ma1[i]=ma2[i]=i;
			}
			for(int i=0;i<T;i++){
				al[q[i][2]]=make_pair(q[i][0],q[i][1]);
			}
			for(int i=0;i<=n*m;i++){
				if(al[i]!=make_pair(0,0)) continue;
				for(int j=0;j<=4;j++){
					for(int k=0;k<(int)roat[j][i].size();k++){
						int u=roat[j][i][k];
						if(al[u]!=make_pair(0,0)) continue;
						roa[j][i].push_back(u);
					}
				}
				for(int j=0;j<(int)roa[2][i].size();j++){
					int u=roa[2][i][j];
					if(abs(i-u)==1){
						int fai=fin1(i),fau=fin1(u);
						fa1[fai]=fau;
						mi1[fau]=min(mi1[fai],mi1[fau]);
						ma1[fau]=max(ma1[fai],ma1[fau]);
					}
					else{
						int fai=fin2(i),fau=fin2(u);
						fa2[fai]=fau;
						mi2[fau]=min(mi2[fai],mi2[fau]);
						ma2[fau]=max(ma2[fai],ma2[fau]);
					}
				}
			}
			for(int i=T-1;i>=0;i--){
				int v=q[i][2];
				al[v]=make_pair(0,0);
				for(int j=0;j<(int)roat[2][v].size();j++){
					int u=roat[2][v][j];
					if(al[u]!=make_pair(0,0)) continue;
					if(abs(v-u)==1){
						int fai=fin1(v),fau=fin1(u);
						fa1[fai]=fau;
						mi1[fau]=min(mi1[fai],mi1[fau]);
						ma1[fau]=max(ma1[fai],ma1[fau]);
					}
					else{
						int fai=fin2(v),fau=fin2(u);
						fa2[fai]=fau;
						mi2[fau]=min(mi2[fai],mi2[fau]);
						ma2[fau]=max(ma2[fai],ma2[fau]);
					}
				}
				for(int j=0;j<(int)roat[1][v].size();j++){
					int u=roat[1][v][j];
					if(al[u]==make_pair(0,0)||(al[u].first!=q[i][0]&&al[u].second<=q[i][1])){
						res[i]++;
					}
				}
				int fai1=fin1(v),fai2=fin2(v);
				res[i]+=ma1[fai1]-mi1[fai1]+(ma2[fai2]-mi2[fai2])/m;
//				cout<<ma1[fai1]-mi1[fai1]+(ma2[fai2]-mi2[fai2])/m<<" "<<print(ma1[fai1])<<" "<<print(mi1[fai1])<<" "<<print(ma2[fai2])<<" "<<print(mi2[fai2])<<"haha"<<endl;
				if(ma1[fai1]%m!=(m-1)&&had21[ma1[fai1]]&&al[ma1[fai1]+1].first!=q[i][0]&&al[ma1[fai1]+1].second<=q[i][1]){
					res[i]++;
//					cout<<"haha1\n";
				}
				if(mi1[fai1]%m!=0&&had21[mi1[fai1]-1]&&al[mi1[fai1]-1].first!=q[i][0]&&al[mi1[fai1]-1].second<=q[i][1]){
					res[i]++;
//					cout<<"haha2\n";
				}
				if(ma2[fai2]+m<n*m&&had22[ma2[fai2]]&&al[ma2[fai2]+m].first!=q[i][0]&&al[ma2[fai2]+m].second<=q[i][1]){
					res[i]++;
//					cout<<"haha3\n";
				}
				if(mi2[fai2]-m>=0&&had22[mi2[fai2]-m]&&al[mi2[fai2]-m].first!=q[i][0]&&al[mi2[fai2]-m].second<=q[i][1]){
					res[i]++;
//					cout<<"haha4\n";
				}
			}
			for(int i=0;i<T;i++) printf("%d\n",res[i]);
		}
		for(int i=0;i<=n*m+100;i++){
			roa[0][i].clear();roa[1][i].clear();roa[2][i].clear();roa[3][i].clear();roa[4][i].clear();
			roat[0][i].clear();roat[1][i].clear();roat[2][i].clear();roat[3][i].clear();roat[4][i].clear();
			al[i]=make_pair(0,0); 
		}
	}
	return 0;
}
