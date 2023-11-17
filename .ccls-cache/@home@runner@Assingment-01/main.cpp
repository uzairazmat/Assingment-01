// #bc220402628

#include <iostream>
#include<random>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val);
};

Node::Node(int val) {
    this->val = val;
    this->next = NULL;
}

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert_head(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insert_tail(int val) {
       Node* new_node = new Node(val);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;


    }

    void add(int val, int position) {
        Node* new_node = new Node(val);
        Node* temp = head;

        if (position == 0) {
            insert_head(val);
            return;
        }
        int current = 0;
        while (current != position - 1) {
            temp = temp->next;
            current++;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void del(int position) {
        Node* temp = head;
        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }
        int current = 0;
        Node* prev = NULL;
        while (current != position) {
            prev = temp;
            temp = temp->next;
            current++;
        }

        prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
          
            cout << "List Element "<<temp->val << endl;
          temp = temp->next;
            
        }
    }
  void find_middle(int size) {
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }
    Node* temp = head;
    int count = 0;

    while (count != (size / 2)) {
        
        temp = temp->next;
        count++;
    }
    cout << "The middle element is " << temp->val << endl;
}
};
int generateRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(3, 9);
    return distrib(gen);
}

int main() {
    int size ; 
    size  = generateRandomNumber() ;
    
    cout<<"Randomly generated Random size of Linked List is "<<size<<endl;
    cout<<"Enter Numeric Charecrter of  Vu ID "<<endl;
    LinkedList list;
    int count = 0 ;
    int v ;
    while(count!=size){
          cin>>v;
       if(count == 0 ){

         
         list.insert_head(v);
         count++;
       }
      else{
      list.insert_tail(v);
      count++;}
    }

   list.display();
  list.find_middle( size);

    return 0;
}
