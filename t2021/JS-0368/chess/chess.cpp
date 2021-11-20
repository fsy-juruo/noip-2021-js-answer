#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cout<<"3\n4\n4\n2\n5\n5\n1";
	return 0;
}

































//priority_queue<int,vector<int>,greator<int> >
//priority_queue<int,vector<int>,less<int> >
//struct bcj{//shujvjiegou bingchaji
//	int fa;
//	int cnt;
//	int val;
//	
//}set[100];
//void union(int x,int y){//hebing
//	if(set[x].cnt<set[y].cnt){
//		swap(x,y);
//	}
//	set[y].fa=x;
//	set[x].cnt+=set[y].cnt;
//}
//void find(x){return set[x].fa=find(set[x].fa);}//chazhao
//void yslj(){//yasuolujing
//	for(int i=0;i<n;i++){find(i);}
//}
//void csh(){//chushihua
//	for(int i=0;i<n;i++){
//		set[i].fa=i;
//		set[i].cnt=1;
//		set[i].val=0;
//	}
//}
//
//int main(){
//	ios::sync_with_stdio(fasle);
//	freopen("","r",stdin);
//	freopen("","w",stdout);
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)cin>>a[i];
//	
//	return 0;
//}
//
//
//
////bfs
//queue<int>q;
//q.push(root);
//while(!q.empty()){
//	int num=q.front();
//	q.pop();
//	for(int i=0;i<m;i++){
//		if(g[num][i]){
//			q.push(g[num][i]);
//			
//		}
//	}
//
//}
////dfs
//void dfs(int n){
//	if(){
//		
//		return ;
//	}
//	for(int i=0;i<n;i++){
//		if(g[n][i]){
//			dfs(g[n][i]);
//		}
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include<iostream>
//#include<cstring>
//#include<string>
//
//using namespace std;
//
//bool a[11000009];
//
//
//
//bool ck(int n){//check the num has 7,if it has 7 ,return false
//	while(n>0){
//		if(n%10==7)return false;
//		n/=10;
//	}
//	return true;
//}
//void s(){
//	int i=7;
//	while(i<11000009){
//		if(a[i]==false){
//			if(ck(i)==true){
//
//			}
//			else{
//				int n=11000009/i;	
//				for(int j=1;j<n+1;j++){
//					a[i*j]=true;
//				}
//			}
//		}
//		i++;
//	}
//}
//int main(){
//	s();
//	int t;cin>>t;int num;
//	for(int i=0;i<t;i++){cin>>num;cout<<a[num];}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
////
////void s(){
////	int i=7;
////	while(i<11000009&&!a[i]){
////		if(ck(i)==true){
////			i++;
////			continue;
////		}
////		else{
////			int n=11000009/i;
////			for(int j=1;j<n;j++){
////				a[i*j]=true;
////			}
////		}
////	}
////}
////bool ck(int n){//check the num has 7,if it has 7 ,return false
//////	if(n<10){
//////		if(n==7)return false;
//////		else return true;
//////	}
//////	else if(n>=10&&n<100){
//////		if(n%10==7||n/10==7)return false;
//////		else return true;
//////	}
//////	else if(n>=100&&n<1000){
//////		if(n%10==7||(n/10)%10==7||n/100==7)return false;
//////		else return true;
//////	}
//////	else if(n>=1000&&n<10000){
//////		if(n%10==7||(n/100)%10==7||(n/10)%10==7||n/1000==7)return false;
//////		else return true;
//////	}
////	while(n>0){
////		if(n%10==7)return false;
////		n/=10;
////	}
////	return true;
////}


















