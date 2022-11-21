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

void kruskal(const string);
int main()
{
    kruskal("kruskal_ex_input.dat");
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

void kruskal(const string f_name)
{
    for (int i=0; i<ARRAY_SIZE; i++) { fathers[i] = i; }
    int node_cnt, edge_cnt;
    int start, end, weight;
    vector< PAIRS > edges; // First int is weight, second and third int is start & end point

    ifstream reader;
    reader.open(f_name);

    reader >> node_cnt >> edge_cnt;
    for (int i=0; i<edge_cnt; i++)
    {
        reader >> start >> end >> weight;
        edges.push_back(make_pair(weight, make_pair(start, end)));
    }
    reader.close();

    /* Kruskal's Algorithm */
    int mst_edge_num = 0, mst_weight = 0, mst_next_idx = 0;
    sort(edges.begin(), edges.end());

    while (mst_edge_num < node_cnt - 1 && mst_next_idx < edge_cnt)
    {
        start = edges[mst_next_idx].second.first;
        end = edges[mst_next_idx].second.second;
        weight = edges[mst_next_idx].first;

        if (find(start) != find(end))
        {
            unite(start, end);
            mst_weight += weight;
            cout << start << " " << end << " " << weight << endl;
            mst_edge_num++;
        }

        mst_next_idx++;
    }
    if (mst_edge_num < node_cnt - 1) cout << "No Spanning Tree\n";
    else cout << "MST Weight: " << mst_weight << endl;
}