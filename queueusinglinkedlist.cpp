#include <iostream>
using namespace std;

struct node {
int data;
   struct node *next;
};

struct node* front = NULL;

struct node* rear = NULL;

struct node* n;

void Insert() {
    int x;
    cout<<"Insert the element in queue: "<<endl;
    cin>>x;
    if (rear == NULL) {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = x;
        front = rear;
    } else {
        n=(struct node *)malloc(sizeof(struct node));
        rear->next = n;
        n->data = x;
        n->next = NULL;
        rear = n;
    }
}

void Delete() {
    n = front;
    if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
    } else {
        if (n->next != NULL) {
            n = n->next;
            cout<<"Element deleted from queue is: "<<front->data<<endl;
            free(front);
            front = n;
        } else {
            cout<<"Element deleted from queue is: "<<front->data<<endl;
            free(front);
            front = NULL;
            rear = NULL;
        }
    }
}

void Display() {
    n = front;
    if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
    }
    cout<<"Queue elements are: " << endl;
    while (n != NULL) {
      cout<<n->data<<" ";
      n = n->next;
    }
    cout<<endl;
}

int main() {
   int y;
   cout<<"1 - Insert element to queue"<<endl;
   cout<<"2 - Delete element from queue"<<endl;
   cout<<"3 - Display elements of the queue"<<endl;
   cout<<"4 - Exit"<<endl;
   do {
        cout<<"Enter your choice: "<<endl;
        cin>>y;
        switch (y) {
        case 1:
            Insert();
            break;
        case 2: 
            Delete();
            break;
        case 3: 
            Display();
            break;
        case 4: 
            cout<<"Exit."<<endl;
            break;
        default: 
            cout<<"Invalid choice!"<<endl;
      }
   } while(y!=4);

   return 0;
}