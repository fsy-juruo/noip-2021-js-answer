#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std; 
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}

const int Maxn=200005;
const int Maxm=6000005;
int M1[Maxn],M2[Maxn],U2[Maxn],D2[Maxn],L2[Maxn],R2[Maxn];
int n,m,q;
char tmp[Maxn];
int qx[Maxn],qy[Maxn],ql[Maxn],qc[Maxn];
int qL[Maxn],qR[Maxn],qU[Maxn],qD[Maxn];
int ansHW[Maxn],ansC[Maxn],ansCM[Maxn];
set<int> OCCX[Maxn],OCCY[Maxn];
int SETCOL[Maxn],SETLVL[Maxn];vector<int> G[Maxn]; 
vector<int> SPC[Maxn]; //special Check
bool ban[Maxn];
int par[Maxn],siz[Maxn],rtX[Maxn],rtY[Maxn],rtN[Maxn];
int lX[Maxm],lY[Maxm],rX[Maxm],rY[Maxm],lN[Maxm],rN[Maxm],valX[Maxm],valY[Maxm],valN0[Maxm],valN1[Maxm],kX,kY,kN;
int banC[Maxn],banL[Maxn];
void Clear(){
	
	kX=0;kY=0;kN=0;
	memset(par,0,sizeof(par));
	memset(rtX,0,sizeof(rtX));
	memset(rtX,0,sizeof(rtY));
	memset(rtX,0,sizeof(rtN));
	for (int i=0;i<Maxm;i++) lX[i]=lY[i]=rX[i]=rY[i]=lN[i]=rN[i]=valX[i]=valY[i]=valN0[i]=valN1[i]=0;
	for (int i=0;i<Maxn;i++){
		OCCX[i].clear();OCCY[i].clear();G[i].clear();SPC[i].clear();
	}
	memset(rtX,0,sizeof(rtX));
	memset(rtY,0,sizeof(rtY));
	memset(rtN,0,sizeof(rtN));
	memset(M1,0,sizeof(M1));memset(M2,0,sizeof(M2));
	memset(U2,0,sizeof(U2));memset(D2,0,sizeof(D2));
	memset(L2,0,sizeof(L2));memset(R2,0,sizeof(R2));
	memset(ban,0,sizeof(ban));memset(siz,0,sizeof(siz));
	memset(banC,0,sizeof(banC));memset(banL,0,sizeof(banL));
	memset(ansHW,0,sizeof(ansHW));
	memset(ansC,0,sizeof(ansC));
	memset(ansCM,0,sizeof(ansCM));
}
int id(int x,int y){
	return (x-1)*m+y;
}
int id2(int x,int y){
	return (y-1)*n+x;
}
void SolveLRUD(){
	for (int i=1;i<=n;i++){
		L2[id(i,1)]=1;
		for (int j=2;j<=m;j++){
			if (M1[id(i,j-1)]==2) L2[id(i,j)]=L2[id(i,j-1)];
			else L2[id(i,j)]=j;
		}
		
		R2[id(i,m)]=m;
		for (int j=m-1;j>=1;j--){
			if (M1[id(i,j)]==2) R2[id(i,j)]=R2[id(i,j+1)];
			else R2[id(i,j)]=j;
		}
	}
	
	for (int j=1;j<=m;j++){
		
		U2[id(1,j)]=1;
		for (int i=2;i<=n;i++){
			if (M2[id(i-1,j)]==2) U2[id(i,j)]=U2[id(i-1,j)];
			else U2[id(i,j)]=i;
		}
		
		D2[id(n,j)]=n;
		for (int i=n-1;i>=1;i--){
			if (M2[id(i,j)]==2) D2[id(i,j)]=D2[id(i+1,j)];
			else D2[id(i,j)]=i;
		}
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (j && M1[id(i,j-1)]==1){
				L2[id(i,j)]=j-1;
			}
			if (j<m && M1[id(i,j)]==1){
				R2[id(i,j)]=j+1;
			}
			
			if (i>1 && M2[id(i-1,j)]==1){
				U2[id(i,j)]=i-1;
			}
			
			if (i<n && M2[id(i,j)]==1){
				D2[id(i,j)]=i+1;
			}
		}
	}
}


