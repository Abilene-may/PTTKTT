#include <bits/stdc++.h>
using namespace std;

int n, p;
int m[15];
int f[1<<14]; 
// f[mask] la ket qua tai trang thai mask
// mask= 0100010... neu bit thu i cua mask = 1 co nghia la hang thu i da duoc chuyen di va nguoc lai
int dp(int mask){
    // for(int j= 0; j<n;j++)
    //     if (mask & (1<<j)) cout<<'1';
    //     else cout<<'0';
    // cout<<endl;
    if (mask == (1<<n)-1) return 0;
    if (f[mask] != -1) return f[mask];
    int cost= 1000*14;
    for (int i= 0; i<n;i++){
        if (mask & (1<<i)) continue; // Da gui 
        cost= min(cost, dp(mask | (1<<i))+ m[i]); // Gui luon, khong can nghi 
        // Xet moi trang thai cac tap con chua i tao thanh 1000
        for(int j= 1; j<(1<<n); j++){
            int temp= 0;
            if (mask & j) continue; // 2 trang thai bi trung nhau tai bit nao do
            if ((j&(1<<i)) == 0) continue; // Trang thai nay khong chon i
            for(int k= 0; k<n;k++)
                if (j & (1<<k)) 
                    temp+= m[k];
            if (temp == 1000)
                cost= min(cost, dp(mask | j)+p); // Lua chon gui hay khong
        }
    }
    return f[mask]= cost;
}

int main(){
    //freopen("input.00","r",stdin);
    cin>>n>>p;
    for(int i=0 ;i<n;i++)
        cin>>m[i];
    memset(f,-1, sizeof f);
    cout<<dp(0)<<endl;
    return 0;
}