// 队列的链表存储
#include <iostream>
using namespace std;


template <class  T>
class linkQueue{
private:
    struct node{
        T data;
        node *next;
        node():next(NULL){}
        node(T data, node *n=NULL):data(data), next(n){}
    };
    node *front;
    node *rear;
public:
    linkQueue():front(NULL), rear(NULL){}
    bool isEmpty()const{
        return front == NULL;
    }
    void enQueue(const T &x){
        node *tmp = new node (x);
        if(rear == NULL)
            front = rear = tmp;
        else
        {
            rear->next = tmp;
            rear = tmp;
        }
    }
    T deQueue(){
        node *tmp = front;
        front = front->next;
        T data = tmp->data;
        if(front == NULL) rear = NULL;
        delete tmp;
        return data;
    }
    T getHead()const {
        return front->data;
    }
    ~linkQueue(){
        node *tmp;
        while (front!=NULL){
            tmp = front;
            front =front->next;
            delete tmp;
        }

    }
};

int main(){
    linkQueue<int> myQueue;
    for(int i=0;i<15;i++)
        myQueue.enQueue(i);
    while (!myQueue.isEmpty()){
        cout<<myQueue.getHead()<<'\t';
        myQueue.deQueue();
    }
}