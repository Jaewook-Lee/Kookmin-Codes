class MyQueue
{
    private:
        const static int QUEUE_SIZE = 50;
        int front;
        int rear;
        int item_cnt;
        int my_queue[QUEUE_SIZE];

    public:
        int max_size;

        MyQueue();
        MyQueue(int[], int);
        void enqueue(int);
        int dequeue();
        bool empty();
        bool full();
        int length();
        void print_queue();

        int operator[](const int);    // Overloading
};