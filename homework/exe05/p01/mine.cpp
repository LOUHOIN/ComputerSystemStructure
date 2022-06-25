#include<stdio.h>
#include<cstring>
using namespace std;
const long maxn =20000;
int m, n;
bool test(int x, int y){
	if(x >= m || x < 0 || y >=n || y < 0){
		return false;
	}
	return true;
}
char mapi[maxn][maxn], mapo[maxn][maxn];
int main() {
	//int X[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	//int Y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	memset(mapi, 0, sizeof mapi);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++) {
		getchar();
		for(int j = 0; j < n; j++) {
			mapi[i][j] = getchar();
		}
		mapi[i][n+1] = '\0';
	}
	/*for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(mapi[i][j] == '*') {
				mapo[i][j] = 'F';
			} else if(mapi[i][j] == '.') {
				int bomb = 0;
				for(int k = 0; k < 8; k++) {
					int x = i + X[k];
					int y = j + Y[k];
					if(test(x, y) && mapi[x][y] == '*') {
						bomb++;
					}
				}
				if(bomb == 0) {
					mapo[i][j] = '-';
				} else {
					mapo[i][j] = bomb + '0';
				}
			}
		}
	}*/
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			putchar(mapi[i][j]);
		}
		putchar('\n');
	}
	return 0;
}