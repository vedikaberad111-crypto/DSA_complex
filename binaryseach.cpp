#include <iostream>
using namespace std;
int binary_search(int a[], int n,int x)
{
    int first=0, last=n-1, mid;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(a[mid]==x)    
        {
            return(mid);
        }
        else if(a[mid]<x) 
        {
          first=mid+1;
        }
        else if(a[mid]<x)
        {
            last=mid-1;
        }
    }
    return(-1);
}
int main()
{
    int n,x;
    int a[20];
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter"<<n<<"sorted integer:\n";
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the target element to searched";
    cin>>x;
    int p=binary_search(a,n,x);
    if(p==-1)cout<<"Element not found";
    else cout<<"Element found at location"<<p;
    return(0);
}
PS C:\Users\Student\OneDrive\Desktop\vedika111> cd "c:\Users\Student\OneDrive\Desktop\vedika111\" ; if ($?) { g++ binarysearch.cpp -o binarysearch } ; if ($?) { .\binarysearch }
Enter the size of array: 5
Enter5sorted integer:
 2 3 4 5 6 
Enter the target element to searched 4 
Element found at location2