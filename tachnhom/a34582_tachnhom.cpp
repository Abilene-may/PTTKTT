#include<iostream>
#include<map>
#include<string>
using namespace std;

const int N=1e4;
int id[N];
int size[N];
int count=1;
int lead[N];

void Create(int n){
    for (int i=0;i<n;i++){
        id[i]=i;
        size[i]=1;
        lead[i]=N;
        
    }
}

int Root(int n){
    while(id[n]!=n){
        id[n]=id[id[n]];
        n=id[n];
    }
    return n;
    
}


bool Check(int p,int q){
    return Root(p)==Root(q);
}


void Union(int p, int q){
    int pid=Root(p);
    int qid=Root(q);
    
    if(lead[pid] ==N && lead[qid]==N){
        lead[pid]=count;
        count++;
        id[qid]=pid;
        if(p!=q) 
            size[pid]+=size[qid];
        return;
    }
    
    if(pid==qid) return;


    if (lead[pid]<lead[qid]){
        lead[qid]=N;
        id[qid]=pid;
        size[pid]+=size[qid];

    }
    else{    
        lead[pid]=N;
        id[pid]=qid;
        size[qid]+=size[pid];
    }
        
        

    
}
int main(){
    int F;
    cin>>F;
    Create(N);
    map<int,string> Name;
    map<string,int> Social;
    while(F--){
        string a,b;
        cin>>a>>b;
        if (Social.count(a)==0){
            Name.insert({Name.size(),a});
            Social.insert({a,Social.size()});
        }
        if (Social.count(b)==0){
            Name.insert({Name.size(),b});
            Social.insert({b,Social.size()});
        }
        int pid=Social.find(a)->second;
        int qid=Social.find(b)->second;
        Union(pid,qid);

        
    }
    int result=0;
    for (int i=0;i<N;i++){
        if(lead[i]!=N) result++;
    }
    cout<<result<<endl;

    for(int i=0;i<N;i++){
        if (lead[i]!=N)
            cout<<Name.find(i)->second<<" "<<size[i]<<endl;
    }

    

    


    
    

    


    







}
