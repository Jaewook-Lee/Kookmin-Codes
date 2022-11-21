class MyHeap
{
    // Max Heap

    private:
        static const int HEAP_SIZE = 11;
        int heap[HEAP_SIZE] = {0};
        int item_cnt;
    public:
        MyHeap();
        bool Empty();
        void Insert(const int);
        int Delete();
        int Length();
        void Print();
};