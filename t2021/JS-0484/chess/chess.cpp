#include <bits/stdc++.h>
using namespace std;
int rd() {
	char c = getchar();
	while(!isdigit(c) && c != '-') {
		c = getchar();
	}
	int f = 1;
	if(c == '-') {
		f = -1;
		c = getchar();
	}
	int val = 0;
	while(isdigit(c)) {
		val = val * 10 + (int)(c - '0');
		c = getchar();
	}
	return val * f;
}
void rs(char* s) {
	char c = getchar();
	while(!isdigit(c)) {
		c = getchar();
	}
	memset(s, 0, sizeof(s));
	int cnt = 0;
	while(isdigit(c)) {
		s[cnt++] = c;
		c = getchar();
	}
	s[cnt] = '\0';
}
int n, m, q;
char r[200005], c[200005];
char s[200005];
bool ok[5005], vis[5005];
int cl[5005], lv[5005];

void solve1() {//brute force
	while(q--) {
		memset(vis, 0, sizeof(vis));
		memset(ok, 0, sizeof(ok));
		int Col = rd(), Lev = rd(), x = rd(), y = rd();
		cl[(x - 1) * m + y] = Col, lv[(x - 1) * m + y] = Lev;
		++cl[(x - 1) * m + y];
		vis[(x - 1) * m + y] = true;
		if(x > 1) {//up
			if(c[(x - 2) * m + y] == '1') {
				if(cl[(x - 2) * m + y] == 0) {
					ok[(x - 2) * m + y] = true;
				} else if(cl[(x - 2) * m + y] != cl[(x - 1) * m + y] && lv[(x - 2) * m + y] <= lv[(x - 1) * m + y]) {
					ok[(x - 2) * m + y] = true;
				}
			} else if(c[(x - 2) * m + y] == '2') {
				int nx = x - 1;
				while(true) {
					if(cl[(nx - 1) * m + y] == 0) {
						ok[(nx - 1) * m + y] = true;
					} else if(cl[(nx - 1) * m + y] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + y] <= lv[(x - 1) * m + y]) {
						ok[(nx - 1) * m + y] = true;
						break;
					} else {
						break;
					}
					if(nx == 1) {
						break;
					}
					if(c[(nx - 2) * m + y] != '2') {
						break;
					}
					--nx;
				}
			} else if(c[(x - 2) * m + y] == '3') {
				queue<int> q;
				if(cl[(x - 2) * m + y] == 0) {
					ok[(x - 2) * m + y] = true;
					q.push(x - 1);
					q.push(y);
				} else if(cl[(x - 2) * m + y] != cl[(x - 1) * m + y] && lv[(x - 2) * m + y] <= lv[(x - 1) * m + y]) {
					ok[(x - 2) * m + y] = true;
				}
				while(!q.empty()) {
					int nx = q.front();
					q.pop();
					int ny = q.front();
					q.pop();
					ok[(nx - 1) * m + ny] = true;
					vis[(nx - 1) * m + ny] = true;
					if(!vis[(nx - 2) * m + ny] && nx > 1 && c[(nx - 2) * m + ny] == '3') {
						if(cl[(nx - 2) * m + ny] == 0) {
							q.push(nx - 1);
							q.push(ny);
						} else if(cl[(nx - 2) * m + ny] != cl[(x - 1) * m + y] && lv[(nx - 2) * m + ny] <= lv[(x - 1) * m + y]) {
							ok[(nx - 2) * m + y] = true;
						}
					}
					if(!vis[nx * m + ny] && nx < n && c[(nx - 1) * m + ny] == '3') {
						if(cl[nx * m + ny] == 0) {
							q.push(nx + 1);
							q.push(ny);
						} else if(cl[nx * m + ny] != cl[(x - 1) * m + y] && lv[nx * m + ny] <= lv[(x - 1) * m + y]) {
							ok[nx * m + ny] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny - 1] && ny > 1 && r[(nx - 1) * m + ny - 1] == '3') {
						if(cl[(nx - 1) * m + ny - 1] == 0) {
							q.push(nx);
							q.push(ny - 1);
						} else if(cl[(nx - 1) * m + ny - 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny - 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny - 1] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny + 1] && ny < m && r[(nx - 1) * m + ny] == '3') {
						if(cl[(nx - 1) * m + ny + 1] == 0) {
							q.push(nx);
							q.push(ny + 1);
						} else if(cl[(nx - 1) * m + ny + 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny + 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny + 1] = true;
						}
					}
				}
			}
		}
		if(x < n) {//down
			if(c[(x - 1) * m + y] == '1') {
				if(cl[x * m + y] == 0) {
					ok[x * m + y] = true;
				} else if(cl[x * m + y] != cl[(x - 1) * m + y] && lv[x * m + y] <= lv[(x - 1) * m + y]) {
					ok[x * m + y] = true;
				}
			} else if(c[(x - 1) * m + y] == '2') {
				int nx = x + 1;
				while(true) {
					if(cl[(nx - 1) * m + y] == 0) {
						ok[(nx - 1) * m + y] = true;
					} else if(cl[(nx - 1) * m + y] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + y] <= lv[(x - 1) * m + y]) {
						ok[(nx - 1) * m + y] = true;
						break;
					} else {
						break;
					}
					if(nx == n) {
						break;
					}
					if(c[(nx - 1) * m + y] != '2') {
						break;
					}
					++nx;
				}
			} else if(c[(x - 1) * m + y] == '3') {
				queue<int> q;
				if(!vis[x * m + y]) {
					if(!cl[x * m + y]) {
						q.push(x + 1);
						q.push(y);
					} else if(cl[x * m + y] != cl[(x - 1) * m + y] && lv[x * m + y] <= lv[(x - 1) * m + y]) {
						ok[x * m + y] = true;
					}
				}
				while(!q.empty()) {
					int nx = q.front();
					q.pop();
					int ny = q.front();
					q.pop();
					ok[(nx - 1) * m + ny] = true;
					vis[(nx - 1) * m + ny] = true;
					if(!vis[(nx - 2) * m + ny] && nx > 1 && c[(nx - 2) * m + ny] == '3') {
						if(cl[(nx - 2) * m + ny] == 0) {
							q.push(nx - 1);
							q.push(ny);
						} else if(cl[(nx - 2) * m + ny] != cl[(x - 1) * m + y] && lv[(nx - 2) * m + ny] <= lv[(x - 1) * m + y]) {
							ok[(nx - 2) * m + y] = true;
						}
					}
					if(!vis[nx * m + ny] && nx < n && c[(nx - 1) * m + ny] == '3') {
						if(cl[nx * m + ny] == 0) {
							q.push(nx + 1);
							q.push(ny);
						} else if(cl[nx * m + ny] != cl[(x - 1) * m + y] && lv[nx * m + ny] <= lv[(x - 1) * m + y]) {
							ok[nx * m + ny] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny - 1] && ny > 1 && r[(nx - 1) * m + ny - 1] == '3') {
						if(cl[(nx - 1) * m + ny - 1] == 0) {
							q.push(nx);
							q.push(ny - 1);
						} else if(cl[(nx - 1) * m + ny - 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny - 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny - 1] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny + 1] && ny < m && r[(nx - 1) * m + ny] == '3') {
						if(cl[(nx - 1) * m + ny + 1] == 0) {
							q.push(nx);
							q.push(ny + 1);
						} else if(cl[(nx - 1) * m + ny + 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny + 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny + 1] = true;
						}
					}
				}
			}
		}
		if(y > 1) {//left
			if(r[(x - 1) * m + y - 1] == '1') {
				if(cl[(x - 1) * m + y - 1] == 0) {
					ok[(x - 1) * m + y - 1] = true;
				} else if(cl[(x - 1) * m + y - 1] != cl[(x - 1) * m + y] && lv[(x - 1) * m + y - 1] <= lv[(x - 1) * m + y]) {
					ok[(x - 1) * m + y - 1] = true;
				}
			} else if(r[(x - 1) * m + y - 1] == '2') {
				int ny = y - 1;
				while(true) {
					if(cl[(x - 1) * m + ny] == 0) {
						ok[(x - 1) * m + ny] = true;
					} else if(cl[(x - 1) * m + ny] != cl[(x - 1) * m + y] && lv[(x - 1) * m + ny] <= lv[(x - 1) * m + y]) {
						ok[(x - 1) * m + ny] = true;
						break;
					} else {
						break;
					}
					if(ny == 1) {
						break;
					}
					if(r[(x - 1) * m + ny - 1] != '2') {
						break;
					}
					--ny;
				}
			} else if(r[(x - 1) * m + y - 1] == '3') {
				queue<int> q;
				if(!vis[(x - 1) * m + y - 1]) {
					if(!cl[(x - 1) * m + y - 1]) {
						q.push(x);
						q.push(y - 1);
					} else if(cl[(x - 1) * m + y - 1] != cl[(x - 1) * m + y] && lv[(x - 1) * m + y - 1] != lv[(x - 1) * m + y]) {
						ok[(x - 1) * m + y - 1] = true;
					}
				}
				while(!q.empty()) {
					int nx = q.front();
					q.pop();
					int ny = q.front();
					q.pop();
					ok[(nx - 1) * m + ny] = true;
					vis[(nx - 1) * m + ny] = true;
					if(!vis[(nx - 2) * m + ny] && nx > 1 && c[(nx - 2) * m + ny] == '3') {
						if(cl[(nx - 2) * m + ny] == 0) {
							q.push(nx - 1);
							q.push(ny);
						} else if(cl[(nx - 2) * m + ny] != cl[(x - 1) * m + y] && lv[(nx - 2) * m + ny] <= lv[(x - 1) * m + y]) {
							ok[(nx - 2) * m + y] = true;
						}
					}
					if(!vis[nx * m + ny] && nx < n && c[(nx - 1) * m + ny] == '3') {
						if(cl[nx * m + ny] == 0) {
							q.push(nx + 1);
							q.push(ny);
						} else if(cl[nx * m + ny] != cl[(x - 1) * m + y] && lv[nx * m + ny] <= lv[(x - 1) * m + y]) {
							ok[nx * m + ny] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny - 1] && ny > 1 && r[(nx - 1) * m + ny - 1] == '3') {
						if(cl[(nx - 1) * m + ny - 1] == 0) {
							q.push(nx);
							q.push(ny - 1);
						} else if(cl[(nx - 1) * m + ny - 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny - 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny - 1] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny + 1] && ny < m && r[(nx - 1) * m + ny] == '3') {
						if(cl[(nx - 1) * m + ny + 1] == 0) {
							q.push(nx);
							q.push(ny + 1);
						} else if(cl[(nx - 1) * m + ny + 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny + 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny + 1] = true;
						}
					}
				}
			}
		}
		if(y < m) {//right
			if(r[(x - 1) * m + y] == '1') {
				if(cl[(x - 1) * m + y + 1] == 0) {
					ok[(x - 1) * m + y + 1] = true;
				} else if(cl[(x - 1) * m + y + 1] != cl[(x - 1) * m + y] && lv[(x - 1) * m + y + 1] <= lv[(x - 1) * m + y]) {
					ok[(x - 1) * m + y + 1] = true;
				}
			} else if(r[(x - 1) * m + y] == '2') {
				int ny = y + 1;
				while(true) {
					if(cl[(x - 1) * m + ny] == 0) {
						ok[(x - 1) * m + ny] = true;
					} else if(cl[(x - 1) * m + ny] != cl[(x - 1) * m + y] && lv[(x - 1) * m + ny] <= lv[(x - 1) * m + y]) {
						ok[(x - 1) * m + ny] = true;
						break;
					} else {
						break;
					}
					if(ny == m) {
						break;
					}
					if(r[(x - 1) * m + ny] != '2') {
						break;
					}
					++ny;
				}
			} else if(r[(x - 1) * m + y] == '3') {
				queue<int> q;
				if(!vis[(x - 1) * m + y + 1]) {
					if(!cl[(x - 1) * m + y + 1]) {
						q.push(x);
						q.push(y + 1);
					} else if(cl[(x - 1) * m + y + 1] != cl[(x - 1) * m + y] && lv[(x - 1) * m + y + 1] != lv[(x - 1) * m + y]) {
						ok[(x - 1) * m + y + 1] = true;
					}
				}
				while(!q.empty()) {
					int nx = q.front();
					q.pop();
					int ny = q.front();
					q.pop();
					ok[(nx - 1) * m + ny] = true;
					vis[(nx - 1) * m + ny] = true;
					if(!vis[(nx - 2) * m + ny] && nx > 1 && c[(nx - 2) * m + ny] == '3') {
						if(cl[(nx - 2) * m + ny] == 0) {
							q.push(nx - 1);
							q.push(ny);
						} else if(cl[(nx - 2) * m + ny] != cl[(x - 1) * m + y] && lv[(nx - 2) * m + ny] <= lv[(x - 1) * m + y]) {
							ok[(nx - 2) * m + y] = true;
						}
					}
					if(!vis[nx * m + ny] && nx < n && c[(nx - 1) * m + ny] == '3') {
						if(cl[nx * m + ny] == 0) {
							q.push(nx + 1);
							q.push(ny);
						} else if(cl[nx * m + ny] != cl[(x - 1) * m + y] && lv[nx * m + ny] <= lv[(x - 1) * m + y]) {
							ok[nx * m + ny] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny - 1] && ny > 1 && r[(nx - 1) * m + ny - 1] == '3') {
						if(cl[(nx - 1) * m + ny - 1] == 0) {
							q.push(nx);
							q.push(ny - 1);
						} else if(cl[(nx - 1) * m + ny - 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny - 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny - 1] = true;
						}
					}
					if(!vis[(nx - 1) * m + ny + 1] && ny < m && r[(nx - 1) * m + ny] == '3') {
						if(cl[(nx - 1) * m + ny + 1] == 0) {
							q.push(nx);
							q.push(ny + 1);
						} else if(cl[(nx - 1) * m + ny + 1] != cl[(x - 1) * m + y] && lv[(nx - 1) * m + ny + 1] <= lv[(x - 1) * m + y]) {
							ok[(nx - 1) * m + ny + 1] = true;
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(ok[(i - 1) * m + j]) {
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
}

void solve2() {//normal only
	while(q--) {
		int Col = rd(), Lev = rd(), x = rd(), y = rd();
		cl[(x - 1) * m + y] = Col, lv[(x - 1) * m + y] = Lev;
		int ans = 0;
		if(x > 1 && c[(x - 2) * m + y] == '1') {
			if(cl[(x - 2) * m + y] == 0) {
				++ans;
			} else if(cl[(x - 2) * m + y] != cl[(x - 1) * m + y] && lv[(x - 2) * m + y] <= lv[(x - 1) * m + y]) {
				++ans;
			}
		}
		if(x < n && c[(x - 1) * m + y] == '1') {
			if(cl[x * m + y] == 0) {
				++ans;
			} else if(cl[x * m + y] != cl[(x - 1) * m + y] && lv[x * m + y] <= lv[(x - 1) * m + y]) {
				++ans;
			}
		}
		if(y > 1 && r[(x - 1) * m + y - 1] == '1') {
			if(cl[(x - 1) * m + y - 1] == 0) {
				++ans;
			} else if(cl[(x - 1) * m + y - 1] != cl[(x - 1) * m + y] && lv[(x - 1) * m + y - 1] <= lv[(x - 1) * m + y]) {
				++ans;
			}
		}
		if(y < m && r[(x - 1) * m + y] == '1') {
			if(cl[(x - 1) * m + y + 1] == 0) {
				++ans;
			} else if(cl[(x - 1) * m + y + 1] != cl[(x - 1) * m + y] && lv[(x - 1) * m + y + 1] <= lv[(x - 1) * m + y]) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}
}

void submain() {
	n = rd(), m = rd(), q = rd();
	bool noc = true, nod = true;
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	memset(cl, 0, sizeof(cl));
	memset(lv, 0, sizeof(lv));
	for(int i = 1; i <= n; ++i) {
		rs(s);
		for(int j = 0; j < m - 1; ++j) {
			r[(i - 1) * m + j + 1] = s[j];
			if(s[j] == '2') {
				nod = false;
			} else if(s[j] == '3') {
				noc = false;
			}
		}
	}
	for(int i = 1; i < n; ++i) {
		rs(s);
		for(int j = 0; j < m; ++j) {
			c[(i - 1) * m + j + 1] = s[j];
			if(s[j] == '2') {
				nod = false;
			} else if(s[j] == '3') {
				noc = false;
			}
		}
	}
	if(n * m <= 5000) {
		solve1();
		return ;
	} else if(nod && noc) {
		solve2();
	}
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int t = rd();
	while(t--) {
		submain();
	}
	return 0;
}
