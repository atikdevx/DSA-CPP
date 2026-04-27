#include <iostream>
#include <climits>
using namespace std;

int dp[100][100];

int matrixChain(int p[], int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int q = matrixChain(p, i, k)
              + matrixChain(p, k + 1, j)
              + p[i - 1] * p[k] * p[j];

        ans = min(ans, q);
    }

    return dp[i][j] = ans;
}

int main()
{
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = 6;

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;

    cout << matrixChain(p, 1, n);

    return 0;
}