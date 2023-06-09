#include <iostream>
#include <string>

using namespace std;
class myQueue{
    private:
        int *arr;
        int cap;
        int size;
        int front;
    public:
        myQueue(int cap)
        {
            this->cap = cap;
            arr = new int[cap];
            size = 0;
            front = 0;
        }
        void push(int data)
        {
            if(size == cap)
            {
                cout<<"Overflow"<<endl;
                return;
            }
            int rear = (front + size -1)%cap;
            rear = (rear + 1)%cap;
    //        cout<<"rear: "<<rear<<" arr[rear]: "<<arr[rear]<<endl;
            arr[rear] = data;
            size++;
        }
        int pop()
        {
            if(size == 0)
            {
                cout<<"Underflow: "<<endl;
                return -1;
            }
            int data = arr[front];
            front = (front + 1)%cap;
            size--;
            return data;
        }
        int sizeQueue()
        {
            return size;
        }
        int top()
        {
            if(size == 0)
            {
                cout<<"Underflow"<<endl;
                return -1;
            }       
  //          cout<<"front: "<<front<<" top value: "<<arr[front]<<endl;
            return arr[front];
        }
};
int main()
{
    myQueue mq(5);
    mq.push(20);
    mq.push(30);
    mq.push(40);
    mq.push(50);
    mq.push(69);
    mq.push(33);
    cout<<"top: "<<mq.top()<<endl;
    cout<<"pop: "<<mq.pop()<<endl;
    while(mq.sizeQueue() > 0)
    {
        int data = mq.top();
        mq.pop();
        cout<<"data: "<<data<<endl;
    }
}