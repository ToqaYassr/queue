#include <iostream>

using namespace std;

template<class t>
/*
o enqueue (elementType element) : void
o dequeue () : elementType element //return the first element and remove it.
o first () : elementType element //return the first element without removing it.
o isEmpty () : bool
o queueSize () : int
o clear (): void
o print () : void*/
class queue {
private:
    struct Node {
        t element;
        Node *next;
    };
    Node *first;
    Node *last;
    int length;
public:
    queue() {
        first = NULL;
        last = NULL;
        length = 0;
    }

    //add element to the queue
    void enqueue(t item) {
        Node *newnode = new Node;
        newnode->element = item;
        newnode->next = NULL;

        if (length == 0) {
            first = last = newnode;

        } else {
            last->next = newnode;
            last = newnode;
        }
        length++;
    }

    //return the first element and remove it
    t dequeue() {
        if (length == 0) {
            cout << "the queue is empty ... ";
        } else {

            if (length == 1) {
                t tmp = first->element;
                delete first;
                first = last = NULL;
                length--;
                return tmp;

            } else {
                t tmp = first->element;
                Node *temp = first;
                first = first->next;
                delete temp;
                length--;
                return tmp;


            }


        }
    }

    t First() {    //return the first element without removing it
        if (length == 0) {
            cout << "the queue is empty ... ";
        } else {
            return first->element;
        }
    }

    //check if the queue is Empty
    bool isEmpty() {
        return length == 0;
    }

    //print the length of the queue
    int queueSize() {
        return length;
    }

    //clear the queue
    void clear() {
        Node *temp;
        while (first != NULL) {
            temp = first;
            first = first->next;
            delete temp;

        }
        last = NULL;
        length = 0;
    }

    void print() {
        if (length == 0) {
            cout << "the queue is empty ... ";
        } else {
            Node *temp = first;
            cout << "[";
            while (temp != NULL) {
                cout << temp->element << " ";
                temp = temp->next;
            }
            cout << "]" << endl;

        }
    }
};





