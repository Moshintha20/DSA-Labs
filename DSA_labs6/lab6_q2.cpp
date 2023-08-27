#include <iostream>
#include <ctime>
using namespace std;

class Node {
    public:
        int data; // Data of the node
        Node* next; // Pointer to the next node

        Node(int data) 
        { 
            this->data = data;
            next = NULL;
        }
};

class Stack {
    private:
        Node* top; // Top node 

    public:
        Stack() 
        {
            top = NULL;
        }

        void Push(int data) {
            Node* newNode = new Node(data); // Create a new node with the given data

            if (top == NULL)  // If stack is empty, make the new node as top
            { 
                top = newNode;
            } else 
            { 
                newNode->next = top; // add the new node at the top and make it the new top
                top = newNode;
            }
        }

        void Pop() 
        {  
            if (isEmpty())  ////checking whether the stack is empty
            {
                cout << "Stack Underflow " << endl;
            } else {
                int data = top->data;
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

        bool isEmpty() {
            return top == NULL;
        }

        int stackTop() {
            if (isEmpty()) {
                return -1;
            } else {
                return top->data;   //returning the top value of the stack
            }
        }

        void Display() {
            if (isEmpty()) {
                cout << "Stack is empty " << endl;
            } else {
                cout << "Stack : ";
                Node* temp = top;
                while (temp != NULL) {
                    cout << temp->data << " ";  //displaying the stack
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main() {
    Stack S;
    
    clock_t begin_time = clock();   //exectution time starts to count
    
    S.Push(8);
    S.Push(10);
    S.Push(5);
    S.Push(11);
    S.Push(15);
    S.Push(23);
    S.Push(6);
    S.Push(18);
    S.Push(20);
    S.Push(17);
    S.Display();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Display();
    S.Push(4);
    S.Push(30);
    S.Push(3);
    S.Push(1);
    S.Display();
    
    clock_t end_time = clock();   //execution time counting ended
    double duration = double (end_time - begin_time)/ CLOCKS_PER_SEC;  //calculating execution time taken
    cout << " time taken for execution " << duration << " seconds " << endl;


    return 0;
}
