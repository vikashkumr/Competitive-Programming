#include<bits/stdc++.h>
using namespace std;
int indx=-1;
int stak[15];
int max(){

}
//pop out the last element
void pop(){
    if(index<0)
    cout<<"stack underflow\n";
    else
    indx--;
}

//push the element to the last
void push(int x){
    if(index==14)
    cout<<"stack overflow\n";
    else
    stak[++indx]=x;

}

//show the last element
int peek(){
    return stak[indx];
}
int main(){
    int choice;
    cout<<"choose a option:\n";
    while(1){
    cout<<"1.push\t2.pop\t3.peek\n";
    cin>>choice;
    switch(choice){
        int x;
        case 1: {
            cout<<"enter element to be pushed:\n";
            cin>>x;
            push(x);
        }
        break;
        case 2: pop();
        break;
        case 3: cout<<peek()<<endl;
        break;
        default : {cout<<"wrong input... try again\n";
        exit(0);}
    }
}
    return 0;
}