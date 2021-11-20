#include <bits/stdc++.h>
#define vite vector<int>::iterator

using namespace std;

map<vector<int> ,bool> m;
double minfc = 2147483647;

double check(vector<int> v){
	long long total = 0;
	for(vite ite = v.begin();ite != v.end();ite++){
		total += *ite;
	}
	double avr = total * 1.0 / v.size();
	double fc = 0;
	for(vite ite = v.begin();ite != v.end();ite++){
		fc += (*ite - avr) * (*ite - avr);
	}
	return fc;
}

void fuckccf(vector<int> v){
	queue<vector<int> > q;
	q.push(v);
	vector<int> tempv;
	while(q.size() != 0){
		vector<int> nowv = q.front();
		q.pop();
		if(m[nowv] == true) continue;
		double nowfc = check(nowv);
		m[nowv] = true;
		if(nowfc < minfc) minfc = nowfc;
		tempv.clear();
		tempv.insert(tempv.begin(),nowv.begin(),nowv.end());
		for(int i = 1;i < int(nowv.size()) - 1;i++){
			tempv[i] = tempv[i - 1] + tempv[i + 1] - tempv[i];
			q.push(tempv);
			tempv[i] = nowv[i];
		}
		
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	scanf("%d",&n);
	int t;
	vector<int> v;
	for(int i = 0;i < n;i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	minfc = check(v);
	fuckccf(v);
	cout << minfc * n << endl;
	return 0;
}
