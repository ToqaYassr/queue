# include "queue.cpp"

// sort a queue using another queue
void sortQueue(queue<int> &q){
    queue<int> tmp;

    while(!q.isEmpty()){

        int min_elm = q.First();


//    for finding the minimum element in the queue
        for(int i = 0; i < q.queueSize(); i++){
            int current_elm = q.dequeue();
//        if the current element is less than the minimum element
            if(current_elm < min_elm){
                min_elm = current_elm;
            }
            q.enqueue(current_elm);
        }




//    for deleting the minimum element from the first queue
//   and pushing it to the temp queue
        for(int i = 0; i < q.queueSize(); i++){
            int current_elm = q.dequeue();

//        if the current element is the minimum element
            if(current_elm == min_elm){
                tmp.enqueue(current_elm);
            }

//        if the current element is not the minimum element
            else{
                q.enqueue(current_elm);
            }
        }
    }
    q = tmp;

}

