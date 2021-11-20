#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	long long ff=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')ff=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=ff;
}
template<typename T>inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);putchar('\n');
}
const long long INF=0x3f3f3f3f3f3f3f3f;
const long long N=1e4;
long long n,a[N+10],b[N+10],ans=INF;
long long get(){
	long long S1=0,S2=0;
	for(long long i=1;i<=n;i++){
		S1+=b[i];S2+=b[i]*b[i];
	}
	return n*S2-S1*S1;
}
void pr(){
	for(long long i=1;i<=n;i++)cout<<setw(4)<<b[i];
	cout<<endl;
	writeln(get());
}
long long pianfen1(){
	long long res=INF;
	for(long long pos=2;pos<n;pos++){
		for(long long i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(long long k=1;k<=n;k++){
			for(long long i=2;i<=pos-1;i++){
				b[i]=max(b[i],b[i-1]+b[i+1]-b[i]);
			}
			for(long long i=n-1;i>=pos;i--){
				b[i]=min(b[i],b[i-1]+b[i+1]-b[i]);
			}
		}
		
//		pr();
		
		res=min(res,get());
	}
	return res;
}
long long pianfen2(){
	long long res=INF;
	for(long long i=1;i<=n;i++)b[i]=a[i];
	for(long long i=2;i<n;i++){
		b[i]=max(b[i],b[i-1]+b[i+1]-b[i]);
	}
	res=min(res,get());
	for(long long i=n-1;i>=2;i--){
		b[i]=min(b[i],b[i-1]+b[i+1]-b[i]);
		
//		pr();
		res=min(res,get());
	}
	return res;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	read(n);
	for(long long i=1;i<=n;i++){
		read(a[i]);
	}
	
	long long tmp=pianfen1();
	ans=min(ans,tmp);
	tmp=pianfen2();
	ans=min(ans,tmp);
	writeln(ans);
	return 0;
}
/*
4
1 2 4 6

10
6 19 34 35 56 63 82 82 83 99

*/
