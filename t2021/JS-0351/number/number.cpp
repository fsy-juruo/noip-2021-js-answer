#include <bits/stdc++.h>

using namespace std;
int num1[100000],num2[100000];
int t,x,tmp[100000];
int c=1,cc=1,ccc=1;//c��ʱ���������cc��num1��������ccc:num2������ 
bool judge(int n){//�ж� 
	if(n%7==0) return 0;
	if(n%10==7||n/10==7||n/10%10==7||n%100==7||n/100%10==7||n/1000==7||n/1000%10==7||n/10000==7){
		tmp[c]=n;
		c++;
		return 0;
	}
	for(int i=1;i<c;i++){
		if(n%tmp[i]==0){
			return 0;
		}
	}
	return 1;
}

void excel(){//10000���ڴ�� 
	for(int i=1;i<=100000;i++){
		if(judge(i)){
			num1[cc]=i;//���� 
			cc++;
		}
		else{
			num2[ccc]=i;//������� 
			ccc++;
		}
	}
}
bool search_num2(int n){
	for(int i=1;i<ccc;i++){
		if(num2[i]==n){
			return 0;
		}
	}
	return 1;
}
int search_num1(int n){
	for(int i=1;i<cc;i++){
		if(num1[i]>n){
			return num1[i];
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	excel();
	cin>>t;
	for(int k=1;k<=t;k++){//ѯ�ʴ��� 
		cin>>x;//Сr������ 
		if(search_num2(x)){
			cout<<search_num1(x);
		}
		else cout<<"-1";
		cout<<endl;
	}
	return 0;
} 
