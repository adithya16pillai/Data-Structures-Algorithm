#include <iostream>
using namespace std;

void push() {
    int top, stack_arr[10];
    int pushed_item, n;
    cout << "Enter the elements which needs to be pushed: ";
    cin >> pushed_item;
    if(top == (n-1)) {
        cout << "Stack Overflow" << endl;
    } else {
        top = top + 1;
        stack_arr[top] = pushed_item;
    }
}

void pop() {
    int top, stack_arr[10];
    if(top == -1) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << "The popped element is: " << stack_arr[top] << endl;
        top = top - 1;
    }
}

void display() {
    int top, stack_arr[10];
    int i;
    if(top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements are: " << endl;
        for(i = top; i >= 0; i--) {
            cout << stack_arr[i];
        }   
    }
}

int main() {
    int top = -1;
    int choice;

    while(1) {
        cout << endl << "Choices: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                push();
                break;
            case 2: 
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                cout << "Wrong choice!";
        }
    }
}

