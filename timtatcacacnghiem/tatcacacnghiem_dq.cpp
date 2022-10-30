#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print(vector<int> a)
{
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
void Backtracking(vector<int> a, int n, int k)
{
    if (k == 0)
    {
        print(a);
        return;
    }
    if (n <= 0)
        return;
    for (int i = k; i >= 0; i--)
    {



       vector<int> a2;
        if (a.size() == 0)
        {
            a2.push_back(i);
        }
        else
        {
            int size = a.size();
            for (int i = 0; i < size; i++)
            {
                int a3 = a[i];
                a2.push_back(a3);
            }
            a2.push_back(i);
        }
        if (k - i == 0)
        {
            for (int i = 0; i < n - 1; i++)
            {
                a2.push_back(0);
            }
        }
        Backtracking(a2, n - 1, k - i);
    }
}
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a;
    if (N > 0 && K == 0)
    {
        vector<int> a2;
        for (int i = 0; i < N; i++)
        {
            a2.push_back(0);
        }
        print(a2);
    }
    else
    {
        Backtracking(a, N, K);
    }
}