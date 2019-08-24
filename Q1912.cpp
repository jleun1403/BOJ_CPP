#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> D(n+1, vector<int> (2));
    vector<int> A(n+1);

    for (int i = 1 ; i <= n ; i++)
    {
        int k;
        cin >> k;
        A[i] = k;
    }
    A[0] = 0;
    D[1][0] = 0;
    D[1][1] = A[1];
    if (n >= 2)
    {
        D[2][0] = A[1];
        D[2][1] = max(A[1] + A[2], A[2]);
        for (int i = 3 ; i <= n ; i++)
        {
            D[i][0] = max(D[i-1][0], D[i-1][1]);
            D[i][1] = max(A[i], D[i-1][1] + A[i]);
        }
    cout << max(D[n][0], D[n][1]); }
    else {
        cout << A[1];
    }

}
