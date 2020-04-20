#include <iostream>
using namespace std;

template <class T>
class linkList{
private:
    struct node{
        T data;
        node *next;
        node(const T &data, node *n = NULL):data(data), next(n){}
        node():next(NULL){}
    };
    node *head;
public:
    linkList(){
        head = new node();
    }
    int length()const{
        int total_length = 0;
        node *p = head->next;
        while (p){
            total_length += 1;
            p = p->next;
        }
        return total_length;
    }
    int search(const T &x) const {
        int index = -1;
        node *p = head->next;
        while (p){
            index++;
            if(p->data == x) return index;
            p = p->next;
        }
        return -1;
    }
    T visit(int i) const {
        node *p = head->next;
        int index = 0;
        while(p){
            if(index == i) return p->data;
            p = p->next;
            index++;
        }
    }
    void insert(int i, const T &x){
        if(i<0) return;
        int index = 0;
        node *p = head;
        while (index < i && p){
            p = p->next;
            index++;
        }
        if(!p) return;
        node *tmp = new node(x,p->next);
        p->next = tmp;
    }
    void remove(int i){
        if(i < 0 )return;
        int index = 0;
        node *p = head;
        while (index < i && p){
            p = p->next;
            index++;
        }
        if(!p) return;
        node *tmp = p->next;
        p->next = tmp->next;
        delete tmp;
    }
    void clear(){
        node *p = head->next;
        head->next = NULL;
        while(p){
            node *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    void traverse()const{
        node *p = head->next;
        while (p){
            cout<<p->data<<'\t';
            p = p->next;
        }
    }
    ~linkList() {
        node *p = head->next;
        while (p) {
            node *tmp = p;
            p = p->next;
            delete tmp;
        }
        delete head;
    }

};

int main(){
    linkList<int> test;
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