/*
WARNING: THIS CODE IS UNFINISHED!
FOR ARCHIVING ONLY.

WARNING: THIS CODE IS UNFINISHED!
FOR ARCHIVING ONLY.

WARNING: THIS CODE IS UNFINISHED!
FOR ARCHIVING ONLY.
*/

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

struct Query{
	int col,lv,x,y;
};
struct Edge{
	bool hor;
	int x,y;
	Edge(bool _hor,int _x,int _y){
		hor=_hor;
		x=_x;
		y=_y;
	}
	Edge(){
		
	}
};

bool operator==(Edge& a,Edge& b){
    return a.hor==b.hor && a.x==b.x && a.y==b.y;
}

bool operator<(const Edge a,const Edge b){
    if(a.x!=b.x){
    	return a.x<b.x;
	}
	return a.y<b.y;
}


int n,m,q;
string s[2][200005];

Query que[200005];
 
char _tmp[200005];

/**
Subtask1-6,7-8,9-11,17-18,19-21
Too hard to write! Give up!
*/
namespace Subtask1{
	bool lvInc,lvDec;
	
	vector<int> hfep[200005],vfep[200005]; //horizontal fast-speed road end point
	set<pii> hc[200005],vc[200005]; //horizontal chess of each line {pos,id}
	map<Edge,Edge> fa; //dsu
	map<Edge,Edge> duse; //what ccip are we using?
	map<pii,int> onb;
	map<Edge,set<pii>> ccip;
	int ans[200005];
	
	Edge getFa(Edge e){
		if(fa[e]==e){
			return e;
		}
		return fa[e]=getFa(fa[e]);
	}
	
	void Union(Edge a, Edge b){
		a=getFa(a);
		b=getFa(b);
		if(a==b){
			return;
		}
		
		int sza=ccip[duse[a]].size();
		int szb=ccip[duse[b]].size();
		if(sza>szb){
			swap(a,b);
		}
		
		fa[a]=b;
		for(auto x:ccip[duse[a]]){
			ccip[duse[b]].insert(x);
		}
		ccip[duse[a]].clear();
	}
	
	void UnionAll(int i,int j){
		vector<Edge> own;
		if(i!=0){
			own.push_back(Edge(false,i-1,j));
		}
		if(i!=n-1){
			own.push_back(Edge(false,i,j));
		}
		if(j!=0){
			own.push_back(Edge(true,i,j-1));
		}
		if(j!=m-1){
			own.push_back(Edge(true,i,j));
		}
		for(int i=0;i<own.size();i++){
			for(int j=i+1;j<own.size();j++){
				Union(own[i],own[j]);
			}
		}
	}
	
	inline bool canEat(Query& q,int x,int y){
		if(onb[make_pair(x,y)]==-1){
			return true;
		}
		Query other=que[onb[make_pair(x,y)]];
		if(other.col==q.col || other.lv>q.lv){
			return false;
		}else{
			return true;
		}
	}
	
	void solve(bool a,bool b){
		lvInc=a;
		lvDec=b;
		
		//horizontal endpoint
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int ep=0;
				if(j==0 || s[0][i][j-1]!='1'){
					ep++;
				}
				if(j==m-1 || s[0][i][j]!='1'){
					ep++;
				}
				if(ep==1){
					hfep[i].push_back(j);
				}
			}
		}
		
		//vertical endpoint
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				int ep=0;
				if(j==0 || s[1][j-1][i]!='1'){
					ep++;
				}
				if(j==n-1 || s[1][j][i]!='1'){
					ep++;
				}
				if(ep==1){
					vfep[i].push_back(j);
				}
			}
		}
		
		//put in set
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				onb[make_pair(i,j)]=-1;
			}
		}
		
		for(int i=0;i<q;i++){
			Query x=que[i];
			hc[x.x].insert(make_pair(x.y,i));
			vc[x.y].insert(make_pair(x.x,i));
			onb[make_pair(x.x,x.y)]=i;
		}
		
		//init dsu
		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++){
				Edge e=Edge(true,i,j);
				fa[e]=e;
				duse[e]=e;
				ccip[e].insert(make_pair(i,j));
				ccip[e].insert(make_pair(i,j+1));
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m;j++){
				Edge e=Edge(false,i,j);
				fa[e]=e;
				duse[e]=e;
				ccip[e].insert(make_pair(i,j));
				ccip[e].insert(make_pair(i+1,j));
			}
		}
		
		//connect dsu
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(onb[make_pair(i,j)]==-1){
					UnionAll(i,j);
				}
			}
		}
		
		//process queries
		for(int i=q-1;i>=0;i--){
			Query me=que[i];
			//up side
			int& res=ans[i];
			if(me.x!=0){
				if(s[1][me.x-1][me.y]=='1' && canEat(me,me.x-1,me.y)){
					res++;
				}
				if(s[1][me.x-1][me.y]=='2'){
					int id1=lower_bound(vfep[me.y].begin(),vfep[me.y].end(),me.x)-vfep[me.y].begin();
                    int val1,val2;
                    if(id1==0){
                        val1=0;
                    }else{
                        val1=vfep[me.y][id1-1];
                    }

                    auto id2=vc[me.y].lower_bound(make_pair(me.x,i));
                    id2--;
                    if(id2==vc[me.y].begin()){
                        val2=0;
                    }else{
                        val2=id2->first;

                        if(!canEat(me,id2->first,me.y)){
                            val2++;
                        }
                    }
                    
                    res+=me.x-max(val1,val2)+1;
				}
                if(s[1][me.x-1][me.y]=='3'){

                }
			}
			
		}
	}
}

