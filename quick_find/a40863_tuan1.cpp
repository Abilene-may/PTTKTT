#include <iostream>

using namespace std;

class quickfind {
private:
  int *id;

public:
  quickfind(int n);
  bool connected(int p, int q);
  void Union(int p, int q);
  void print();
};
quickfind::quickfind(int n) {
  id = new int[n];
  for (int i = 0; i < n; i++)
    id[i] = i;

}
bool quickfind::connected(int p, int q) {
  if (id[p] == id[q]) {
    return true;
  }
  return false;
}
void quickfind::Union(int p, int q) {
  int pid = id[p];
  int qid = id[q];
  for (int i = 0; i <= (sizeof(id) + 1); i++)
    if (id[i] == pid)
      id[i] = qid;
}
void quickfind::print() {
  for (int i = 0; i <= (sizeof(id) + 1); i++)
    cout << id[i] << " ";
  cout << endl;
}
class quickUnion{
private:
  int *id;
public:
  quickUnion(int n);
  int root(int i);
  bool connected(int p, int q);
  void Union(int p, int q);
};
quickUnion::quickUnion(int n)
{
  id = new int[n];
  for (int i=0; i<n; i++)
    id[i] = i;
}
int quickUnion::root(int i){
  while (i != id[i])
    i = id[i];
    return i;
  
}
bool quickUnion::connected(int p, int q){
  if( root(p)==root(q))
    return true;
  return false;
}
void quickUnion::Union(int p, int q){
  int i = root(p);
  int j = root(q);
  id[i] = j;
}
// Weighting 
class Improvement1_weighting
{
private:
  int *id;
  int *sz;

public: 
  Improvement1_weighting(int n) {
  id = new int[n];
  sz = new int[n];
  for (int i = 0; i < n; i++)
  { id[i] = i;
    sz[i] = 1;
  }
  
  }
  int root(int i)
  {
    while (i != id[i]){
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }
  bool connected(int p, int q) {
    if (root(p) == root(q)){
      return true;
    }
    return false;
  }
  void Union(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i ==j) 
    {

      return;
    }else{
      if (sz[i]<sz[j]) 
      {
        id[i] = j; sz[j] += sz[i];

      }
      else { 
        id[j] = i; sz[i] += sz[j]; 
      }
    }

  }
  void printszoftree() {
    for (int i = 0; i <= (sizeof(sz) + 1); i++)
      cout << sz[i] << " ";
    cout << endl;
  }


};

int main() {
  cout<<"---Inprovament1 weighting ---\n";
  Improvement1_weighting w(10);
  
  w.Union(4,3);
  w.Union(3,8);
  w.Union(6,5);
  w.Union(9,4);
  w.Union(2,1);
  if (w.connected(9, 3) == true) {
    cout << "9 and 3 are connected\n";
  } else {
    cout << "9 and 3 didn't connected\n";
  }
  if (w.connected(8, 3) == true) {
    cout << "8 and 3 are connected\n";
  } else {
    cout << "8 and 3 didn't connected\n";
  }
  w.Union(5,0);
  w.Union(7,2);
  w.Union(6,1);
  w.connected(7, 5);
  w.Union(7,3);
  w.connected(4, 1);
  
  cout<<endl;
  quickfind timnhanh(10);
  cout<<"--- Quick find ---\n";
  timnhanh.Union(4, 3);
  timnhanh.Union(3, 8);
  timnhanh.Union(6, 5);
  timnhanh.Union(9, 4);
  timnhanh.Union(2, 1);
  if (timnhanh.connected(9, 3) == true) {
    cout << "9 and 3 are connected\n";
  } else {
    cout << "9 and 3 didn't connected\n";
  }
  if (timnhanh.connected(8, 3) == true) {
    cout << "8 and 3 are connected\n";
  } else {
    cout << "8 and 3 didn't connected\n";
  }

  timnhanh.Union(5, 0);
  timnhanh.Union(7, 2);
  timnhanh.Union(6, 1);
  if (timnhanh.connected(7, 5) == true) {
    cout << "7 and 5 are connected\n";
  } else {
    cout << "7 and 5 didn't connected\n";
  }

  timnhanh.Union(7, 3);
  if (timnhanh.connected(4, 1) == true) {
    cout << "4 and 1 are connected\n";
  } else {
    cout << "4 and 1 didn't connected\n";
  }
  cout<<endl;

  quickUnion u(10);
  cout<<"--- Quick union ---\n";
  u.Union(4, 3);
  u.Union(3, 8);
  u.Union(6, 5);
  u.Union(9, 4);
  u.Union(2, 1);
  if (u.connected(9, 3) ==true) {
    cout << "9 and 3 are connected\n";
  } else {
    cout << "9 and 3 didn't connected\n";
  }
  if (u.connected(8, 3) ==true) {
    cout << "8 and 3 are connected\n";
  } else {
    cout << "8 and 3 didn't connected\n";
  }

  u.Union(5, 0);
  u.Union(7, 2);
  u.Union(6, 1);
  if (u.connected(7, 5) == true) {
    cout << "7 and 5 are connected\n";
  } else {
    cout << "7 and 5 didn't connected\n";
  }
   if (u.connected(4, 1) == true) {
    cout << "4 and 1 are connected\n";
  } else {
    cout << "4 and 1 didn't connected\n";
  }


  return 0;
}