void GetLRUD(){
	for (int i=0;i<Maxn;i++) SETCOL[i]=SETLVL[i]=-1;
	for (int i=1;i<=n;i++) OCCX[i].insert(0),OCCX[i].insert(m+1);
	for (int i=1;i<=m;i++) OCCY[i].insert(0),OCCY[i].insert(n+1);
	
	for (int i=0;i<q;i++){
		int x=qx[i],y=qy[i];
	//	cerr<<i<<' '<<x<<" "<<y<<endl;
		int L,R,U,D;
		set<int>::iterator it=OCCX[x].lower_bound(y);
		
		R=(*it)-1;it--;L=(*it)+1;
		
		it=OCCY[y].lower_bound(x);
		
		D=(*it)-1;it--;U=(*it)+1;
		
		OCCX[x].insert(y);OCCY[y].insert(x);
		
		qL[i]=max(L,L2[id(x,y)]);
		qR[i]=min(R,R2[id(x,y)]);
		qU[i]=max(U,U2[id(x,y)]);
		qD[i]=min(D,D2[id(x,y)]);
		
		ansHW[i]=(qR[i]-qL[i]+1)+(qD[i]-qU[i]);
		
		if (qL[i]!=1 && L2[id(x,y)]<qL[i] && SETCOL[id(x,qL[i]-1)]==1-qc[i] && SETLVL[id(x,qL[i]-1)]<=ql[i]){
			ansHW[i]++;
			SPC[i].pb(id(x,qL[i]-1));
		}
		
		if (qR[i]!=m && R2[id(x,y)]>qR[i] && SETCOL[id(x,qR[i]+1)]==1-qc[i] && SETLVL[id(x,qR[i]+1)]<=ql[i]){
			//cerr<<"!!!"<<endl;
			ansHW[i]++;
			SPC[i].pb(id(x,qR[i]+1));
		}
		
		if (qU[i]!=1 && U2[id(x,y)]<qU[i] && SETCOL[id(qU[i]-1,y)]==1-qc[i] && SETLVL[id(qU[i]-1,y)]<=ql[i]){
			ansHW[i]++;
			SPC[i].pb(id(qU[i]-1,y));
		}
		
		if (qD[i]!=n && D2[id(x,y)]>qD[i] && SETCOL[id(qD[i]+1,y)]==1-qc[i] && SETLVL[id(qD[i]+1,y)]<=ql[i]){
			ansHW[i]++;
			SPC[i].pb(id(qD[i]+1,y));
		}
		
		SETCOL[id(x,y)]=qc[i];
		SETLVL[id(x,y)]=ql[i];
	}
}

int findset(int x){
	return par[x]=(par[x]==x)?x:findset(par[x]);
}


void AddX(int &p,int l,int r,int pos,int val){
	if (!p){
		p=++kX;
	}
	if (l==r){
		valX[p]+=val;
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid) AddX(lX[p],l,mid,pos,val);
	else AddX(rX[p],mid+1,r,pos,val);
	valX[p]=valX[lX[p]]+valX[rX[p]];
}

void AddY(int &p,int l,int r,int pos,int val){
	if (!p){
		p=++kY;
	}
	if (l==r){
		valY[p]+=val;
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid) AddY(lY[p],l,mid,pos,val);
	else AddY(rY[p],mid+1,r,pos,val);
	valY[p]=valY[lY[p]]+valY[rY[p]];
}

void AddN0(int &p,int l,int r,int pos,int val){
	if (!p){
		p=++kN;
	}
	if (l==r){
		valN0[p]=val;
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid) AddN0(lN[p],l,mid,pos,val);
	else AddN0(rN[p],mid+1,r,pos,val);
	valN0[p]=valN0[lN[p]]+valN0[rN[p]];
}
void AddN1(int &p,int l,int r,int pos,int val){
	if (!p){
		p=++kN;
	}
	if (l==r){
		valN1[p]=val;
		return;
	}
	int mid=l+r>>1;
	if (pos<=mid) AddN1(lN[p],l,mid,pos,val);
	else AddN1(rN[p],mid+1,r,pos,val);
	valN1[p]=valN1[lN[p]]+valN1[rN[p]];
}

void MergeX(int &A,int B,int l,int r){
	if (!A){
		A=B;
		return;
	}
	if (!B) return;
	valX[A]+=valX[B];
	if (l==r) return;
	int mid=l+r>>1;
	MergeX(lX[A],lX[B],l,mid);
	MergeX(rX[A],rX[B],mid+1,r);
}

void MergeY(int &A,int B,int l,int r){
	if (!A){
		A=B;
		return;
	}
	if (!B) return;
	valY[A]+=valY[B];
	if (l==r) return;
	int mid=l+r>>1;
	MergeY(lY[A],lY[B],l,mid);
	MergeY(rY[A],rY[B],mid+1,r);
}

