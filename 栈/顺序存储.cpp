#include <iostream>
using namespace std;

template <class T>
class seqStack{
private:
    int currentLength;
    int maxSize;
    T *data;
    void doubleSpace(){
        T *tmp = new T [maxSize * 2];
        for(int i=0;i<currentLength;i++){
            tmp[i] = data[i];
        }
        maxSize *= 2;
        delete [] data;
        data = tmp;
    }
public:
    seqStack(int maxsize):maxSize(maxsize), currentLength(0){
        data = new T [maxsize];
    }
    void push(const T &x) {
        if (currentLength == maxSize) doubleSpace();
        data[currentLength++] = x;
    }
    T pop(){
        return data[--currentLength];
    }
    T top()const{
        return data[currentLength - 1];
    }
    bool isEmpty()const{
        return currentLength == 0;
    }
    ~seqStack(){
        delete [] data;
    }
};


int main(){
    seqStack<int> test(10);
    for(int i=0;i<100;i++)
        test.push(i);
    while(!test.isEmpty()){
        cout<<test.top()<<'\t';
        test.pop();
    }

}