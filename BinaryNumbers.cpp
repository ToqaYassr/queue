#include "queue.cpp"


// binary numbers from 1 to n using queue
void BinaryNumbers(int n){
// create three queues used to store the binary numbers
// and reverse them
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
//    loop over the numbers from 1 to n
    for (int i=1;i<=n;i++){
//      convert the number to binary and
//      push it to the queue to print
//      it later not reversed
        int num = i;
//       convert the number to binary,
//       and push it to the first queue(in reverse order)
        while(num>0){
            q1.enqueue(num%2);
            num/=2;
        }
        while(q1.queueSize()>0){
//  store the queue in the second queue
//  (except the last element)
            while(q1.queueSize()>1){
                q2.enqueue(q1.dequeue());

            }
//  push that last element to the third queue
            q3.enqueue(q1.dequeue());
// swap the first and second queue to loop over it
// again in the first loop to extract the last element again
            swap(q1,q2);
        }
//  print the queue in the right order
        q3.print();
        q3.clear();
    }
}