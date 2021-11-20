#include<bits/stdc++.h>
using namespace std;
int a[1000+10];
void pan(int q){
	int y = (q/10)+1;
	int chu = 7;
	for(int i = 1; i <= y; i++){
		if( q % chu == 0){
			a[q] = -1;
			break;
		}
		else chu += 10;
	}
	y = (q/100) +1;
	chu = 70;
	int ji = 0;  
	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= 10; j++){
			if( q % chu == 0){
				a[q] = -1;
				ji = 1;
				break;
			}
			else chu++;
		}
		if (ji ==1) break;
		else chu += 90;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i = 1; i <= 1002; i++)
	{
		a[i]=i;
		if(i % 10 ==7 || (i%100)/10 == 7 || i/100 ==7) a[i] = -1;
		else pan(a[i]);
	} 
/*	for(int i = 1; i <= 3; i++)
	{
		int w;
		cin>>w;
		cout<<a[w]<<endl;
	}*/
	for(int i = 1; i <= n; i++){
		cin>>x;
		if(a[x] == -1) cout<<-1<<endl;
		else{
			while(1){
				x++;
				if(a[x] != -1) {
					cout<<x<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

