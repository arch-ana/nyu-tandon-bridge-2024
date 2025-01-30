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
        
        //check the top element
        T top(){
            if (front>back){
                throw runtime_error("Queue is empty");
            }
            else{
                return queueVector[front];
            }
        }

        //check if the queue is empty
        bool isEmpty(){
            if (front > back){
                return true;
            }
            return false;
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

// int main() {
//     Queue<int> q;

//     cout << "Enqueuing 1, 2, 3, 4, 5..." << endl;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(4);
//     q.enqueue(5);

//     cout << "Front element: " << q.top() << endl;
//     cout << "Queue size: " << q.size() << endl;

//     cout << "Dequeuing 2 elements..." << endl;
//     q.dequeue();
//     q.dequeue();

//     cout << "Front element after dequeuing: " << q.top() << endl;
//     cout << "Queue size after dequeuing: " << q.size() << endl;

//     cout << "Dequeuing remaining elements..." << endl;
//     q.dequeue();
//     q.dequeue();
//     q.dequeue();

//     cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

//     cout << "Trying to peek on empty queue..." << endl;
//     try {
//         q.top();
//     } catch (const runtime_error& e) {
//         cout << "Exception caught: " << e.what() << endl;
//     }

//     cout << "Enqueuing after clearing queue..." << endl;
//     q.enqueue(10);
//     q.enqueue(20);

//     cout << "Front element: " << q.top() << endl;
//     cout << "Queue size: " << q.size() << endl;

//     return 0;
// }