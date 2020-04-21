//括号匹配检验
#include <iostream>
#include <stack>
using namespace std;

bool check_parentheses(char *org){
    stack<char> my_stack;
    char current ;
    for(int i=0;i<strlen(org); i++){
        if(org[i] == '(' || org[i] == '{' || org[i] == '['  )
            my_stack.push(org[i]);
        else{
            current = my_stack.top();
            my_stack.pop();
            if(
                    current == '(' && org[i] != ')' ||
                    current == '[' && org[i] != ']' ||
                    current == '{' && org[i] != '}'
            )
                return false;

        }
    }
    if(!my_stack.empty()) return false;
    return true;
}


int main(){
    char test[] = "[][[]]({[()]})";
    cout<<check_parentheses(test)<<endl;
}