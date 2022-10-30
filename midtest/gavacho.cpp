#include<iostream>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i =0;i<n;i++){
        if(i*2+(n-i)*4==m){
            cout<<i<<" "<<n-i<<endl;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}