#include <iostream>
using namespace std;

#define MAX_SIZE 100 // maximum size of the stack

class Stack {
    private:
        int top; // Top index 
        int arr[MAX_SIZE]; // Array 

    public:
        Stack() 
        { 
            top = -1;
        }

        void Push(int data) {
            if (isFull())       // checking whether the stack is full
            { 
                cout << "Stack Overflow " << endl;
            } else 
            {
                top++;
                arr[top] = data;          //pushing the value into stack
            }
        }

        void Pop() {
            if (isEmpty())    //checking whether the stack is empty
            {
                cout << "Stack Underflow " << endl;
            } else {
                int data = arr[top];    //poping the value from the stack
                top--;
            }
        }

        bool isEmpty()   
        {
            return top == -1;
        }

        bool isFull() 
        {
            return top == MAX_SIZE - 1;
        }

        int stackTop() 
        {
            if (isEmpty()) {
                return -1;
            } else {
                return arr[top];   //returning the top value of the stack
            }
        }

        void Display() {
            if (isEmpty()) {
                cout << "Stack is empty " << endl;
            } else {
                cout << "Stack : ";
                for (int i = 0; i <= top; i++) {
                    cout << arr[i] << " ";    //displaying the stack
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
    
    clock_t end_time = clock();  //execution time counting ended
    double duration = double (end_time - begin_time)/ CLOCKS_PER_SEC;   //calculating execution time taken
    cout << " time taken for execution " << duration << " seconds " << endl;

    return 0;
}
