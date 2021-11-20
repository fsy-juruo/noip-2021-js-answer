#include<bits/stdc++.h>
using namespace std;
int n,a[10005],del[10005],tot;
int v[605];
int f[2][605][6005];
int pre1[605][605],pre2[605][605];
int ans=1145141919;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	int mx=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(i>=2){
			del[i-1]=a[i]-a[i-1];
			v[del[i-1]]++;
		}
	}
	mx=a[n];
	for(int i=0;i<=mx;++i){
		for(int j=0;j<=mx;++j){
			pre1[i][j]=j;
			if(j-i>=0) pre1[i][j]+=pre1[i][j-i];
			pre2[i][j]=j*j;
			if(j-i>=0) pre2[i][j]+=pre2[i][j-i];
		}
	}
	sort(del+1,del+n);
	tot=unique(del+1,del+n)-del-1;
	for(int j=0;j<=mx;++j)
		for(int k=0;k<=n*mx;++k)
			f[0][j][k]=1145141919;
	f[0][0][a[1]]=a[1]*a[1];
	int pre=0,cur=1;
	int sm=0;
	for(int i=tot;i>=1;--i){
//		cerr<<del[i]<<endl<<v[del[i]]<<endl;
		for(int j=0;j<=mx;++j)
			for(int k=0;k<=n*mx;++k)
				f[cur][j][k]=1145141919;
		for(int j=0;j<=mx;++j)
			for(int k=0;k<=n*mx;++k)
				if(f[pre][j][k]!=1145141919){
//					assert(f[pre][j][k]!=0);
					for(int l=0;l<=v[del[i]];++l){
						int del1=0,del2=0;
//						if(l){
							if(del[i]==0){
								del1=(a[1]+j)*v[del[i]];
								del2=(a[1]+j)*(a[1]+j)*v[del[i]];
							}
							else{
							del1+=pre1[del[i]][a[1]+j+l*del[i]]-pre1[del[i]][a[1]+j];
							del2+=pre2[del[i]][a[1]+j+l*del[i]]-pre2[del[i]][a[1]+j];
//							int tot1=0,tot2=0,curv=a[1]+j+del[i];
//							puts("2331");
//							for(int p=1;p<=l;++p){
//								tot1+=curv;
//								tot2+=curv*curv;
//								curv+=del[i];
////								puts("2332");
//							}
//							if(tot1!=del1){
//								cerr<<del[i]<<" "<<
//							}
//							assert(tot1==del1);
//							assert(tot2==del2);
//							puts("2333");
//						}
//						if(v[del[i]]-l){
							int val=a[n]-(sm-j);
							del1+=pre1[del[i]][val]-pre1[del[i]][val-del[i]*(v[del[i]]-l)];
							del2+=pre2[del[i]][val]-pre2[del[i]][val-del[i]*(v[del[i]]-l)];
							}
//							curv=val;
//							for(int p=1;p<=v[del[i]]-l;++p){
//								tot1+=curv;
//								tot2+=curv*curv;
//								curv-=del[i];
//							}
//							if(tot1!=del1){
//								cerr<<i<<" "<<j<<" "<<l<<endl;
//							}
//							assert(tot1==del1);
//							assert(tot2==del2);
//							puts("2334");
//							assert(a[1]+j+l*del[i]<=val-del[i]*(v[del[i]]-l));
//						}
						//assert(j<=sm);
//						puts("2336");
//						cerr<<del1<<" "<<del2<<endl;
//						cerr<<j<<" "<<k<<endl;
//						cerr<<i<<" "<<j+l*del[i]<<" "<<k+del1<<" "<<endl; 
						//cerr<<cur<<endl;
						f[cur][j+l*del[i]][k+del1]=min(f[cur][j+l*del[i]][k+del1],f[pre][j][k]+del2);
//						cerr<<i<<" "<<j+l*del[i]<<" "<<k+del1<<" "<<f[cur][j+l*del[i]][k+del1]<<endl; 
//						puts("2335");
						if(i==1) break; 
					}
				}
		sm+=v[del[i]]*del[i];
		pre^=1,cur^=1;
//		puts("2331");
	}
	//assert(sm==a[n]-a[1]);
	for(int j=0;j<=mx;++j)
		for(int k=0;k<=n*mx;++k)
			if(f[pre][j][k]!=1145141919)
				ans=min(ans,f[pre][j][k]*n-k*k);
	printf("%d\n",ans);
	return 0;
}

