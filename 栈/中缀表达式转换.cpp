//将中缀表达式转换为后缀表达式
#include <iostream>
#include <stack>
#include <map>
using namespace std;

void test_(){
    cout<<"gg"<<endl;
}

void infix_to_postfix(char *expression){
    stack<char> my_stack;
    map<char , int> priority;
    priority['+'] = 1, priority['-']=1;
    priority['*'] = 2, priority['/'] =2;
    priority['^'] = 3;
    int index = 0;
    while (index < strlen(expression)){
        if(expression[index] - '0' >= 0 && expression[index] -'0' <= 9) {
            cout << expression[index];
        }
        else if(expression[index] == '(')
            my_stack.push(expression[index]);
        else if(expression[index] == ')'){
            index ++;
            while (expression[index] != '('){
                cout<<expression[index++];
            }
        } else{
            do{
                my_stack.pop();
                cout<<expression[index];
                }
            while (priority[expression[index]]<priority[expression[my_stack.top()]]);
            my_stack.push(expression[index]);
            }
        index++;
        }
    while (!my_stack.empty())
    {
        cout<<my_stack.top();
        my_stack.pop();
    }
}

int main(){
    char test[]="5*(7-2*3)+8/2";
    infix_to_postfix(test);
    test_();
}