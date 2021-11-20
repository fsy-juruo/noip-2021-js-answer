#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
using namespace std;
void read(int &x)
{
	int s=0,f=1;char c;
	while((c=getchar())>'9'||c<'0') if(c=='-') f=-1;
	s=(c&15);
	while((c=getchar())>='0'&&c<='9') s=s*10+(c&15);
	x=s*f;
}
int t,n,m,q,i,j,a[200005],col[200005],lv[200005],px[200005],py[200005],ans[200005];
int typr[200005],typc[200005],_;
int id(int x,int y){return (x-1)*m+y;}
int idr(int x,int y){return (y-1)*n+x;}
int rev(int id)
{
	int x=(id-1)/m+1,y=(id-1)%m+1;
	return idr(x,y);
}
bool checku(int x,int y){return x!=1&&typc[id(x-1,y)]==_;}
bool checkd(int x,int y){return x!=n&&typc[id(x,y)]==_;}
bool checkl(int x,int y){return y!=1&&typr[id(x,y-1)]==_;}
bool checkr(int x,int y){return y!=m&&typr[id(x,y)]==_;}
namespace solve123
{
	struct dsu
	{
		int fa[200005],sz[200005];
		int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
		void init(int n){int i;fz1(i,n) fa[i]=i,sz[i]=1;}
		void merge(int x,int y)
		{
			x=fnd(x);y=fnd(y);if(x==y)return;
			sz[y]+=sz[x];fa[x]=y;
		}
	}fu,fd,fl,fr;
	int lc[32000005],rc[32000005],sum[32000005],cnt;
	int nwnd(){cnt++;lc[cnt]=rc[cnt]=sum[cnt]=0;return cnt;}
	void update(int &x,int l,int r,int y,int c)
	{
		if(!x) x=nwnd();
		if(l==r){sum[x]=c;return;}
		int mid=(l+r)/2;
		if(y<=mid) update(lc[x],l,mid,y,c); else update(rc[x],mid+1,r,y,c);
		sum[x]=sum[lc[x]]+sum[rc[x]];
	}
	void segmerge(int &x,int y,int l,int r)
	{
		if(!x||!y){x+=y;return;}
		if(l==r){sum[x]|=sum[y];return;}
		int mid=(l+r)/2;
		segmerge(lc[x],lc[y],l,mid);
		segmerge(rc[x],rc[y],mid+1,r);
		sum[x]=sum[lc[x]]+sum[rc[x]];
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(!x) return 0;
		if(ql<=l&&r<=qr) return sum[x];
		int mid=(l+r)/2,s=0;
		if(ql<=mid) s+=query(lc[x],l,mid,ql,qr);
		if(qr>mid) s+=query(rc[x],mid+1,r,ql,qr);
		return s;
	}
	int fa[200005],sz[200005],rt[200005][2],rtr[200005],rtc[200005];
	int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
	void init(int n)
	{
		int i;cnt=0;
		fz1(i,n) fa[i]=i,sz[i]=1,rt[i][0]=rt[i][1]=rtr[i]=rtc[i]=0;
	}
	void merge(int x,int y)
	{
		x=fnd(x);y=fnd(y);if(x==y)return;
		sz[y]+=sz[x];fa[x]=y;
		segmerge(rt[y][0],rt[x][0],1,q);
		segmerge(rt[y][1],rt[x][1],1,q);
		segmerge(rtr[y],rtr[x],1,n*m);
		segmerge(rtc[y],rtc[x],1,n*m);
	}
	void solve()
	{
		_=2;int i;
		fz1(i,n*m) a[i]=0;
		fz1(i,q) a[id(px[i],py[i])]=i;
		fu.init(n*m);fd.init(n*m);fl.init(n*m);fr.init(n*m);
		fz1(i,n)fz1(j,m){
			if(checkr(i,j)){
				int cx=id(i,j),cy=id(i,j+1);
				if(!a[cx]&&!a[cy]) fr.merge(cx,cy),fl.merge(cy,cx);
			}
			if(checkd(i,j)){
				int cx=id(i,j),cy=id(i+1,j);
				if(!a[cx]&&!a[cy]) fd.merge(cx,cy),fu.merge(cy,cx);
			}
		}
		_=3;
		init(n*m);
		fz1(i,n)fz1(j,m){
			if(checkr(i,j)){
				int cx=id(i,j),cy=id(i,j+1);
				if(!a[cx]&&!a[cy]) merge(cx,cy);
			}
			if(checkd(i,j)){
				int cx=id(i,j),cy=id(i+1,j);
				if(!a[cx]&&!a[cy]) merge(cx,cy);
			}
		}
		fz1(i,n*m) update(rtr[fnd(i)],1,n*m,i,1),update(rtc[fnd(i)],1,n*m,rev(i),1);
		fz1(i,q){
			a[id(px[i],py[i])]=i;
			if(checku(px[i],py[i])) update(rt[fnd(id(px[i]-1,py[i]))][col[i]],1,q,lv[i],1);
			if(checkd(px[i],py[i])) update(rt[fnd(id(px[i]+1,py[i]))][col[i]],1,q,lv[i],1);
			if(checkl(px[i],py[i])) update(rt[fnd(id(px[i],py[i]-1))][col[i]],1,q,lv[i],1);
			if(checkr(px[i],py[i])) update(rt[fnd(id(px[i],py[i]+1))][col[i]],1,q,lv[i],1);
		}
		fd1(i,q){
			_=2;
			a[id(px[i],py[i])]=0;
			if(checkr(px[i],py[i])){
				int cx=id(px[i],py[i]),cy=id(px[i],py[i]+1);
				if(!a[cx]&&!a[cy]) fr.merge(cx,cy),fl.merge(cy,cx);
			}
			if(checkl(px[i],py[i])){
				int cx=id(px[i],py[i]-1),cy=id(px[i],py[i]);
				if(!a[cx]&&!a[cy]) fr.merge(cx,cy),fl.merge(cy,cx);
			}
			if(checkd(px[i],py[i])){
				int cx=id(px[i],py[i]),cy=id(px[i]+1,py[i]);
				if(!a[cx]&&!a[cy]) fd.merge(cx,cy),fu.merge(cy,cx);
			}
			if(checku(px[i],py[i])){
				int cx=id(px[i]-1,py[i]),cy=id(px[i],py[i]);
				if(!a[cx]&&!a[cy]) fd.merge(cx,cy),fu.merge(cy,cx);
			}
			
			_=3;
			if(checku(px[i],py[i])) update(rt[fnd(id(px[i]-1,py[i]))][col[i]],1,q,lv[i],0);
			if(checkd(px[i],py[i])) update(rt[fnd(id(px[i]+1,py[i]))][col[i]],1,q,lv[i],0);
			if(checkl(px[i],py[i])) update(rt[fnd(id(px[i],py[i]-1))][col[i]],1,q,lv[i],0);
			if(checkr(px[i],py[i])) update(rt[fnd(id(px[i],py[i]+1))][col[i]],1,q,lv[i],0);
			if(checkr(px[i],py[i])){
				int cx=id(px[i],py[i]),cy=id(px[i],py[i]+1);
				if(!a[cx]&&!a[cy]) merge(cx,cy);
			}
			if(checkl(px[i],py[i])){
				int cx=id(px[i],py[i]-1),cy=id(px[i],py[i]);
				if(!a[cx]&&!a[cy]) merge(cx,cy);
			}
			if(checkd(px[i],py[i])){
				int cx=id(px[i],py[i]),cy=id(px[i]+1,py[i]);
				if(!a[cx]&&!a[cy]) merge(cx,cy);
			}
			if(checku(px[i],py[i])){
				int cx=id(px[i]-1,py[i]),cy=id(px[i],py[i]);
				if(!a[cx]&&!a[cy]) merge(cx,cy);
			}
			
			ans[i]+=sz[fnd(id(px[i],py[i]))]-1;
			ans[i]-=query(rtr[fnd(id(px[i],py[i]))],1,n*m,fl.fnd(id(px[i],py[i])),fr.fnd(id(px[i],py[i])))-1;
			ans[i]-=query(rtc[fnd(id(px[i],py[i]))],1,n*m,rev(fu.fnd(id(px[i],py[i]))),rev(fd.fnd(id(px[i],py[i]))))-1;
			
			ans[i]+=rev(id(px[i],py[i]))-rev(fu.fnd(id(px[i],py[i])));
			ans[i]+=rev(fd.fnd(id(px[i],py[i])))-rev(id(px[i],py[i]));
			ans[i]+=id(px[i],py[i])-fl.fnd(id(px[i],py[i]));
			ans[i]+=fr.fnd(id(px[i],py[i]))-id(px[i],py[i]);
			
			ans[i]+=query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,1,lv[i]);
			_=2;int x,y,t;
			t=fu.fnd(id(px[i],py[i]));x=(t-1)/m+1;y=(t-1)%m+1;
			if(checku(x,y)&&col[a[id(x-1,y)]]!=col[i]&&lv[i]>=lv[a[id(x-1,y)]]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(x-1,y)]],lv[a[id(x-1,y)]])) ans[i]++;
			t=fd.fnd(id(px[i],py[i]));x=(t-1)/m+1;y=(t-1)%m+1;
			if(checkd(x,y)&&col[a[id(x+1,y)]]!=col[i]&&lv[i]>=lv[a[id(x+1,y)]]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(x+1,y)]],lv[a[id(x+1,y)]])) ans[i]++;
			t=fl.fnd(id(px[i],py[i]));x=(t-1)/m+1;y=(t-1)%m+1;
			if(checkl(x,y)&&col[a[id(x,y-1)]]!=col[i]&&lv[i]>=lv[a[id(x,y-1)]]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(x,y-1)]],lv[a[id(x,y-1)]])) ans[i]++;
			t=fr.fnd(id(px[i],py[i]));x=(t-1)/m+1;y=(t-1)%m+1;
			if(checkr(x,y)&&col[a[id(x,y+1)]]!=col[i]&&lv[i]>=lv[a[id(x,y+1)]]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(x,y+1)]],lv[a[id(x,y+1)]])) ans[i]++;
			
			_=1;
			if(checku(px[i],py[i])){
				int t=a[id(px[i]-1,py[i])];
				if(!t) ans[i]+=(!query(rtr[fnd(id(px[i],py[i]))],1,n*m,id(px[i]-1,py[i]),id(px[i]-1,py[i]))); 
				else ans[i]+=(col[i]!=col[t]&&lv[i]>=lv[t]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(px[i]-1,py[i])]],lv[a[id(px[i]-1,py[i])]]));
			}
			if(checkd(px[i],py[i])){
				int t=a[id(px[i]+1,py[i])];
				if(!t) ans[i]+=(!query(rtr[fnd(id(px[i],py[i]))],1,n*m,id(px[i]+1,py[i]),id(px[i]+1,py[i]))); 
				else ans[i]+=(col[i]!=col[t]&&lv[i]>=lv[t]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(px[i]+1,py[i])]],lv[a[id(px[i]+1,py[i])]]));
			}
			if(checkl(px[i],py[i])){
				int t=a[id(px[i],py[i]-1)];
				if(!t) ans[i]+=(!query(rtr[fnd(id(px[i],py[i]))],1,n*m,id(px[i],py[i]-1),id(px[i],py[i]-1))); 
				else ans[i]+=(col[i]!=col[t]&&lv[i]>=lv[t]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(px[i],py[i]-1)]],lv[a[id(px[i],py[i]-1)]]));
			}
			if(checkr(px[i],py[i])){
				int t=a[id(px[i],py[i]+1)];
				if(!t) ans[i]+=(!query(rtr[fnd(id(px[i],py[i]))],1,n*m,id(px[i],py[i]+1),id(px[i],py[i]+1))); 
				else ans[i]+=(col[i]!=col[t]&&lv[i]>=lv[t]&&!query(rt[fnd(id(px[i],py[i]))][!col[i]],1,q,lv[a[id(px[i],py[i]+1)]],lv[a[id(px[i],py[i]+1)]]));
			}
		}
//		cerr<<cnt<<endl;
	}
}
int cc[200005];
void relevel()
{
	int i;
	fz1(i,q) cc[i]=0;
	fz1(i,q) cc[lv[i]]++;
	fz1(i,q) cc[i]+=cc[i-1];
	fd1(i,q) lv[i]=(cc[lv[i]]--);
}
int main()
{
//	cerr<<sizeof(solve123::lc)*3/1048576<<endl;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(t);
	while(t--){
		read(n);read(m);read(q);
		fz1(i,n)fz1(j,m-1){
			char c;while((c=getchar())<'0'||c>'3');
			typr[id(i,j)]=(c&15);
		}
		fz1(i,n-1)fz1(j,m){
			char c;while((c=getchar())<'0'||c>'3');
			typc[id(i,j)]=(c&15);
		}
		fz1(i,q){
			read(col[i]);read(lv[i]);read(px[i]);read(py[i]);
			ans[i]=0;
		}
		relevel();
//		solve1::solve();
//		solve2::solve();
//		solve3::solve(); 
		solve123::solve();
		fz1(i,q){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
