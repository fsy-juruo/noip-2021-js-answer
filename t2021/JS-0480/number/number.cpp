#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=2e5+10;
bool p[M]; int nex[M];//每个数是不是7.以及下一个是什么 
int zhi[N],ret=0;//一个数的质因数 
int zs[N],zss=0; bool pp[M];//所有质数 
bool pd(int s){
	int ss=s;
	while(ss){
		if(ss%10==7) return true;
		ss/=10;
	}
	return false;
}//十进制中有无7
void shai(){
	for(int i=2;i<M;i++){
		if(pp[i]==false) zs[zss++]=i;
		for(int j=0;j<zss;j++){
			if(zs[j]*i>M||p[zs[j]*i]==true) break;
			pp[zs[j]*i]=true;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(p,0,sizeof(p)); memset(pp,0,sizeof(pp)); 
	shai();//线性筛素数 
	for(int i=1;i<200000;i++)
	{
		if(pd(i)==true) p[i]=true;
		else
		{//fjzys 
			int ss=i; ret=0;
			for(int j=0;j<N&&zs[j]<=ss;j++)
				while(ss%zs[j]==0) zhi[ret++]=zs[j],ss/=zs[j];
			for(int j=0;j<ret;j++)
				if(p[i/zhi[j]]==true) {p[i]=true; break;}
		}
		//printf("%d %d\n",i,p[i]);
	}
	int last=-1;
	for(int i=1;i<200000;i++)
	{
		if(last!=-1&&p[i]==0) nex[last]=i,last=i;
		else if(last==-1&&p[i]==0) last=i;
	}
	//for(int i=1;i<200000;i++) printf("%d %d\n",i,nex[i]);
	int t; scanf("%d",&t);
	while(t--)
	{
		int ss; scanf("%d",&ss);
		if(p[ss]==true) printf("-1\n");
		else printf("%d\n",nex[ss]);
	}
	return 0;
}
