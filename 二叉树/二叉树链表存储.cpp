#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class  T>
class BinaryTree{
private:
    struct node{
        T data;
        node *left;
        node *right;
        node():left(nullptr),right(nullptr){}
        node(const T &x, node *L= nullptr, node *R= nullptr):data(x),left(L),right(R){}
    };
    node *root;
    void clear(node *t){
        if(t->left) clear(t->left);
        if(t->right) clear(t->right);
        delete t;
    }
    int size(node *t)const{
        if(!t) return 0;
        else return 1 + size(t->left) + size(t->right);
    }
    int height(node *t)const{
        if(!t) return 0;
        else return max(height(t->left), height(t->right)) + 1;
    }
    void preOrder(node *t)const{
        if(t){
            cout<<t->data<<'\t';
            preOrder(t->left);
            preOrder(t->right);
        }
    }
    void midOrder(node *t)const{
        if(t){
            midOrder(t->left);
            cout<<t->data<<'\t';
            midOrder(t->right);
        }
    }
    void postOrder(node *t) const {
        if(t){
            postOrder(t->left);
            postOrder(t->right);
            cout<<t->data<<'\t';
        }
    }




public:
    BinaryTree():root(nullptr){}
    BinaryTree(const T &x){
        root = new node(x);
    }
    BinaryTree(node *p){
        root = p;
    }
    T getRoot()const{ return root->data;}
    T getLeft()const{return root->left->data;}
    T getRight()const{return root->right->data;}
    void makeTree(const T &x, BinaryTree &lt, BinaryTree &rt){
        root = new node(x, lt, rt);
        lt.root = nullptr;
        rt.root = nullptr;
    }
    void deleteLeft(){
        BinaryTree tmp = root->left;
        root->left = nullptr;
        tmp.clear();
    }
    void deleteRight(){
        BinaryTree tmp = root->right;
        root->right = nullptr;
        tmp.clear();
    }
    bool isEmpty()const{
        return root == nullptr;
    }
    void clear(){
        clear(root);
        root = nullptr;
    }
    int size() const {
        return size(root);
    }
    int height() const {
        return height(root);
    }
    void preOrder()const {
        preOrder(root);
    }
    void midOrder()const{
        midOrder(root);
    }
    void postOrder()const{
        postOrder(root);
    }
    void createTree(T flag){
        queue<node *> que;
        node *current;
        T x,ldata,rdata;
        cout<<"创建根节点：";
        cin >> x;
        root = new node(x);
        que.push(root);
        while(!que.empty()){
            current = que.front();
            que.pop();
            cout<<"输入"<<current->data<<"的两个子节点：";
            cin>>ldata>>rdata;
            if(ldata!=flag) que.push(current->left = new node(ldata));
            if(rdata!=flag) que.push(current->right = new node(rdata));
        }
    }
    // 前序遍历的非递归实现
    void preOrderWithoutRecursive()const {
        stack<node*> data_stack;
        node *current = root;
        data_stack.push(current);
        while (!data_stack.empty()){
            current = data_stack.top();
            cout<<current->data<<'\t';
            data_stack.pop();
            if(current->right) data_stack.push(current->right);
            if(current->left) data_stack.push(current->left);
        }
    }
    void midOrderWithoutRecursive()const {
        struct newNode{
            node *Node;
            int num;
            newNode(node *p):Node(p), num(0){}
        };
        stack<newNode> data_stack;
        newNode current(root);
        data_stack.push(current);
        while (!data_stack.empty()){
            current = data_stack.top();
            data_stack.pop();
            if(++current.num == 2){
                cout<<current.Node->data<<'\t';
                if(current.Node->right)
                    data_stack.push(newNode(current.Node->right));
            } else{
                data_stack.push(current);
                if(current.Node->left)
                    data_stack.push(newNode(current.Node->left));
            }
        }
    }

    void postOrderWithoutRecursive()const {
        struct newNode {
            node * Node;
            int num;
            newNode(node *p):Node(p),num(0){}
        };
        stack<newNode> data_stack;
        newNode current(root);
        data_stack.push(current);
        while (!data_stack.empty()){
            current = data_stack.top();
            data_stack.pop();
            if(++current.num == 3){
                cout<<current.Node->data<<'\t';
                continue;
            }
            data_stack.push(current);
            if(current.num == 1){
                if(current.Node->left) data_stack.push(newNode(current.Node->left));
            } else{
                if(current.Node->right) data_stack.push(newNode(current.Node->right));
            }
        }

    }
    ~BinaryTree(){
        clear(root);
    }
};


int main(){
    BinaryTree<int> testTree;
    testTree.createTree(0);
    cout<<"高度:"<<testTree.height()<<endl;
    cout<<"规模:"<<testTree.size()<<endl;
    cout<<"前序遍历:";
    testTree.preOrder();
    cout<<endl;
    cout<<"前序遍历(非递归实现):";
    testTree.preOrderWithoutRecursive();
    cout<<endl;

    cout<<"中序遍历:";
    testTree.midOrder();
    cout<<endl;
    cout<<"中序遍历(非递归实现):";
    testTree.midOrderWithoutRecursive();
    cout<<endl;

    cout<<"后序遍历:";
    testTree.postOrder();
    cout<<endl;
    cout<<"后序遍历(非递归实现):";

    testTree.postOrderWithoutRecursive();
    cout<<endl;
}