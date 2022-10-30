#include <iostream>

using namespace std;
int n,sum=0,f[10000],d[10000];
int a[100];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	   {
	   	cin>>a[i];
	   	sum=sum+a[i];
	   }
	sum =sum/2;
//QUy hoach dong
	for (int i=1;i<=sum;i++)
	{
        f[i] = INT_MAX;
	   for (int j=1;j<=n;j++)
	      if (i>=a[j] && j>f[i-a[j]]) 
	      {
	      	f[i]=j;
	      	break;
		  }
	}
int c  =0 ,b = 0 ;
//Truyvet
	while (f[sum] > n) sum--;
	while (sum > 0)
	{
		d[f[sum]]=1;
		sum=sum-a[f[sum]];
	}
	for (int i=1;i<=n;i++)	{   
        if (d[i]==1) {
            cout<<a[i]<<" ";
            c +=a[i]; 
        }
        }
        cout<<"\n";
	for (int i=1;i<=n;i++) {
        if (d[i]!=1){ 
            b +=a[i]; 
            cout<<a[i]<<" ";
        }
        }
	cout<<endl;
    cout<<abs(b-c);
}
