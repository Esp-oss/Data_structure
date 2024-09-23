#include <iostream>  

#define CAPACITY 1000// 定义容量  
#define ERROR = -0x3f3f3f3f

class Stack {
private:
    int memory[CAPACITY]; // 用于储存元素  
    int rear = 0; // 指向栈顶，C++11及以后允许在类定义中直接初始化  

public:
    //判断是否为空
    bool is_empty() {
        if (rear == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    //返回当前栈的大小
    int size() {
        return rear;
    }

    //访问栈顶元素
    int top() {
        if (rear > 0) {
            return memory[rear - 1];
        }
        else {
            return ERROR;
        }
    }

    //删除栈顶元素
    void pop() {
        if (rear > 0) {
            rear--;
        }
    }

    //重置栈
    void reset() {
        rear = 0;
    }

    //将元素压入栈
    bool push(int in_put) {
        if (rear < CAPACITY) {//判断是否栈满
            memory[rear++] = in_put;
            return true;
        }
        else {
            return false;
        }
    }





};