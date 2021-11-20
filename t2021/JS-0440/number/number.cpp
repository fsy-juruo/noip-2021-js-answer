#include<bits/stdc++.h>
#define N 10000005
using namespace std; 
int T,x[200005],p[3000005],cnt,ans[10000005],mx,now;
bitset<N>vis1,vis2,vis3;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&x[i]);
		mx=max(mx,x[i]);		
	}
	for(int i=2;i<=10000000;i++){
		if(i%10==7||vis3[i/10])vis3[i]=vis2[i]=1;
		if(i%7==0)vis2[i]=1;
	}
	for(int i=2;i<=10000000;i++){
		if(!vis1[i]){
			for(int j=i;j<=10000000;j+=i){
				vis1[j]=1;
				if(vis2[i]||vis2[j/i])vis2[j]=1;
			}
		}
	}
	now=10000001;
	for(int i=10000000;i>=1;i--){
		ans[i]=now;
		if(!vis2[i])now=i;
	}
	for(int i=1;i<=T;i++){
		if(!vis2[x[i]])printf("%d\n",ans[x[i]]);
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
}
//T1代码
//洛谷打卡887天，差一天就888了！ 
//掐指一算，今天还是和npy wxt表白的第400天。
//所以能有400分吗（
//也没见到我CSP有300+分啊（ 
//所以这个代码肯定要上奇葩代码合集（
//求保护隐私（要是这边的全放出来估计一堆人都知道我是谁了 
//freopen("number.in","r",stdin);(诱捕器) 
//考前写的一些东西，希望考的时候可以RP++!
