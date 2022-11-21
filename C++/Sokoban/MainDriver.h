#include "Array.h"
using namespace std;

class MainLogic
{
    public:
        int level = 1;
        int Count = 0;
        int step = 0;
        int** current_map = ReturnLevel(level);
        bool clear(int, int**);
        void push(int, int**);
};