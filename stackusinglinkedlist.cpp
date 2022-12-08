#include <iostream>
using namespace std;

struct Node {
   int x;
   struct Node *next;
};

struct Node* top = NULL;

void push(int z) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->x = z;
   newnode->next = top;
   top = newnode;
}

void pop() {
   if(top==NULL) {
   cout<<"Stack Underflow"<<endl;
   } else {
      cout<<"The popped element is "<< top->x <<endl;
      top = top->next;
   }
}

void display() {
   struct Node* ptr;
   if(top==NULL) {
   cout<<"Stack is empty";
   } else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->x <<" ";
         ptr = ptr->next;
      }
   }
}

int main() {
   int y, z;
   cout<<"1 - Push in stack"<<endl;
   cout<<"2 - Pop from stack"<<endl;
   cout<<"3 - Display stack"<<endl;
   cout<<"4 - Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>y;
      switch(y) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>z;
            push(z);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit."<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice!"<<endl;
         }
      }
   } while(y!=4);
   return 0;
}