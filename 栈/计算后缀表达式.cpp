// 计算后缀表达式的值
#include <iostream>
#include <stack>
using namespace std;

double calculate_postfix_expression(char *expression){
    stack<int> my_stack;
    int first_num, second_num,tmp;
    for(int i=0;i<strlen(expression);i++){
        if(expression[i] - '0'>=0 && expression[i] - '0' <=9){
            my_stack.push(expression[i] - '0');
        } else {
            first_num = my_stack.top();
            my_stack.pop();
            second_num = my_stack.top();
            my_stack.pop();
            switch (expression[i]) {
                case '+':
                    tmp = second_num + first_num;
                    break;
                case '-':
                    tmp = second_num - first_num;
                    break;
                case '*':
                    tmp = second_num * first_num;
                    break;
                case '/':
                    tmp = second_num / first_num;
                    break;
                default:
                    continue;
            }
            my_stack.push(tmp);
        }

    }
    return my_stack.top();
}

int main(){
    char test[] = "5723*-*82/+";//5*(7-2*3)+8/2
    cout<<calculate_postfix_expression(test)<<endl;

}