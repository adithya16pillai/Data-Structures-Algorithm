#include <iostream>
using namespace std;

int q[100], n = 100, front = - 1, rear = - 1;

void Add() {
   int x;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1) {
      front = 0;
      cout<<"Insert the element in the queue: "<<endl;
      cin>>x;
      rear++;
      q[rear] = x;
      }
   }
}
void Delete() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow!";
      return ;
   } else {
      cout<<"Element deleted from the queue is: "<< q[front] <<endl;
      front++;;
   }
}
void Display() {
   if (front == - 1) {
   cout<<"Queue is empty!"<<endl;
   } else {
      cout<<"Queue elements are: ";
      for (int i = front; i <= rear; i++) {
      cout<<q[i]<<" ";
      cout<<endl;
      }
   }
}
int main() {
   int y;
   cout<<"1 - Insert element to queue"<<endl;
   cout<<"2 - Delete element from queue"<<endl;
   cout<<"3 - Display all the elements of queue"<<endl;
   cout<<"4 - Exit!"<<endl;
   do {
      cout<<"Enter your choice: "<<endl;
      cin>>y;
      switch (y) {
         case 1: Add();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit!"<<endl;
         break;
         default: cout<<"Invalid choice!"<<endl;
      }
   } while(y!=4);
   return 0;
}
