#include <iostream>
using namespace std;
class complex{
    private:
    float real;
    float imag;
    public:
    complex()
    {
        real=0;
        imag=0;
    }
    complex(float r,float i)
    {
        real=r;
        imag=i;
    }
    ~complex(){
            }
    void display(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }  
    complex operator+(complex c)
    {
        float r=real+c.real;
        float i=imag+c.imag;
        return complex(r,i);
    }      
};
int main()
{
    complex c1(2.0,3.0);
    cout<<"complex no is"<<endl;
     c1.display();
    complex c2(5.0,7.0);
    cout<<"complex no is"<<endl;
     c2.display();
    complex c3(3.0,5.0);
    cout<<"complex no is"<<endl;
     c3.display();
    complex c4(9.0,1.0);
    cout<<"complex no is"<<endl;
     c4.display();
     complex sum=c1+c2;
     sum.display();
     return(0);

}
PS C:\Users\Student\OneDrive\Desktop\vedika111> cd "c:\Users\Student\OneDrive\Desktop\vedika111\" ; if ($?) { g++ complex.cpp -o complex } ; if ($?) { .\complex }
complex no is
2+3i
complex no is
5+7i
complex no is
3+5i
complex no is
9+1i
7+10i