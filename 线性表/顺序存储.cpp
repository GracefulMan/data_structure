#include <iostream>
using namespace std;


template <class T>
class seqList{
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
    };
public:
    seqList(int maxsize=10):currentLength(0),maxSize(maxsize){
        data = new T [maxsize];
    }

    int length()const {
        return currentLength;
    }

    int search(const T &x) const {
        for(int i=0;i<currentLength;i++){
            if(data[i] == x) return i;
        }
        return -1;
    }

    T visit(int i) const {
        if (i>=currentLength || i<0){
            cerr<<"error index"<<endl;
            exit(0);
        }
        return data[i];
    }

    void insert(int i,const T &x){
        if(i < 0 || i > currentLength) return;
        if(currentLength == maxSize){
            doubleSpace();
        }
        for(int j=currentLength;j>i;j--)
            data[j] = data[j-1];
        data[i] = x;
        currentLength++;
    }

    void remove(int i){
        if(i < 0 || i >=currentLength) return;
        for(int j=i;j<currentLength - 1; j++)
            data[j] = data[j + 1];
        currentLength--;
    }
    void clear(){
        currentLength = 0;
    }
    void traverse()const {
        for(int i=0;i<currentLength;i++)
            cout<<data[i]<<'\t';
    }
    ~seqList(){
        delete [] data;
    }
};


int main(){
    seqList<int> test;
    for(int i=0;i<100;i++){
        test.insert(i,i);
    }
    test.traverse();
    cout<<endl;
    cout<<"current size:"<<test.length()<<endl;
    cout<<"55:"<<test.visit(55)<<endl;
    cout<<"search for 55:"<<test.search(55)<<endl;
    for(int i=0;i<10;i++)
        test.remove(0);
    test.traverse();
    cout<<endl;
    cout<<"current size:"<<test.length()<<endl;
    test.clear();
    cout<<"current size:"<<test.length()<<endl;
}