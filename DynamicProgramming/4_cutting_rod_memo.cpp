#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// The auxiliary recursive function that does the actual work
int memoizedCutRodAux(int price[], int n, vector<int>& r)
{
    // If we have already calculated the max revenue for length n, return it immediately!
    if (r[n] >= 0)
    {
        return r[n];
    }

    int q;
    if (n == 0)
    {
        q = 0; // Base case: a rod of length 0 yields 0 revenue
    }
    else
    {
        q = INT_MIN;
        // Recursively find the max revenue for the current length
        for (int i = 1; i <= n; i++)
        {
            q = max(q, price[i] + memoizedCutRodAux(price, n - i, r));
        }
    }
    
    // SAVE the calculated result in our memory array before returning
    r[n] = q;
    return q;
}

// The main wrapper function that initializes the memory array
int memoizedCutRod(int price[], int n)
{
    // Create an array `r` of size n+1 to store the maximum revenue for each length
    // We initialize it with INT_MIN (representing negative infinity) 
    vector<int> r(n + 1, INT_MIN);

    return memoizedCutRodAux(price, n, r);
}

int main()
{
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;
    
    cout << "Maximum Revenue (Memoized) = " << memoizedCutRod(price, n) << endl;
    
    return 0;
}