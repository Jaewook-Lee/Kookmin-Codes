#include <iostream>
using namespace std;

const int C_QUEUE_SIZE = 3;
class StaticCircularQueue
{
    private:
        char char_queue[C_QUEUE_SIZE];
        int front, rear;
        int count = 0; // For checking existing

    public:
        StaticCircularQueue()
        {
            front = -1;
            rear = -1;
        }

        void c_enqueue(char value) // For using Queue as Circular.
        {
            rear = (rear + 1) % C_QUEUE_SIZE;
            if (front == rear)
            {
                cout << "QueueFull." << endl;
            }
            else
            {
                char_queue[rear] = value;
                count++;
            }
        }
        char c_dequeue() // For using Queue as Circular.
        {
            char item;
            if (count == 0)
            {
                cout << "QueueEmpty." << endl;
            }
            else
            {
                front = (front + 1) % C_QUEUE_SIZE;
                item = char_queue[front];
                count--;
                return item;
            }
        }
        int queue_full()
        {
            if (rear == C_QUEUE_SIZE - 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int queue_empty()
        {
            if (front == rear)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        void displayCircularQueue()
        {
            int i;
            if (front == rear && count == 0)
            {
                cout << "QueueEmpty." << endl;
            }
            else
            {
                i = front + 1;
                while (i != rear)
                {
                    cout << char_queue[i] << ", ";
                    i = (i + 1) % C_QUEUE_SIZE;
                }
                cout << endl;
            }
        }
};