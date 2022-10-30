#include <bits/stdc++.h>
using namespace std;
int n,ct=1,vlt;
const int maxn=2e5+5;
unordered_map<string,int> M;
string s[maxn];
int par[maxn];
int fpar(int u){
    if(par[u]<0) return u;
    par[u]=fpar(par[u]);
    return par[u];
}
void ghep(int u,int v){
    if(par[u]>par[v]) swap(u,v);
    if(u>v) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>n;
    memset(par,255,sizeof(par));
    for(int i = 1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        if(M[a]==0) M[a]=ct++;
        s[ct-1]=a;
        if(M[b]==0) M[b]=ct++;
        s[ct-1]=b;
        if(fpar(M[a])!=fpar(M[b])) ghep(fpar(M[a]),fpar(M[b]));
    }
    for (int i = 1; i<ct; i++) if(par[i]<0) vlt++;
    cout<<vlt<<endl;
    for (int i = 1; i<ct; i++) if(par[i]<0) cout<<s[i]<<" "<<abs(par[i])<<endl;
    return 0;
}