#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
class Improvement1_weighting
{
private:
    int *id;
    int *sz;
    int soluong;

public:
    Improvement1_weighting(int n)
    {
        soluong =n;
        id = new int[2*n];
        sz = new int[2*n];
        for (int i = 0; i < 2*n; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
    int root(int i)
    {
        while (i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    void Union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if (i == j)
        {
            return;
        }
        else
        {
            if (sz[i] < sz[j])
            {
                id[i] = j;
                sz[j] += sz[i];
            }
            else
            {
                id[j] = i;
                sz[i] += sz[j];
            }
        }
    }
    void print(int x)
    {
        cout << sz[root(x)];
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;       
    map<string,int>m;
    Improvement1_weighting a(n);
    int count =1;
    string str1, str2;
    for(int i=0; i<n;i++)
    {
        cin>>str1>>str2;
        if(m[str1]==0){
            m[str1]=count;
            count++;
        }
        if(m[str2]==0)
        {
            m[str2]=count;
            count++;
        }
        a.Union(m[str1],m[str2]);
        a.print(m[str1]);
    }
    
    
    

    return 0;
}
