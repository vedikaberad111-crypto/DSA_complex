# include <iostream>
using namespace std;
int linear_search(int a[] ,int n ,int x)
{
    for(int i=0 ; i<n; i++ )
    {
        if (a[i]==x)
        return(i);
    }
    return(-1);
}
  int main()
  {
    int a[20];
    int n;
    cout<<"How many elements";
    cin>>n;
    cout<<"Enter"<<n<<"elements";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int x;
    cout<<"Enter element to search";
    cin>>x;
    int location= linear_search(a,n,x);
    if(location==-1)
    cout<<"Element is not found";
    else
    cout<<"Element is found at index :"<<location;
    return(0);
  }
  PS C:\Users\Student\OneDrive\Desktop\vedika111> cd "c:\Users\Student\OneDrive\Desktop\vedika111\" ; if ($?) { g++ linearsearch.cpp -o linearsearch } ; if ($?) { .\linearsearch }
How many elements 3
Enter3elements 4 5 6
Enter element to search 5
Element is found at index :1