void MergeN(int &A,int B,int l,int r){
	if (!A){
		A=B;
		return;
	}
	if (!B) return;
	if (l==r){
		valN0[A]|=valN0[B];
		valN1[A]|=valN1[B];
		return;
	}
	int mid=l+r>>1;
	MergeN(lN[A],lN[B],l,mid);
	MergeN(rN[A],rN[B],mid+1,r);
	valN0[A]=valN0[lN[A]]+valN0[rN[A]];
	valN1[A]=valN1[lN[A]]+valN1[rN[A]];
}

int queryX(int p,int l,int r,int lo,int hi){
	if (!p) return 0;
	if (lo<=l && r<=hi){
		return valX[p];
	}
	int mid=l+r>>1;
	int ans=0;
	if (lo<=mid) ans+=queryX(lX[p],l,mid,lo,hi);
	if (hi>mid) ans+=queryX(rX[p],mid+1,r,lo,hi);
	return ans;
}

int queryY(int p,int l,int r,int lo,int hi){
	if (!p) return 0;
	if (lo<=l && r<=hi){
		return valY[p];
	}
	int mid=l+r>>1;
	int ans=0;
	if (lo<=mid) ans+=queryY(lY[p],l,mid,lo,hi);
	if (hi>mid) ans+=queryY(rY[p],mid+1,r,lo,hi);
	return ans;
}

int queryN0(int p,int l,int r,int lo,int hi){
	if (!p) return 0;
	if (lo<=l && r<=hi){
		return valN0[p];
	}
	int mid=l+r>>1;
	int ans=0;
	if (lo<=mid) ans+=queryN0(lN[p],l,mid,lo,hi);
	if (hi>mid) ans+=queryN0(rN[p],mid+1,r,lo,hi);
	return ans;
}

int queryN1(int p,int l,int r,int lo,int hi){
	if (!p) return 0;
	if (lo<=l && r<=hi){
		return valN1[p];
	}
	int mid=l+r>>1;
	int ans=0;
	if (lo<=mid) ans+=queryN1(lN[p],l,mid,lo,hi);
	if (hi>mid) ans+=queryN1(rN[p],mid+1,r,lo,hi);
	return ans;
}

