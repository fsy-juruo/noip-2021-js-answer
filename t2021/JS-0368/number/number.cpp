#include<iostream>
#include<cstring>
#include<string>

using namespace std;

bool a[11000009];



bool ck(int n){//check the num has 7,if it has 7 ,return false
	while(n>0){
		if(n%10==7)return false;
		n/=10;
	}
	return true;
}
void s(){
	int i=7;
	while(i<11000009){
		if(a[i]==false){
			if(ck(i)==true){
			}
			else{
				int n=11000009/i;	
				for(int j=1;j<n+1;j++){
					a[i*j]=true;
				}
			}
		}
		i++;
	}
}

int main(){
	s();
	//memset(a,0,sizeof(a));
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	cin>>t;
	int num;
	for(int i=0;i<t;i++){
		cin>>num;
	//	if(num==0){cout<<1<<"\n";continue;}
		//cout<<a[num]<<endl;
		if(a[num]==true){cout<<-1<<"\n";continue;}
		else {
			while(a[num+1]==true&&num+1<=11000009){
				num++;
			}
			cout<<num+1<<"\n";
		}
	}
	return 0;
}
