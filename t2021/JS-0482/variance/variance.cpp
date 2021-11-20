#include <bits/stdc++.h>
using namespace std;

const int N= 15;

int a[N], M1[N][N];

struct P15
{
    int change()
	{
		if(a[2]* 2!= a[1]+ a[3]&& ! M1[a[1]+ a[3]- a[2]][a[3]]) {a[2]= a[1]+ a[3]- a[2], M1[a[2]][a[3]]= 1; return 1;}
		else if(a[3]* 2!= a[2]+ a[4]&& ! M1[a[2]][a[2]+ a[4]- a[3]]) {a[3]= a[2]+ a[4]- a[3], M1[a[2]][a[3]]= 1; return 1;}
		return 0;
	}
	
	int got()
	{
		int x= a[1]+ a[2]+ a[3]+ a[4];
		return ((a[1]* 4- x)* (a[1]* 4- x)+ (a[2]* 4- x)* (a[2]* 4- x)+ (a[3]* 4- x)* (a[3]* 4- x)+ (a[4]* 4- x)* (a[4]* 4- x))/ 4;
    }  
	
	void solve()
	{
		int minn= (int)1e9;
		while(change()) minn= min(minn, got());
		cout<< minn<< endl;
		
		return ;
	}
}P15;

int M[55][305]; 
int n;

struct P40
{
	int change()
	{
		for(int i= 2; i<= n- 1; i++ )
			if(a[i]* 2!= a[i- 1]+ a[i+ 1]&& ! M[i][a[i- 1]+ a[i+ 1]- a[i]]) {a[i]= a[i- 1]+ a[i+ 1]- a[i], M[i][a[i]]= 1; return 1; }
		return 0;
	}
	
	int got()
	{
		int x= 0;
		for(int i= 1; i<= n; i++ ) x+= a[i]; 
		int sum= 0;
		for(int i= 1; i<= n; i++ ) sum+= (n* a[i]- x)* (n* a[i]- x);
		return sum/ n;
	} 
	
	void solve()
	{
		int minn= (int)1e9;
		while(change()) minn= min(minn, got());
		cout<< minn<< endl;
		
		return ;
	}
}P40;

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	cin>> n;
	for(int i= 1; i<= n; i++ ) scanf("%d", &a[i]);
	if(n== 4) P15.solve();
	else P40.solve();
	
	
	return 0;
}


/*
4
1 2 4 6


10
6 19 34 35 56 63 82 82 83 99

50
1 6 25 27 27 28 29 30 32 32 32 32 32 32 32 32 32 32 32 34 36 38 39 40 40 42 45 49 50 51 52 53 53 54 54 54 56 57 57 57 59 59 59 59 61 63 63 63 64 66



*/
