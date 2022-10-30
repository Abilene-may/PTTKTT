#include <iostream>
#include <vector>
using namespace std;
string X,Y;
vector< vector <int> > MEMO;
int diff(int i, int j){
    return X[i] != Y[j]; 
}
int E(int i, int j){
    if (i == -1)
        return j+1;
    if (j == -1)
        return i+1;
    if (MEMO[i][j] != -1)
        return MEMO[i][j];
    int r= E(i-1, j) + 1;
    r= min(r, E(i, j-1) + 1);
    r= min(r, E(i-1, j-1) + diff(i, j));
    cout<<i<<" "<<j<<" "<<r<<endl;
    return MEMO[i][j]= r;
}
int main(){
    freopen("input.txt", "r", stdin);
    cin>>X>>Y;
    MEMO= vector < vector <int> > (X.size(), vector < int > (Y.size(), -1));
    cout<<E(X.size()-1, Y.size()-1)<<endl;
    return 0;
}