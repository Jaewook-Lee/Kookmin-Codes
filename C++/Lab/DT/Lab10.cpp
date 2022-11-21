#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define PAIRS pair<int, pair<int, int>>
using namespace std;

const int ARRAY_SIZE = 100;

int fathers[ARRAY_SIZE]; // Using for checking cycle.

int find(int);
void unite(int, int);
int minCost(int*, int, int&, bool*); // Prim's Algorithm (Greedy ver.)
int minCost(int [6][6], int*, int, int&, int&, bool*, vector<PAIRS>&); // Prim's Algorithm (Revise ver.)
int sum(int*, int);
void prim(const string); // with Greedy
void primRevised(const string, int=0); // with Revise
int main()
{
    prim("input.dat");
    primRevised("input.dat", 0);
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

/* Find the minimum cost, using in Prim's Algorithm(Greedy version) */
int minCost(int* array, int size, int& end_point, bool* visited)
{
    int min_cost = 100;
    if (sum(array, size) == 0) return 0;

    for (int i=0; i<size; i++)
    {
        if ((*(array + i) < min_cost && *(array + i) != 0) && !(*(visited + i)))
        {
            min_cost = *(array + i);
            end_point = i;
            *(visited + i) = true;
        }
    }

    return min_cost;
}

/* Find the minimum cost, using in Prim's Algorithm(Revise version) */
int minCost(int cost[6][6], int* array, int size, int& start_point, int& end_point, bool* visited, vector<PAIRS>& unselected)
{
    int origin_start = start_point;
    int min_cost = 100;
    if (sum(array, size) == 0) return 0;

    int selected = -1;
    for (int i=0; i<size; i++)
    {
        if ((*(array + i) < min_cost && *(array + i) != 0) && !(*(visited + i)))
        {
            min_cost = *(array + i);
            end_point = i;
            selected = i;
            *(visited + i) = true;
        }
    }

    int del_idx = -1;
    for (int j=0; j<unselected.size(); j++)
    {
        if (unselected[j].first < min_cost)
        {
            min_cost = unselected[j].first;
            start_point = unselected[j].second.first;
            end_point = unselected[j].second.second;
            del_idx = j;
            selected = -1;
        }
    }
    if (del_idx != -1) { unselected.erase(unselected.begin() + del_idx); }

    for (int k=0; k<size; k++)
    {
        if (k == selected) continue;
        else if (array[k] > 0 && array[k] < 100) 
        { unselected.push_back(make_pair(array[k], make_pair(origin_start, k))); }
    }

    return min_cost;
}

/* Checking if next route is exist or not. */
int sum(int* array, int size)
{
    int sum = 0;
    for (int i=0; i<size; i++) { sum += *(array + i); }
    return sum;
}

/* Main Function of Prim's algorithm (Greedy) */
void prim(const string f_name)
{
    ifstream reader;
    reader.open(f_name);

    int costs[6][6] = {0};
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
        {
            int cost_data;
            reader >> cost_data;
            costs[i][j] = cost_data;
        }
    }
    reader.close();
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
        {
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }

    /*Prim's Algorithm*/
    int mst_edge_num = 0, mst_weight = 0;
    int start = 0, end, weight;
    for (int i=0; i<ARRAY_SIZE; i++) { fathers[i] = i; }
    bool visited[6] = {false};
    visited[0] = true;

    cout << "\nMinimal Spanning Tree (Greedy algorithm)\n";
    while(mst_edge_num < 5)
    {
        weight = minCost(costs[start], 6, end, visited);
        if (weight == 0) break;

        if (find(start) != find(end))
        {
            unite(start, end);
            mst_weight += weight;
            if (mst_edge_num != 0) cout << "-> ";
            cout << "(" << char(start + 65) << ", " << char(end + 65) << ")";
            mst_edge_num++;
        }
        costs[start][end] = 0; costs[end][start] = 0;
        start = end;
    }
    cout << endl;

    if (mst_edge_num < 5) cout << "No Spanning Tree\n";
    else cout << "Weight: " << mst_weight << endl;
}

/* Main Function of Prim's algorithm (Revise) */
void primRevised(const string f_name, int start_idx)
{
    ifstream reader;
    reader.open(f_name);

    int costs[6][6] = {0};
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
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
    bool visited[6] = {false};
    visited[start_idx] = true;
    vector<PAIRS> non_selected_edges;

    cout << "\nRevised Prim's Algorithm\n";
    while(mst_edge_num < 5)
    {
        weight = minCost(costs, costs[start], 6, start, end, visited, non_selected_edges);
        if (weight == 0) break;

        if (find(start) != find(end))
        {
            unite(start, end);
            mst_weight += weight;
            if (mst_edge_num != 0) cout << "-> ";
            cout << "(" << char(start + 65) << ", " << char(end + 65) << ")";
            mst_edge_num++;
        }
        costs[start][end] = 0; costs[end][start] = 0;
        start = end;
    }
    cout << endl;

    if (mst_edge_num < 5) cout << "No Spanning Tree\n";
    else cout << "Weight: " << mst_weight << endl;
}