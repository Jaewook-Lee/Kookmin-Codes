const int STACK_SIZE = 10;
class MyStack {
    private:
        int top;

    public:
        int my_stack[STACK_SIZE];
        int max_size;

        MyStack();
        void push(int);
        int pop();
        int length();
        bool empty();
        void print_stack();

        int operator[](int); // Overloading
};