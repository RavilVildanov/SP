//
//  main.cpp
//  Lab_3
//
//  Created by Равиль Вильданов on 13/05/2019.
//  Copyright © 2019 Premium Parking. All rights reserved.
//

#include <iostream>

using namespace std;

class Stack {

    int size;
    int* data;
    size_t ptr;
    
public:
    
    Stack(int valid_stack_size) {
        this->size = valid_stack_size;
        this->ptr = 0;
        this->data = new int[valid_stack_size];
    }
    
    ~Stack() {
        delete[] this->data;
    }
    
    void push(int value) {
        if (this->ptr >= (size_t)this->size)
            throw "stack is full\n";
        this->data[this->ptr++] = value;
        
    }
    
    int pop() {
        if (this->ptr == 0)
            throw "stack is empty";
        
        return this->data[--this->ptr];
        
    }
};

int main(int argc, const char * argv[]) {
    Stack* stack1 = new Stack(5);
    Stack* stack2 = new Stack(5);
    Stack* stack3 = new Stack(10);
    int n;
    
    cout << "\nВведите первую не убывающую последовательность: \n";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        stack1->push(n);
    }
    
    cout << "\nВведите вторую не убывающую последовательность: \n";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        stack2->push(n);
    }
    
    for (int i = 0; i < 5; i++) {
        int n1 = stack1->pop();
        int n2 = stack2->pop();
        if (n1 < n2) {
            stack3->push(n2);
            stack3->push(n1);
        } else {
            stack3->push(n1);
            stack3->push(n2);
        }
    }
    
    cout << "\nОбщая последовательность: \n";
    for (int i = 0; i < 10; i++)
        cout << stack3->pop() << endl;
    
    return 0;
}
