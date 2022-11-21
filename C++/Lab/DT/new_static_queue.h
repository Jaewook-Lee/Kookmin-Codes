#include <iostream>
using namespace std;

const int QUEUE_SIZE = 3;
class StaticQueue
{
    private:
        char char_queue[QUEUE_SIZE];
        int front, rear;

    public:
        StaticQueue()
        {
            front = -1;
            rear = -1;
        }

        void enqueue(char value)
        {
            if (rear == QUEUE_SIZE - 1)
            {
                cout << "QueueFull." << endl;
            }
            else
            {
                char_queue[++rear] = value;
            }
        }
        char dequeue()
        {
            char item;
            if (front == rear)
            {
                cout << "QueueEmpty." << endl;
            }
            else
            {
                item = char_queue[++front];
                return item;
            }
        }
        int queue_full()
        {
            if (rear == QUEUE_SIZE - 1)
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
        void displayQueue()
        {
            int i;
            if (front == rear)
            {
                cout << " QueueEmpty." << endl;
            }
            else
            {
                i = front + 1;
                while (i <= rear)
                {
                    if (i == rear)
                    {
                        cout << char_queue[i] << endl;
                    }
                    else
                    {
                        cout << char_queue[i] << ", ";
                    }
                    i += 1;
                }
            }
        }
};