#include<iostream>
using namespace std;
#define MAX 5
class queue
{
    private:
    int a[MAX];
    int front;
    int rear;
    public:
    queue()
    {
        front=-1;
        rear=-1;
    }
    int empty()
    {
        if(front==-1 && rear==-1)
        return(1);
        else
        return(0);
    }
    int full()
    {
        if(rear==MAX-1)
        return(1);
        else
        return(0);
    }
    void enqueue(int x)
    {
        if(front==-1 && rear==-1)
        {
        front++;
        rear++;
        }
        else
        {
            rear++;
        }
        a[rear]=x;
    }
    int dequeue()
    {
        int x=a[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
        return(x);
    }
    int peek()
    {
        return(a[front]);
    }
    void display(void)
    {
        for(int i=front;i<=rear;i++)
        cout<<"\t"<<a[i];
    }

};
int main()
{
    queue q;
    if(q.full())
    {
        cout<<"queue full";
    }
    else
    {
        q.enqueue(10);
    }
    cout<<"\n queue contents";    
    q.display();
     if(q.full())
    {
        cout<<"queue full";
        }
    else
    {
        q.enqueue(20);
    }

    if(q.full())
    {
        cout<<"queue full";
    }
    else
    {
        q.enqueue(30);
    }
    cout<<"\n queue contents";                                                                                                                                                                                                                                                                                                                                                                                                                                   
    q.display();
     if(q.full())
    {
        cout<<"\n queue full";
    }
    else
    {
        q.enqueue(40);
    }
    cout<<"\n queue contents";                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    q.display();
     if(q.full())
    {
        cout<<"queue full";
    }
    else
    {
        q.enqueue(50);
    }
     cout<<"\n queue contents";                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    q.display();
    if(q.full())
    {
        cout<<"\n queue full";
    }
    else
    {
        q.enqueue(60);
    }
    cout<<"\n queue contents";                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    q.display();
     if(q.empty())
    {
        cout<<"\n queue is empty";
    }
    else
    {
        cout<<"\n dequed element is "<<q.dequeue();
    }
   q.display();

     if(q.empty())
    {
        cout<<"\n queue is empty";
    }
    else
    {
        cout<<"\n dequed element is "<<q.dequeue();
    }
    q.display();

    if(q.empty())
    {
        cout<<"\n queue is empty";
    }
    else
    {
        cout<<"\n dequed element is "<<q.dequeue();
    }
    q.display();

    if(q.empty())
    {
        cout<<"\n queue is empty";
    }
    else
    {
        cout<<"\n dequed element is "<<q.dequeue();
    }
    q.display();

    if(q.empty())
    {
        cout<<"\n queue is empty";
    }
    else
    {
        cout<<"\n dequed element is "<<q.dequeue();
    }
    
     if(q.empty())
    {
        cout<<"\n queue is empty";
    }
    else
    {
        cout<<"\n dequed element is "<<q.dequeue();
    }
     return(0);
}

// PS C:\vedika111> cd "c:\vedika111\" ; if ($?) { g++ queueasstack.cpp -o queueasstack } ; if ($?) { .\queueasstack }

//  queue contents 10
//  queue contents 10      20      30
//  queue contents 10      20      30      40
//  queue contents 10      20      30      40      50
//  queue full
//  queue contents 10      20      30      40      50
//  dequed element is 10   20      30      40      50
//  dequed element is 20   30      40      50
//  dequed element is 30   40      50
//  dequed element is 40   50
//  dequed element is 50
//  queue is empty