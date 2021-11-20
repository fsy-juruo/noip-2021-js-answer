#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=1000007;
int k;
int aaa[maxn];
int v;
bool pd1(int y) {
	int zh=y;
	while(zh!=0) {
		int jj=zh%10;
		if(jj==7)
			{
//				cout<<y<<"  ";
				v=2;
				return false;
			}		
		else {
			zh=zh/10;
			k++;
		}
	}
	return true;
}
bool pd2(int y) {
	if(y%7==0) return false;
	int zh=y;
	while(zh!=0) {
		int jj=zh%10;
		if(jj==7)
				return false;		
		else 
			zh=zh/10;
	}
	return true;
}
bool gys(int x) {
	if(!pd1(x)) return false;
//	cout<<"x:"<<x<<"k:"<<k<<endl;
//	cout<<"v:"<<v<<endl;
	int m=x/2;
	for(int i=2; i<=m; i++) {
		if(x%i==0) {
			if(!pd2(i)) {
//				cout<<"i:"<<i<<endl;
				return false;
			}
			if(!pd2(x/i)) {
//				cout<<"i1:"<<x/i<<endl;
				return false;
			}
		}
	}
	return true;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	scanf("%d",&aaa[i]);
	for(int i=1; i<=n; i++) {
		if(aaa[i]<=10) {
			if(aaa[i]==7) cout<<-1<<endl;
			else if(aaa[i]+1!=7) cout<<aaa[i]+1<<endl;
			else if(aaa[i]+1==7) cout<<aaa[i]+2<<endl;
		} else {
			if(gys(aaa[i])) { //本身无问题
//				cout<<aaa[i]<<"NO"<<endl;
				v=0;
				int bbb=aaa[i];
				while(true){
					k=0;
					if(v==0) {
						bbb=bbb+1;
//						cout<<"+1"<<" "<<bbb<<endl;
					}
					else {
//						cout<<"k:"<<k<<endl;
						bbb=bbb+pow(10,k);
					}
//					cout<<"b:"<<bbb<<endl;
					if(gys(bbb)) break;
				}	
				cout<<bbb<<endl;
			} else cout<<-1<<endl;
		}
	}
	return 0;
}
