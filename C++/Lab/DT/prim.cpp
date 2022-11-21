#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define PAIRS pair<int, pair<int, int>>
using namespace std;

const int ARRAY_SIZE = 100;

// Disjoint Sets structure
int fathers[ARRAY_SIZE];
int find(int);
void unite(int, int);
int minCost(int*, int, int&);
int sum(int*, int);
void prim(const string, int=0);
int main()
{
    prim("prim_ex_input.dat");
    return 0;
}

int find(int x) // Find ancestor of x
{
    if (fathers[x] == x) return x;
    else return find(fathers[x]);
}

void unite(int x, int y) // Group two subtrees to a subtree
{
    int father_x = find(x);
    int father_y = find(y);
    fathers[father_x] = father_y;
}

int minCost(int* array, int size, int& end_point)
{
    int min_cost = 214897;
    if (sum(array, size) == 0) return 0;

    for (int i=0; i<size; i++)
    {
        if (*(array + i) < min_cost && *(array + i) != 0)
        {
            min_cost = *(array + i);
            end_point = i;
        }
    }

    return min_cost;
}

int sum(int* array, int size)
{
    int sum = 0;
    for (int i=0; i<size; i++) { sum += *(array + i); }
    return sum;
}

void prim(const string f_name, int start_idx)
{
    ifstream reader;
    reader.open(f_name);
    int node_cnt, edge_cnt;
    reader >> node_cnt >> edge_cnt;

    int costs[node_cnt][node_cnt] = {0};
    for (int i=0; i<node_cnt; i++)
    {
        for (int j=0; j<node_cnt; j++)
        {
            int cost_data;
            reader >> cost_data;
            costs[i][j] = cost_data;
        }
    }
    reader.close();

    /*Prim's Algorithm*/
    int mst_edge_num = 0, mst_weight = 0;
    int start = start_idx, end, weight;
    for (int i=0; i<ARRAY_SIZE; i++) { fathers[i] = i; }

    while(mst_edge_num < node_cnt - 1)
    {
        weight = minCost(costs[start], node_cnt, end);
        if (weight == 0) break;

        if (find(start) != find(end))
        {
            unite(start, end);
            mst_weight += weight;
            cout << start << " " << end << " " << weight << endl;
            mst_edge_num++;
        }
        costs[start][end] = 0; costs[end][start] = 0;
        start = end;
    }

    if (mst_edge_num < node_cnt - 1) cout << "No Spanning Tree\n";
    else cout << "MST Weight: " << mst_weight << endl;
}