/**
 * Subtask 1-6
 Give up due to paucity of time
 */
namespace Subtask2{
    
    struct Edge{
        int tox,toy;
        char type;
        Edge(int _x,int _y,char _t){
            tox=_x;
            toy=_y;
            type=_t;
        }
    };

    bool vis[5005][5005],vis2[5005][5005];
    int chess[5005][5005];
    vector<Edge> nei[5005][5005];

    inline bool canEat(Query& q,int x,int y){
		if(chess[x][y]==-1){
            return true;
        }
		Query other=que[chess[x][y]];
		if(other.col==q.col || other.lv>q.lv){
			return false;
		}else{
			return true;
		}
	}

    void solve(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                chess[i][j]=-1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0){
                    nei[i][j].push_back(Edge(i-1,j,s[1][i-1][j]));
                }
                if(i!=n-1){
                    nei[i][j].push_back(Edge(i+1,j,s[1][i][j]));
                }
                if(j!=0){
                    nei[i][j].push_back(Edge(i,j-1,s[0][i][j-1]));
                }
                if(j!=m-1){
                    nei[i][j].push_back(Edge(i,j+1,s[0][i][j]));
                }
            }
        }
        
        for(int i=0;i<q;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    vis2[j][k]=vis[j][k]=false;
                }
            }

            Query me=que[i];
            chess[me.x][me.y]=i;

            //up
            if(me.x!=0){
                if(s[1][me.x-1][me.y]=='1'){
                    vis[me.x-1][me.y]=true;
                }
                if(s[1][me.x-1][me.y]=='2'){
                   int now=me.x;
                   while(now>0 && s[1][me.x-1][me.y]=='2'){
                       now--;
                       vis[now][me.y]=true;
                   } 
                }
            }
            //down
            if(me.x!=n-1){
                if(s[1][me.x][me.y]=='1'){
                    vis[me.x][me.y]=true;
                }
                if(s[1][me.x][me.y]=='2'){
                   int now=me.x;
                   while(now<n-1 && s[1][me.x][me.y]=='2'){
                       now++;
                       vis[now][me.y]=true;
                   } 
                }
            }
            //left
            if(me.y!=0){
                if(s[0][me.x][me.y-1]=='1'){
                    vis[me.x][me.y-1]=true;
                }
                if(s[0][me.x][me.y-1]=='2'){
                   int now=me.y;
                   while(now>0 && s[0][me.x][me.y-1]=='2'){
                       now--;
                       vis[me.x][now]=true;
                   } 
                }
            }
            //right
            if(me.y!=m-1){
                if(s[0][me.x][me.y]=='1'){
                    vis[me.x][me.y]=true;
                }
                if(s[0][me.x][me.y]=='2'){
                   int now=me.y;
                   while(now>0 && s[0][me.x][me.y]=='2'){
                       now++;
                       if(chess[me.x][now]!=-1){
                           if(canEat(me,me.x,now)){
                               vis[me.x][now]=true;
                           }
                           break;
                       }
                       vis[me.x][now]=true;
                   } 
                }
            }
            
            //for operation 3
            queue<pii> q;
            q.push(make_pair(me.x,me.y));
            vis2[me.x][me.y]=true;
            while(!q.empty()){
                pii last=q.front();
                q.pop();

                for(Edge e:nei[last.first][last.second]){
                    if(vis2[e.tox][e.toy] || e.type!=3){
                        continue;
                    }
                    vis[e.tox][e.toy]=vis2[e.tox][e.toy]=true;
                    q.push(make_pair(e.tox,e.toy));
                }
            }
        }
    }
}

void solve(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++){
		scanf("%s",_tmp);
		s[0][i]=string(_tmp);
	}
	for(int i=0;i<n-1;i++){
		scanf("%s",_tmp);
		s[1][i]=string(_tmp);
	}
	
	bool lvInc=true,lvDec=true;
	for(int i=0;i<q;i++){
		scanf("%d%d%d%d",&que[i].col,&que[i].lv,&que[i].x,&que[i].y);
		
		if(que[i].lv!=i+1){
			lvInc=false;	
		}
		if(que[i].lv!=q-(i+1)+1){
			lvDec=false;
		}
		que[i].x--;
		que[i].y--;
	}
	
	Subtask1::solve(lvInc,lvDec);
}

int main(){
	freopen("chess.in","r",stdin);
	#ifndef XGN
	freopen("chess.out","w",stdout);
	#endif
	
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}

