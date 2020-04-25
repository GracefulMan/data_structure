// 队列的顺序实现
#include <iostream>
using namespace std;
template <class T>
class seqQueue {
private:
    int front;
    int rear;
    int maxSize;
    T *data;
    void doubleSpace(){
        T *tmp = new T [maxSize * 2];
        for(int i=1;i<maxSize;i++){
            tmp[i] = data[(front + i) % maxSize];
        }
        front = 0;
        rear = maxSize - 1;
        maxSize *= 2;
        delete [] data;
        data = tmp;
    }
public:
    seqQueue(int maxsize=10):maxSize(maxsize),front(0),rear(0) {
        data = new T [maxsize];
    }
    bool isEmpty() const {
        return rear == front;
    }
    void enQueue(const T &x) {
        if((rear + 1) % maxSize == front)
            doubleSpace();
        rear = (rear + 1) % maxSize;
        data[rear] = x;
    }
    T deQueue(){
        front = (front + 1) % maxSize;
        return data[front];
    }
    T getHead()const{
        return data[(front + 1) % maxSize];
    }
    ~seqQueue(){
        delete [] data;
    }
};

int main(){
    seqQueue<int> myQueue(3);
    for(int i=0;i<15;i++)
        myQueue.enQueue(i);
    while (!myQueue.isEmpty()){
        cout<<myQueue.getHead()<<'\t';
        myQueue.deQueue();
    }
}