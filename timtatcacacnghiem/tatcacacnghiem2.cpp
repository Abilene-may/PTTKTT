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
int d = 0;
void Backtracking(vector<int> a, int n, int k, int a4[])
{
    if (k == 0)
    {
        print(a);
        d++;
        return;
    }
    if (n <= 0)
        return;
    for (int i = k; i >= 0; i--)
    {
        vector<int> a2;
        int a31 = a4[n - 1] * i;
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
        if (k - a31 == 0)
        {
            for (int i = 0; i < n - 1; i++)
            {
                a2.push_back(0);
            }
        }
        Backtracking(a2, n - 1, k - a31, a4);
    }
}
int main()
{
    int N, K;
    cin >> N >> K;
    int a1[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a1[N - i - 1];
    }
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
        vector<int> a;
        Backtracking(a, N, K, a1);
        if (d == 0)
        {
            cout << "Vo nghiem!" << endl;
        }
    }
}