#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;
int n, l, r;
const int maxx = 1e6;
int main()
{
    cin>>n;
    int count =1;
    while(n-- && 2<= l<= r<= 1e12)
    {
      int k[maxx]; 
      int j=0;
      cin>>l>>r;
      for(int m=1;m<=r;m++)
        {
          int i=2;
          while(i++)
            {
              if(pow(m,i)>=l && pow(m,i)<=r)
              {
                k[j] = i;
                j++;
              }else { k[j]=0; j++; break;}
            }
        }
      int max =1;
      while(j--)
        {
          if(max < k[j])
          {
            max = k[j];
          }
        }
      cout<<"Case #"<<count<<": "<<max<<endl;
      count++;
       
    }
    return 0;
}