#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int x)
    {
        data= x;
        next= NULL;
    }
};
class queue
{
    private:
    node*front;
    node*rear;
    public:
    queue()
    {
        front= NULL;
        rear=NULL;
    }

int empty()
{
    if(front== NULL)
    return(1);
    else
    return(0);
}
void enqueue(int x)
{
    node*p=new node(x);
    if(empty())
    {
        front=p;
        rear=p;
    }
    else{
        rear->next=p;
        rear=p;
    }
}
int dequeue()
{
    int x=front->data;
    node*p=front;
    front=front-> next;
    delete p;
    return(x);
}
void display()
{
    node*q=front;
    while(q!=NULL)
    {
        cout<<endl<<q->data;
        q=q->next;
    }
}
int peek()
{
    return(front->data);
}
};
int main()
{
    queue q;
    int x;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    x=q.peek();
    cout<<"front element is"<<x<<endl;
    x=q.dequeue();
    cout<<"rear "<<x<<endl;
    q.display();
    q.dequeue();
    q.dequeue();
    return 0;
}
PS D:\vedika111\New folder> cd "d:\vedika111\New folder\" ; if ($?) { g++ queueusinglinkedlist.cpp -o queueusinglinkedlist } ; if ($?) { .\queueusinglinkedlist }

40
50
60front element is40
rear 40

50
60
PS D:\vedika111\New folder> 