void Union(int x,int y){
	//cerr<<"UUU"<<x<<" "<<y<<endl;
	x=findset(x);y=findset(y);
	if (x==y) return;
	par[y]=x;
	siz[x]+=siz[y]; 
	MergeX(rtX[x],rtX[y],1,n*m);
	MergeY(rtY[x],rtY[y],1,n*m);
	MergeN(rtN[x],rtN[y],1,q); 
}
void GetC(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<m;j++){
			if (M1[id(i,j)]==3){
				G[id(i,j)].pb(id(i,j+1));
				G[id(i,j+1)].pb(id(i,j));
			}
		}
	}
	for (int i=1;i<n;i++){
		for (int j=1;j<=m;j++){
			if (M2[id(i,j)]==3){
				G[id(i,j)].pb(id(i+1,j));
				G[id(i+1,j)].pb(id(i,j));
			}
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) par[id(i,j)]=id(i,j);
	memset(ban,0,sizeof(ban));
	
	for (int i=0;i<q;i++){
		ban[id(qx[i],qy[i])]=1;
		banC[id(qx[i],qy[i])]=qc[i];
		banL[id(qx[i],qy[i])]=ql[i];
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (!ban[id(i,j)]){
				siz[id(i,j)]=1;
				AddX(rtX[id(i,j)],1,n*m,id(i,j),1);
				AddY(rtY[id(i,j)],1,n*m,id2(i,j),1);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (!ban[id(i,j)]){
				for (int k=0;k<G[id(i,j)].size();k++){
					int u=G[id(i,j)][k];
					if (!ban[u]){
						Union(id(i,j),u);
					}
				}
			}
		}
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (ban[id(i,j)]){
				vector<int> C;
				for (int k=0;k<G[id(i,j)].size();k++){
					int u=G[id(i,j)][k];
					if (!ban[u]){
						C.pb(findset(u));
					}
				}
				sort(C.begin(),C.end());
				C.resize(unique(C.begin(),C.end())-C.begin());
				
				for (int _=0;_<C.size();_++){
					int c=C[_];
					if (banC[id(i,j)]) AddN1(rtN[c],1,q,banL[id(i,j)],1);
					else AddN0(rtN[c],1,q,banL[id(i,j)],1);
				}
			}
		}
	}
	
	for (int i=q-1;i>=0;i--){
		int x=qx[i],y=qy[i];
	//	cerr<<"UNBAN"<<" "<<id(x,y)<<endl;
	//	assert(ban[id(x,y)]);
		ban[id(x,y)]=0;
		vector<int> C,D;
		for (int k=0;k<G[id(x,y)].size();k++){
			int u=G[id(x,y)][k];
		//	cerr<<"ADJ"<<u<<endl;
			if (!ban[u]) C.pb(findset(u));
			else{
				D.pb(u);
			}
		}
		sort(C.begin(),C.end());
		C.resize(unique(C.begin(),C.end())-C.begin());
		
		for (int _=0;_<C.size();_++){
			int c=C[_];
			AddN0(rtN[c],1,q,ql[i],0);
			AddN1(rtN[c],1,q,ql[i],0);
		}
		for (int _=0;_<D.size();_++){
			int c=D[_];
		//	cerr<<"NWWW"<<c<<endl;
			if (banC[c]) AddN1(rtN[id(x,y)],1,q,banL[c],1);
			else AddN0(rtN[id(x,y)],1,q,banL[c],1);
		}
		
		siz[id(x,y)]=1;
		AddX(rtX[id(x,y)],1,n*m,id(x,y),1);
		AddY(rtY[id(x,y)],1,n*m,id2(x,y),1);
	//	cerr<<id(x,y)<<' '<<findset(id(x,y))<<endl;
		for (int _=0;_<C.size();_++){
			int c=C[_];
			Union(id(x,y),c);
		}
		
		int rid=findset(id(x,y));
		
		ansC[i]=siz[rid];
	//	cerr<<"RID"<<' '<<ql[i]<<' '<<rid<<' '<<siz[rid]<<endl;
		
		if (qc[i]) ansC[i]+=queryN0(rtN[rid],1,q,1,ql[i]);
		else ansC[i]+=queryN1(rtN[rid],1,q,1,ql[i]);
		
	//	cerr<<"FFF"<<' '<<x<<" "<<y<<' '<<qU[i]<<' '<<qD[i]<<" "<<x<<endl;
		ansCM[i]+=queryX(rtX[rid],1,n*m,id(x,qL[i]),id(x,qR[i]));
		ansCM[i]+=queryY(rtY[rid],1,n*m,id2(qU[i],y),id2(qD[i],y));
	//	cerr<<"FFF"<<ansCM[i]<<endl;
		ansCM[i]--;
		
		for (int _=0;_<SPC[i].size();_++){
			int v=SPC[i][_];
			//front eat
			assert(ban[v]);
			bool flag=0;
			for (int __=0;__<G[v].size();__++){
				int t=G[v][__];
				if (findset(t)==rid){
					flag=true;
				}
			}
			if (flag) ansCM[i]++;
		}
	}
}

void FUCK(){
	vector<pair<int,int> > V;
	for (int i=0;i<q;i++){
		V.pb(mp(ql[i],i));
	}
	sort(V.begin(),V.end());
	for (int i=0;i<q;i++){
		ql[i]=lower_bound(V.begin(),V.end(),mp(ql[i],i))-V.begin()+1;
		//cerr<<"NW"<<i<<" "<<ql[i]<<endl;
	}
}


void mian(){
	Clear();
	n=read();m=read();q=read();
	for (int i=1;i<=n;i++){
		scanf("%s",tmp+1);
		for (int j=1;j<m;j++){
			assert(tmp[j]>='0' && tmp[j]<='3');
			M1[id(i,j)]=tmp[j]-'0';
			
		} 
	}
	for (int i=1;i<=n-1;i++){
		scanf("%s",tmp+1);
		for (int j=1;j<=m;j++){
			assert(tmp[j]>='0' && tmp[j]<='3');
			M2[id(i,j)]=tmp[j]-'0';
		} 
	}
	SolveLRUD();
	
	for (int i=0;i<q;i++){
		qc[i]=read();ql[i]=read();qx[i]=read();qy[i]=read();
	//	cerr<<i<<" "<<qx[i]<<' '<<qy[i]<<endl;
	}
	FUCK();
	
//	cerr<<"ENDFUCK"<<endl;
	
	GetLRUD();
	
//	cerr<<"END1"<<endl;
	
	GetC();
	
	for (int i=0;i<q;i++){
	//	cerr<<i<<' '<<ansHW[i]<<" "<<ansC[i]<<" "<<ansCM[i]<<endl;
		printf("%d\n",ansHW[i]+ansC[i]-ansCM[i]-1);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while (T--){
		mian();
	}
	return 0;
}
