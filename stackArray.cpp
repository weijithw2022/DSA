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
    // while(flag){
    //     cout<<"1.Push()\n2.Pop()\n3.Display()\n4.Exit()\n";
    //     cin>>choice;
    //     switch(choice){
    //         case 1:
    //             int ele;
    //             cin>>ele;
    //             push(ele);
    //             break;
    //         case 2:
    //             pop();
    //             break;
    //         case 3:
    //             display();
    //             break;
    //         case 4:
    //             flag = 0;
    //             break;
    //         default:
    //             cout<<"Wrong choice"<<endl;
    //             break;
    //     }
    struct timespec begin, end;
    clock_gettime(CLOCK_REALTIME, &begin);

    clock_gettime(CLOCK_REALTIME, &end);
    
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();
    clock_gettime(CLOCK_REALTIME, &end);
    


    float secs = end.tv_sec - begin.tv_sec;
    float nanosecs = end.tv_nsec - begin.tv_nsec;

    double elapsed = secs*1e9 + nanosecs;
    cout << "time taken is " << elapsed << "ns" << endl;
    return 0;
    return 0;
}

