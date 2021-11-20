/*
吾令羲和弭节兮
望崦嵫而勿迫 
路曼曼其修远兮
吾将上下而求索 
*/
#include<bits/stdc++.h>
using namespace std;
int ttttt,maxx,cnt;
bool test[10000010],p[10000010];
int ans[200010];
pair<int,int>a[200010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ttttt;
	for(int i=1;i<=ttttt;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+ttttt+1);
	maxx=min(2*a[ttttt].first,10000001);
	for(int i=1;i<=maxx;i++){
		if(i%10==7||p[i/10])p[i]=true;
		if(test[i])continue;
		if(p[i]){
			test[i]=1;
			for(int j=1;i*j<=maxx;j++)test[i*j]=true;
		}
	}
	int x=a[1].first;
	for(int i=1;i<=ttttt;i++){
		while(i<=ttttt&&a[i].first==a[i-1].first)ans[a[i].second]=ans[a[i-1].second],i++;
		while(i<=ttttt&&x>a[i].first)ans[a[i].second]=-1,i++;
		if(i>ttttt)break;
		x=a[i].first;
		if(test[x]){
			ans[a[i].second]=-1;
			continue;
		}
		x++;
		while(test[x])x++;
		ans[a[i].second]=x;
	}
	for(int i=1;i<=ttttt;i++)cout<<ans[i]<<endl;
	return 0;
}
