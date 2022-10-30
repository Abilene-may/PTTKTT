#include <iostream>
using namespace std;
int n, a[200];
int MEMO[200];
int L(int i){ // L[i] la do dai lon nhat cua chuoi con tang ket thuc tai 
    if (i == 0)
        return 1;
    if (MEMO[i] != -1)
        return MEMO[i];
    
    // cout<<"L("<<i<<")"<<endl;
    int r= 0;               
    for(int j=0; j<i; j++){     
        if (a[i] >= a[j])
            r= max(r, L(j));
    }
    return MEMO[i]= r+1;
}
int main(){
    freopen("input.txt", "r", stdin);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
        MEMO[i]= -1;
    }
    int ans= 0;
    for(int i=0;i<n;i++)
        ans= max(ans, L(i));
    cout<<ans<<endl;
    return 0;
}