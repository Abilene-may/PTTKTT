#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
Nhập N và K
Tìm tất cả các nghiệm không âm của phương trình: 
X1 + X2 + .... + XN= K

SOLUTION

solve(n, k): Tất cả các nghiệm không âm của phương trình: X1 + X2 + .... + Xn= k
return: vector (m * n): 
 - m: so luong nghiem
 - n: so bien 
vector a,b,c; b= [3,4], c= [1,0]
a= b+c => a chua tat ca các phân tu có trong vector b và c 
a= [3,4,1,0]

solve(n, k)= sum{i:0..k}(solve(n-1, k-i))
Duyet tat ca các trương hợp của Xn(i:0..k) 
------------------------------------------------
n= 3, k= 4
[x, a, b]
i= 0: x= 0 [0, a, b] ==> [a, b]= 4
i= 1: x= 1 [1, a, b] ==> [a, b]= 3
....
i   : x= i [i, a, b] ==> [a, b]= k-i 

[a,b]= 3
i= 0: a= 0 [0, b]= 3 ==> [b] = 3 ==> b= 3
i= 1: a= 1 [1, b]= 3 ==> [b] = 2 ==> b= 2
...
i   : a= i [i, b]= 3 ==> [b] = 3-i ==> b= 3-i




[a] = k ==> a= k ===> [k]


[a,b,c]= 0 ==> [0, 0, 0]
*/

vector < vector < int > > solve(int n, int k){
    // Dieu kien dung
    if (n == 1) return vector < vector < int > >(1, vector < int >(1, k)); // [[k]] (1*1)
    if (k == 0) return vector < vector < int > >(1, vector < int >(n, 0)); // [[0,0,0,0, ..]] (1*n)

    // Cong thuc de quy
    vector < vector < int > > r;
    for (int i= k; i>=0 ; i--){
        vector < vector < int > > t= solve(n-1, k-i); //(m, n-1)
        //vector: a+b
        for (int j= 0;j < t.size(); j++){
            t[j].push_back(i); // n bien 
            r.push_back(t[j]);
        }
    }
    return r;
}

int main(){
    int N, K;
    cin>>N>>K;
    vector < vector < int > > ans= solve(N,K);
    for(int i=0 ;i< ans.size(); i++){
        for (int j= N-1; j>= 0; j--)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    //cout<<"Size: "<<ans.size()<<endl;
    return 0;

}
