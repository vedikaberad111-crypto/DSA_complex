#include<iostream>
using namespace std;
#define MAX 5
class stack
{
    private:
    int a[MAX];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    int empty()
    {
        if(top==-1)
        return(1);
        else
        return(0);
    }

    int full()
    {
        if(top==MAX-1)
        return(1);
        else
        return(0);
    }

    void push(int x)
    {
        top++;
        a[top]=x;
    }

    int pop()
    {
     int x=a[top];
     top--;
     return(x);
    }

    int peek()
    {
        return(a[top]);
    }

    void display()
    {
        for (int i=top; i>=0; i--)
     cout<<a[i]<<endl;
    }
};

int main()
{
    stack s;
    
    if(s.full())
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        s.push(10);
        cout<<"stack contents after push operation: "<<endl;
    }
    s.display();

    if(s.full())
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        s.push(20);
        cout<<"stack contents after push operation: "<<endl;
    }
    s.display();

    if(s.full())
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        s.push(30);
        cout<<"stack contents after push operation: "<<endl;
    }
    s.display();

    if(s.full())
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        s.push(40);
        cout<<"stack contents after push operation: "<<endl;
    }
    s.display();
    if(s.full())
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        s.push(50);
        cout<<"stack contents after push operation: "<<endl;
    }
    s.display();

    if(s.full())
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        s.push(60);
        cout<<"stack contents after push operation: "<<endl;
    }
    s.display();

    if (s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"popped out element is "<<s.pop();
    }
    cout<<"stack contents after pop operation: "<<endl;
    s.display();

    if (s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"popped out element is "<<s.pop();
    }
    cout<<"stack contents after pop operation: "<<endl;
    s.display();

    if (s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"popped out element is "<<s.pop();
    }
    cout<<"stack contents after pop operation: "<<endl;
    s.display();

    if (s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"popped out element is "<<s.pop();
    }
    cout<<"stack contents after pop operation: "<<endl;
    s.display();

    if (s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"popped out element is "<<s.pop();
    }
    cout<<"stack contents after pop operation: "<<endl;
    s.display();

    if (s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"popped out element is "<<s.pop();
    }
    cout<<"stack contents after pop operation: "<<endl;
    s.display();
    return(0);
}
  
output:
PS C:\Users\Student\OneDrive\Desktop\vedika111>g++ Stack_using_array.cpp -o Stack_using_array
PS C:\Users\Student\OneDrive\Desktop\vedika111>./Stack_using_array
stack contents after push operation: 
10
stack contents after push operation: 
20
10
stack contents after push operation: 
30
20
10
stack contents after push operation: 
40
30
20
10
stack contents after push operation: 
50
40
30
20
10
stack is full
50
40
30
20
10
popped out element is 50stack contents after pop operation: 
40
30
20
10
popped out element is 40stack contents after pop operation: 
30
20
10
popped out element is 30stack contents after pop operation: 
20
10
popped out element is 20stack contents after pop operation: 
10
popped out element is 10stack contents after pop operation: 
stack is empty
stack contents after pop operation: 