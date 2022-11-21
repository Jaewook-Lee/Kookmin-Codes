#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *link;
    public:
        Node() {};
        Node (int n) : link(0) { data = n; }
};

class Graph
{
    private:
        Node **array; // An array of Node pointers
    public:
        int size;
        Graph() {}
        Graph(int n)
        {
            size = n;
            array = new Node*[n];
            for (int i=0; i<size; i++) { *(array + i) = 0; } // Initialize all of elements to null
        }
        ~Graph() { delete[] array; }
        void addEdge(int start, int end)
        {
            Node *start_vertex = new Node(start);
            Node *end_vertex = new Node(end);
            start_vertex->link = end_vertex;

            if (array[start] == 0) array[start] = start_vertex; // If array's element is null, update new data.
            else // Linking end_vertex right after existing end_vertex in array.
            {
                Node *temp = array[start];
                while (temp->link != 0) temp = temp->link;
                temp->link = end_vertex;
            }
        }
        void printGraph()
        {
            for (int i=0; i<size; i++)
            {
                cout << "Vertex " << i << ": ";
                Node *printed = array[i]->link;
                while (printed != 0)
                {
                    cout << printed->data;
                    if (printed->link!= 0) cout << "->";

                    printed = printed->link;
                }
                cout << endl;
            }
        }
        void bfs(bool *visited, int start_vertex=0) 
        {
            queue<Node*> bfs_search_queue;
            bfs_search_queue.push(array[start_vertex]);
            visited[start_vertex] = true;

            while (!bfs_search_queue.empty())
            {
                Node* print = bfs_search_queue.front();
                bfs_search_queue.pop();
                cout << "Vertex " << print->data << ", ";
                while (print->link != 0)
                {
                    if (!visited[print->link->data])
                    {
                        bfs_search_queue.push(array[print->link->data]);
                        visited[print->link->data] = true;
                    }
                    print = print->link;
                }
            }
            cout << endl;
        }
};

void makeGraph(string, Graph&);
int main()
{
    Graph g;
    makeGraph("lab9-2.dat", g); // Data is looks like a two-dimensional array.

    g.printGraph();

    bool visited[g.size] = {false};
    g.bfs(visited);
    return 0;
}

void makeGraph(const string file_name, Graph &graph)
{
    ifstream reader;
    reader.open(file_name);
    int size, data;
    reader >> size;
    graph = Graph(size);

    for (int start_vertex=0; start_vertex<size; start_vertex++)
    {
        for (int end_vertex = 0; end_vertex<size; end_vertex++)
        {
            reader >> data;
            if (data == 1) graph.addEdge(start_vertex, end_vertex);
        }
    }
    reader.close();
}