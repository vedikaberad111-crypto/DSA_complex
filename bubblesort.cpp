#include <iostream>
using namespace std;
void bubblesort(int a[], int n)
{
    int temp;
    for(int i=0; i<n-1;i++)
    {
        for(int j=0; j<n-1;j++)
      {
        if(a[j]> a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
      }  

    }
}
int main()
{
    int a [20] ,n ;
    cout<<"how many elements to sort";
    cin>>n;
    cout<<"enter"<<n<<"unsorted element";
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    bubblesort(a,n);
    cout<<"sorted list is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }

}
PS C:\Users\Student\OneDrive\Desktop\vedika111> cd "c:\Users\Student\OneDrive\Desktop\vedika111\" ; if ($?) { g++ bubblesort.cpp -o bubblesort } ; if ($?) { .\bubblesort }
how many elements to sort5
enter5unsorted element 7 5 4 3 2
sorted list is
2
3
4
5
7