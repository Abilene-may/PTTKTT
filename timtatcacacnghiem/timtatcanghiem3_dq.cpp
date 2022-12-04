/*
a1x1 + a2x2 + ... aNxN= K

#Y TUONG
xet aixi: 1<= i <= n
(i, k) // i ~ N, k ~ K 
0 <= v[i] <= k, v[i]%a[i]==0

xet (1, K) ~ a1x1= v1=> x1:= v1/a1 // v%a1==0
             => a2x2 + a2x3 + ... anxn = k - a1x1 
             => k:= k-a1x1
xet (2, K- a1x1) ~ a2x2= v2 => x2:= v2/a2 
             => a2x3 + ... anxn  = k - a2x2
             => => k:= k-a2x2
-------
-------
xet (n-1, K- a1x1 - a2x2 - ... a(n-2)x(n-2)) ~  
    a(n-1)x(n-1)= v(n-1) => x(n-1)= ?
                         => anxn = k- ... a(n-1)x(n-1)
                         => => k= k-a(n-1)x(n-1)
xet anxn= vn => xn = ?

i = n + 1

Dieu kien dung:
if i == N:
    => x[n] = k / a[i]
    if k%a[n] != 0: nghiem ko thoa man 
    else : x[n] nghiem thoa man ==> x[n]
    break vong lap
else: // i <= n
    if k == 0:  ==> nghiem can tim x(i..n) = 0

# CACH CODE
solve(i, k): tra ve ket qua (tap nghiem thoa man) cua phuong trinh: 
        aixi + a[i+1]x[i+1] + ... + a[N]x[N] = k

solve(1, K) ==> de bai 
solve(2, K- a1x1) ==> 
solve(3, K- a1x1 - a2x2) ==> 
......
solve(i, 0) ==> tap nghiem toan 0
......
solve(N, k= K - a1x1 - ... aN-1xN-1)

# CODE
*/
#include <iostream>
#include <vector>
using namespace std;
int N, K; 
int a[11];

vector < vector < int > > solve(int i, int k){
    if (i == N){
        if (k % a[i] != 0) 
            return vector < vector < int > > ();
        else 
            return vector < vector < int > > (1, vector < int > (1, k / a[i])); //[[v]]
            //vector < int >  v(so_luong_pt, gia_tri);
            //vector < int >  v(3, 4); ==> v= [4, 4, 4]
    }
    if (k == 0) // i<N, N= 4, i= 3 ==> i=3, i=4
        return vector < vector < int > > (1, vector < int > (N-i+1, 0)); //N= 4, i= 3 ==> N-i+1= 2 ==> [[0, 0]]

    vector < vector < int > > result;
    for(int v= k; v>= 0; v--){
        if (v%a[i] != 0)
            continue;
        // chon v
        int x= v/a[i];
        vector < vector < int > > r= solve(i+1, k- v);
        /*N = 3
        i= 1 == x 
        r= [ 
             2  3    2  3 
            [3, 4], [5, 6]
        ]

        result= [
            [x, 3, 4], [x, 5, 6]
        ]
        */
        for(int j= 0; j< int(r.size()); j++){
            vector < int > temp= r[j];
            temp.insert(temp.begin(), x);
            result.push_back(temp);
        }
    }
    return result;
} 
int main(){
    cin>>N>>K;
    for(int i= 1; i<=N; i++)
        a[i]= N-i+1;

    vector < vector < int > > ans= solve(1, K);
    for(int i= 0; i< (int)ans.size(); i++){
        for(int j= 0; j< N; j++){
            cout<<ans[i][j]<< " ";
        }
        cout<<endl;
    }
    if (ans.size() == 0)
        cout<<"Vo nghiem!"<<endl;

    return 0;
}

