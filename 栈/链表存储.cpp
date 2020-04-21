#include <iostream>
using namespace std;

template <class  T>
class linkStack{
private:
    struct node {
        T data;
        node *next;
        node():next(NULL){}
        node(const T &x, node *n=NULL):data(x),next(n){}
    };
    node *head;
public:
    linkStack(){
        head = new node;
    }
    void push(const T &x){
        node *tmp = new node(x, head->next);
        head->next = tmp;
    }
    T pop(){
        node *tmp = head->next;
        T val = tmp->data;
        head->next = tmp->next;
        delete tmp;
        return val;
    }
    T top()const {
        return head->next->data;
    }
    bool isEmpty()const{
        return head->next==NULL;
    }
    ~linkStack(){
        delete head;
    }
};

int main(){
    linkStack<int> test;
    for(int i=0;i<100;i++){
        test.push(i);
    }
    while(!test.isEmpty()){
        cout<<test.pop()<<'\t';
    }


}