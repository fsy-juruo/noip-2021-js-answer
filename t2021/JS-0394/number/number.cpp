#include <iostream>
#include <cstdio>
//#include <vector>
using namespace std;
int a[10000003],T,x,f/*,flag*/;
//vector<int> wro;
int read(){
	char c=' ';
	int num=0;
	c=getchar();
	while (c!='\n'){
		//if (c=='7'){
			//flag=1;
		//}
		num=num*10+c-'0';
		c=getchar();
	}
	return num;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=7;i<=10000;++i){
		int tmp=i;
		if (a[i]==1){
			for (int j=1;j*i<=10000000;++j){
				a[i*j]=1;
			}
			continue;
		}
		while(tmp!=0){
			int c=tmp%10;
			if (c==7){
				a[i]=1;
				break;
			}
			tmp/=10;
		}
		if (a[i]==1){
			for (int j=1;j*i<=10000000;++j){
				a[i*j]=1;
			}
		}
	}
	T=read();
	while (T--){
		//flag=0;
		x=read();
		/*if (flag){
			printf("-1\n");
			a[x]=1;
			wro.push_back(a[x]);
			continue;
		}else{
			for (int i=0;i<wro.size();++i){
				
			}
		}*/
		if (a[x]==1){
			printf("-1\n");
		}else{
			x++;
			while (a[x]==1) x++;
			printf("%d\n",x);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
