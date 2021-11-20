#include<iostream>
using namespace std;
int unable[200005];
int T;
int x[200005];
void make(int x){
	for(int i=x;i<=2e5;i+=x){
		unable[i]=1;
	}
	return ;
}
void createunable(){
	for(int i=1;i<=2e5;i++){
		if(unable[i]) continue;
		if(i%7==0){
			make(i);
			continue;
		}
		int t=i;
		while(t){
			int p=t%10;
			if(p==7){
				make(i);
				break;
			}
			t/=10;
		}
	}
	return ;
}
int answer(int x){
	for(int i=x+1;i<=2e5;i++){
		if(!unable[i]) return i;
	}
	return -1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>x[i];
	}
	createunable();
	for(int i=0;i<T;i++){
		if(unable[x[i]]){
			cout<<-1;
			cout<<endl;
			continue;
		}
		else{
			cout<<answer(x[i]);
			cout<<endl;
		}
	}
	return 0;
}








