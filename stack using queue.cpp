#include"queue.cpp"
using namespace std;
template <class t >
class stack{
private:
    int top;
    queue<int>q1;
public:
    stack() {
        top = -1;
    }

    void stack_push(t n){
        q1.enqueue(n);
        top++;
    }
    void stack_pop(){
        queue<int>q2;
        if(q1.isEmpty())
            return;
        else{
            while(q1.queueSize()>1){
                q2.enqueue(q1.First());
                q1.dequeue();

            }
            top--;
            q1.dequeue();
            swap(q1,q2);
        }

    }
    void print(){
        q1.print();
    }
    int stackSize(){
        return top+1;
    }


};

int main(){
//    test main
 stack<int>s1;
    s1.stack_push(1);
    s1.stack_push(2);
    s1.stack_push(3);
    s1.stack_push(4);
    s1.stack_push(5);
    s1.print();
    s1.stack_pop();
    s1.print();
    cout<<s1.stackSize()<<endl;

}
