#include <bits/stdc++.h>
using namespace std;
int n;
int cor_n;
int cor_num = 0;

int p(int number){
	int lastnum = 0;
	while(number != 0){
		lastnum = number % 10;
		if(lastnum == 7){
			return 1;
		}
		else{
			number = (number - lastnum) / 10;
		}
	}
}

int p2(int number){
	int x = 7;
	while(x < cor_n){
		if(p(x)){
			if(cor_n % x == 0){
				return 1;
			}
		}
		x ++;
	}
	return 0;
}

int judge(int number){
	if(p(number)){
		return 0;
	}
	else{
		if(p2(number)){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	int num;
	for(int i = 1 ; i<= n ; i ++){
		cin >> num;
		cor_n = num;
		if(!judge(num)){
			cout << -1 << endl;
			continue;
		}
		for(int j = num + 1 ; ; j++){
			cor_n = j;
			if(judge(j)){
				cout << j << endl;
				break;
			}
		}
	}
	return 0;
}
