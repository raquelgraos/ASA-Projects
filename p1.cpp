/* Projeto 1 de ASA
    Raquel Rodrigues - 106987
    Guilherme Pereira - 107057
*/

#include <iostream>
#include <vector>
using namespace std;

int maxPrice(int X, int Y, int n, vector<vector<int>>& marble) {
    for (int i = 1; i <= X; ++i) {
        for (int j = 1; j <= Y; ++j) {
            for (int k = 1; k <= (i/2) ; ++k) {
                marble[i][j] = max(marble[i][j], marble[k][j] + marble[i-k][j]);
            }
            for (int k = 1; k <= (j/2); ++k) {
                marble[i][j] = max(marble[i][j], marble[i][k] + marble[i][j-k]);
            }
        }
    }
    return marble[X][Y];
}

int main() {
    int X, Y;
    if (scanf("%d %d", &X, &Y) != 2)
        return 0;

    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    vector<vector<int>> marble(X + 1, vector<int>(Y + 1, 0));
    for (int i = 0; i < n; ++i) {
        int a, b, p;
        if (scanf("%d %d %d", &a, &b, &p) != 3)
            return 0;
        if (a <= X && b <= Y) {
            marble[a][b] = max(marble[a][b], p);
        }
        if (b <= X && a <= Y) {
            marble[b][a] = max(marble[b][a], p);
        }
    }
    int result = maxPrice(X, Y, n, marble);
    printf("%d\n", result);
    return 0;
}
