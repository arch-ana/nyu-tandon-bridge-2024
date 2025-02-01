#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Queue{
    private:
        vector <T> queueVector;
        int front = 0;
        int back = -1;
    
    public:

        //constructor
        Queue(): front(0), back(-1) {}

        //getters
        int get_front(){
            return front;
        }

        int get_back(){
            return back;
        }

        //add element to queue
        void enqueue(const T& theElement){
            queueVector.push_back(theElement);
            back++;
        }

        //remove element from queue
        void dequeue(){
            if (front > back){
                cout<<"No elements left to dequeue";
                return;
            }
            else{
                front++;
                if (front > back){
                    queueVector.clear();
                    front = 0;
                    back = -1;
                }
            }
        }
        
        //check the front element - using a bool + pass by reference to check 
        //for front element only if queue is not empty
        bool peek(T& theTopElement){
            if (isEmpty()){
                return false;
            }
            theTopElement = queueVector[front];  
            return true; 
        }

        //check if the queue is empty
        bool isEmpty(){
            return (front > back);
        }

        //check the logical size of the queue
        int size(){
            return (back - front + 1);
        }

        //clears the queue
        void clear(){
            queueVector.clear();
            front = 0;
            back = -1;
        }
};

int main() {
    Queue<int> q;
    int frontElement;

    cout << "Enqueuing 1, 2, 3, 4, 5" << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    if (q.peek(frontElement)){
        cout<<"Front element: "<<frontElement<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }

    cout << "Queue size: " << q.size() << endl;

    cout << "Dequeuing 2 elements..." << endl;
    q.dequeue();
    q.dequeue();

    if (q.peek(frontElement)){
        cout<<"Front element after dequeueing: "<<frontElement<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }

    cout << "Queue size after dequeuing: " << q.size() << endl;

    cout << "Dequeuing remaining elements..." << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Trying to peek on empty queue..." << endl;
    if (q.peek(frontElement)){
        cout<<"Front element: "<<frontElement<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }

    cout << "Enqueuing 10 and 20" << endl;
    q.enqueue(10);
    q.enqueue(20);

    if (q.peek(frontElement)){
        cout<<"Front element: "<<frontElement<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
    cout << "Queue size: " << q.size() << endl;

    return 0;
}