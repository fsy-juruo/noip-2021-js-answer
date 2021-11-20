#include<bits/stdc++.h>
#define ls (x<<1)
#define rs ((x<<1)^1)
#define l tree[x].lll
#define r tree[x].rrr
#define mid ((l+r)>>1)
#define int long long
using namespace std;
inline int read()
{
	int b=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		b*=10;
		b+=c-'0';
		c=getchar();
	}
	return b;
}
struct node{
	int lll,rrr,num1,num2;
}tree[30000];
int n,val[10005],delta[10005],d;
void build(int ll,int rr,int x)
{
	l=ll;r=rr;
	if(l==r)
	{
		tree[x].num1=val[l]=read();
		tree[x].num2=tree[x].num1*tree[x].num1;
		if(l>2)
		{
			delta[l-1]=val[l-2]+val[l]-val[l-1]*2;
		}
		return;
	}
	build(ll,mid,ls);
	build(mid+1,rr,rs);
	tree[x].num1=tree[ls].num1+tree[rs].num1;
	tree[x].num2=tree[ls].num2+tree[rs].num2;
	return;
}
void change(int k,int x)
{
	if(l==r)
	{
		tree[x].num1+=delta[k];
		val[k]+=delta[k];
		tree[x].num2=tree[x].num1*tree[x].num1;
		if(k>2)delta[k-1]+=delta[k];
		if(k<n-1)delta[k+1]+=delta[k];
		delta[k]=val[k+1]+val[k-1]-val[k]*2;
		return;
	}
	if(k<=mid)change(k,ls);
	else change(k,rs);
	tree[x].num1=tree[ls].num1+tree[rs].num1;
	tree[x].num2=tree[ls].num2+tree[rs].num2;
}
int del(int k)
{
	if(delta[k]==0)return 0;
	int q=(delta[k]+tree[1].num1*2)*delta[k];
	q=n*(val[k]*2+delta[k])*delta[k]-q;
	return q;
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	build(1,n,1);
	bool flag=1;
	while(flag)
	{	
		flag=0;
		for(int i=2;i<n;++i)
		{
			if(del(i)<0){
				flag=1;
				change(i,1);
			}
		}
	}
	d=n*tree[1].num2-tree[1].num1*tree[1].num1;
	cout<<d<<endl;
	return 0;
}

