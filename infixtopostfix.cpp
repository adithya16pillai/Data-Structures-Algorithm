#include <iostream>
using namespace std;

class Stack {
    int top;
    int max;
    int* j;
 
public:
    Stack(int size){
        top = -1;
        max = size;
        j = new int [max];
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool Stack::isEmpty(){
    return (top < 0); 
} 

bool Stack::isFull(){
    return (top == max - 1); 
    
} 

int Stack::peek(){ 
    return j[top]; 
    
} 
bool Stack::push(int x) {
    if (top >= (max - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        top++;
        j[top] = x;
        return true;
    }
}
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = j[top]; 
        top--; return x; 
    }
}
int priority (char z)
{
    if(z == '(') {
        return 0;
    }
    if(z == '+' || z =='-') {
        return 1;
    } if(z == '*' || z =='/') {
        return 2;
    } if(z == '^') {
        return 3;
    }
    return 0;
}

string convert(string infix)
{
    int i = 0;
    string postfix = "";
    
    Stack s(20);
    while(infix[i]!='\0')
    {
       if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')
       {
           postfix += infix[i]; 
            i++; 
       } else if(infix[i]=='(') {
           s.push(infix[i]);
           i++; 
       } else if(infix[i]==')') { 
        while(s.peek()!='(')
            postfix += s.pop(); 
        s.pop(); 
        i++;
        } else { 
        while (!s.isEmpty() && priority(infix[i]) <= priority(s.peek())){
            postfix += s.pop();
        } 
        s.push(infix[i]);
        i++;
        }
    } 
    while(!s.isEmpty()){
        postfix += s.pop();
        }
    cout << "The Postfix is : " << postfix; 
    return postfix;
    
} 

int main() {
    string infix;
    string postfix; 
    cout << "Enter infix expression: ";
    cin >> infix;
    postfix = convert(infix);
    return 0;
}