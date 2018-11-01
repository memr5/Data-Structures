#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    stack<int> s1;
    stack<int> s2;

    int x,y;

    do{
        cout<<"\n\t\t<<<Queue Using Two-Stacks>>>\n";
        cout<<"\n\t\tEnter (1 Value) To Enqueue Value in Queue";
        cout<<"\n\t\tEnter (2) To Dequeue";
        cout<<"\n\t\tEnter (3) To Display Front Element";
        cout<<"\n\t\tEnter (4) To Exit";
        cout<<"\n\t\tEnter here: ";

        cin>>x;
        if(x==1){
            cin>>y;
            s1.push(y);
            cout<<"\n\t\tElement Enqueued\n";
        }
        else if(x==2){
            if(s2.empty() && s1.empty()){
                cout<<"\n\t\tQueue is Empty\n";
                continue;
            }
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int popped = s2.top();
            s2.pop();
            cout<<"\n\t\tElement Dequeued : "<<popped<<endl;
        }
        else if(x==3){
            if(s2.empty() && s1.empty()){
                cout<<"\n\t\tQueue is Empty\n";
                continue;
            }
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout<<"\n\t\tElement at Front :"<<s2.top()<<endl;
        }
    }while(x!=4);
return 0;
}

