#include<bits/stdc++.h>
using namespace std;
int read(){	
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
int p[8000001];
int prime[89]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457};
bool sc(int x){
	int f=x;
	while(f>0){
		if(f%10==7){
			return 1;
		}
		f=f/10;
	}
	return 0;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   int t=read();
   for(int i=1;i<=200000;++i){
   	    int f=i,cnt=0;
   	
   	    while(f>1){
   	        if(p[f]||sc(f)){
   	        	p[i]=1;
   	        	break;
			   }
			while(f%prime[cnt]!=0&&cnt<87)cnt++;
			if(prime[cnt]>=f)break;
			if(p[prime[cnt]]){
				p[i]=1;
				break;
			}
			f=f/prime[cnt];
		}
   }
   for(int i=1;i<=t;++i){
   	  int x=read();
   	  if(p[x])printf("-1\n");
   	  else {
   	  	 int j;
   	  	 for(j=x+1;p[j]!=0;++j);
   	  	 printf("%d\n",j);
		 }
   }
   return 0;
}

