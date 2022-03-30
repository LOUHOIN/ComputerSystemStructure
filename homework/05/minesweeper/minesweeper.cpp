#include<iostream>
#include<string.h>
using namespace std;
int main() {
    static int map[1000][1000];
	int n, m, i, j, k, t = 0;
	char z;
	int df[8][2] = { {1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,1},{-1,-1},{-1,0} }; 
	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0)break;
		if (t)cout << endl; t++;
		memset(map, 0, sizeof(map));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				cin >> z;
				if (z == '*') {
					map[i][j] = 10;
					for (k = 0; k < 8; k++)map[i + df[k][0]][j + df[k][1]]++;
				}
			}
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++)
				if (map[i][j] >= 10)cout << "F";
				else if (map[i][j] == 0)cout << "-";
				else cout << map[i][j];
			cout << endl;
		}
	}
	return 0;
}