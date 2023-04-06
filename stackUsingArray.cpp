#include <iostream>

using namespace std;
int top,n,flag,x;
int stack[200];
void push(int ele){
    if(top>=n-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        stack[top]=ele;
    }
}
void pop(){
    if(top<=-1)
        cout<<"Stack Underflow"<<endl;
    else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
    }
}
void display(){
    if(top>=0){
        for(int i=top;i>=0;i--){
            cout<<stack[i]<<" ";
        }
    cout<<endl;
    }
    else{
        cout<<"STACK IS EMPTY."<<endl;
    }
}
int main(){
    top =-1;
    int choice;
    flag = 1;
    n = 200;
    while(flag){
        cout<<"1.Push()\n2.Pop()\n3.Display()\n4.Exit()\n";
        cin>>choice;
        switch(choice){
            case 1:
                int ele;
                cin>>ele;
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                flag = 0;
                break;
            default:
                cout<<"Wrong choice"<<endl;
                break;
        }
    }
    return 0;
}

