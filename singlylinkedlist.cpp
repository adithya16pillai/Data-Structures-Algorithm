#include <iostream>
using namespace std;

struct node {
    int value;
    struct node *next;
};

void Insert();
void Delete();
void Display();
int final();

typedef struct node DATA_NODE;

DATA_NODE *head_node, *first_node, *temp_node = 0, *prev_node, next_node;
int data;

int main() {
  int option = 0;

  while (option < 5) {

    cout << "\nOptions:\n";
    cout << "1 - Insert into Linked List \n";
    cout << "2 - Delete from Linked List \n";
    cout << "3 - Display Linked List\n";
    cout << "4 - Count Linked List\n";
    cout << "Enter your choice:";
    cin >> option;

    switch (option) {
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
        final();
        break;
      default:
        break;
    }
  }

  return 0;
}

void Insert() {
  cout << "\nEnter Element to insert: \n";
  cin >> data;
  temp_node = (DATA_NODE *) malloc(sizeof (DATA_NODE));
  temp_node->value = data;
  if (first_node == 0) {
    first_node = temp_node;
  } else {
    head_node->next = temp_node;
  }
  temp_node->next = 0;
  head_node = temp_node;
  fflush(stdin);
}

void Delete() {
  int countvalue, pos, i = 0;
  countvalue = final();
  temp_node = first_node;
  cout << "\nDisplay Linked List: \n";

  cout << "\nEnter position to delete element: \n";
  cin >> pos;

  if (pos > 0 && pos <= countvalue) {
    if (pos == 1) {
      temp_node = temp_node -> next;
      first_node = temp_node;
    } else {
      while (temp_node != 0) {
        if (i == (pos - 1)) {
          prev_node->next = temp_node->next;
          if(i == (countvalue - 1))
          {
			  head_node = prev_node;
		  }
          break;
        } else {
          i++;
          prev_node = temp_node;
          temp_node = temp_node -> next;
        }
      }
    }
  } else
    cout << "\nInvalid Position\n";
}

void Display() {
  int count = 0;
  temp_node = first_node;
  cout << "\nDisplay linked list: \n";
  while (temp_node != 0) {
    count++;
    temp_node = temp_node -> next;
  }
}

int final() {
  int count = 0;
  temp_node = first_node;
  while (temp_node != 0) {
    printf("# %d # ", temp_node->value);
    count++;
    temp_node = temp_node -> next;
  }
  cout << "\nNo Of Items In Linked List : \n" << count;
  return count;
}
