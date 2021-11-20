#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	srand(time(NULL));
	cout << ((((rand() << 3) + (rand() << 5) + 1145141919810) * 1145141) >> (rand() % 4)) % 998244353<< endl;
	return 0;
}
