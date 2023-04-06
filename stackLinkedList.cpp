#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *nxt;
}; 
node* top = NULL;
void push(int ele) {
   node *new_node = new node();
   new_node->data = ele;
   new_node->nxt = top;
   top = new_node;
}

void pop ( ){
    if ( top ==NULL ){
        cout<<"Stack is Empty";
    }
    else{
        node *pointer = top;
        top = top -> nxt;
        delete(pointer);
    }
}
void display(){
    if ( top ==NULL  ){
    cout<<"Stack is Empty";
    }
    else{
        node *ptr=top;
        while(ptr!=NULL){   
            cout<<ptr->data<<" ";
            ptr=ptr->nxt;
        }
        cout<<"\n";
    }
 }

int main(){
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
}

