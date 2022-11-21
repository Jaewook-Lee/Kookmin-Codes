/************************************************************************************************************************************************************
* 이름 : 이재욱
* 학번 : 20181670
* 숙제 번호 : HW #6
* 설명 :
*     이 프로그램은 과제를 수행하기 위해 작성됐습니다.
*     이 프로그램의 목적은 주어진 그래프 별로 최단 거리를 출력하는 것입니다.
* 함수 :
* shortestPath: 단일 출발점, 모든 도착지를 확인하는 방법을 사용하고, 강의 교안에 적혀 있는 Dijkstra's Algorithm을 바탕으로 최단 거리를 계산, 출력합니다.
* minCost: 현재 있는 곳을 기준으로 이동 비용이 제일 적게 걸리는 다음 노드를 찾아 노드 번호를 반환합니다.
* main():
    입력받는 데이터(Adjacency Cost Matrix)를 바탕으로 이차원 배열을 생성, 출력합니다.
    그리고 그래프 별로 최단 거리를 구하는 함수를 실행합니다.
* 알고리즘:
    최단 거리를 구하는 알고리즘은 아래와 같습니다. (지역 번호는 0 ~ (그래프 행의 갯수)-1 로 설정했습니다.)
    1. bool 타입의 배열, visited를 동적으로 할당하고 모두 방문한 적이 없다는 의미로 false로 초기화합니다.
    2. int 타입의 배열, distance를 동적으로 할당하고 시작 정점에서 다른 지역들까지의 비용들을 담습니다.
    3. visited의 시작 정점 인덱스 값을 true로 바꾸고, distance의 시작 정점 인덱스 값을 0으로 변경합니다.
    4. visited의 원소 값들이 모두 true일 때 까지 아래의 반복문을 실행합니다.
    4-1. 최소 비용으로 갈 수 있는 장소의 번호를 int 타입의 min_cost_number 변수로 선언하고, 함수(minCost) 연산을 통해 얻습니다.
    4-1-1. min_cost_number가 -1이면 반복문을 종료합니다.
    4-2. visited의 min_cost_number 인덱스 값을 true로 바꿉니다.
    4-3. distance(또는 visited)의 길이 만큼 아래의 반복문을 실행합니다.
    4-3-1. visited의 i번째 인덱스가 true면 넘어갑니다.
    4-3-2. visited의 i번째 인덱스가 false고, distance[min_cost_vertex] + costs[min_cost_vertex][i]가 distance[i] 보다 작으면,
           distance[i]의 값을 distance[min_cost_vertex] + costs[min_cost_vertex][i]fh 바꿉니다.
    5. visited와 distance를 delete 합니다.

    최소 비용을 구하는 알고리즘은 아래와 같습니다.
    1. 최소 비용을 비용을 담는 변수, int 타입의 min_cost를 최댓값으로 초기화합니다.
    2. 최소 비용으로 갈 수 있는 지역의 번호, int 타입의 min_cost_node를 -1로 초기화합니다.
    3. distance의 길이 만큼 아래의 반복문을 실행합니다.
    3-1. visited[i] 값이 true이면 넘어갑니다.
    3-2. visited[i] 값이 false이면서, distance[i]가 min_cost보다 작으면 min_cost값을 distance[i] 값으로 바꿉니다.
    3-3. i를 min_cost_node 값으로 바꿉니다.
* **********************************************************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void shortestPath(int, int**, int);
int minCost(int*, int, bool*);

/*************************************************************************************************************************
 * 함수 : main
 * 설명 : 두 그래프를 생성하고, 각 그래프의 최단 거리를 출력합니다.
 * 변수들:
 *     reader1, reader_2 : 파일에 써있는 값을 읽기 위한 reader기 입니다. reader_1은 'test_graph_1.dat',
 *                         reader_2는 'test_graph_2.dat'의 내용을 읽습니다.
 *     row_size, row_size_2 : 그래프의 크기를 지정할 int형 변수입니다. row_size는, 'test_graph_1.dat' 속 그래프의 행의 갯수,
 *                            row_size_2는 'test_graph_2.dat' 속 그래프의 행의 갯수입니다.
 *     graph_1, graph_2: Adjacency Cost Matrix 값들을 담는 두 그래프입니다. 동적 할당을 위해 int** 타입으로 지정합니다.
 *                       graph_1은 'test_graph_1.dat', graph_2는 'test_graph_2.dat'을 바탕으로 만들어집니다.
 * **********************************************************************************************************************/
int main()
{
    /* Graph 1 */
    ifstream reader1;
    reader1.open("test_graph_1.dat", fstream::binary);
    
    // 그래프 동적 할당
    int row_size;
    reader1 >> row_size;
    int **graph_1 = new int*[row_size];
    for (int i=0; i<row_size; i++) { graph_1[i] = new int[row_size]; }

    std::cout << "First Graph" << endl;
    for (int i=0; i<row_size; i++)
    {
        for (int j=0; j<row_size; j++)
        {
            reader1 >> graph_1[i][j];
            std::cout << graph_1[i][j] << " ";
        }
        std::cout << endl;
    }
    std::cout << "\n";

    reader1.close();
    shortestPath(row_size, graph_1, 0);
    std::cout << "\n"; // 첫 번째 그래프와 두 번째 그래프 구분을 위한 개행

    delete graph_1;

    /* Graph 2 */
    ifstream reader2;
    reader2.open("test_graph_2.dat", fstream::binary);

    // 그래프 동적 할당
    int row_size_2;
    reader2 >> row_size_2;
    int **graph_2 = new int*[row_size_2];
    for (int i=0; i<row_size_2; i++) graph_2[i] = new int[row_size_2];
    std::cout << "Second Graph" << endl;
    for (int i=0; i<row_size_2; i++)
    {
        for (int j=0; j<row_size_2; j++)
        {
            reader2 >> graph_2[i][j];
            std::cout << graph_2[i][j] << " ";
        }
        std::cout << endl;
    }
    std::cout << "\n";

    reader2.close();
    
    shortestPath(row_size_2, graph_2, 4);

    delete graph_2;

    return 0;
}

/*************************************************************************************************************************
 * 함수 : shortestPath
 * 설명 : 그래프의 최단 거리를 계산하고, 출력합니다. 반환 값이 없습니다.
 * 변수들:
 *     size: visited와 distance를 생성하기 위해 사용되는 int 타입의 parameter입니다.
 *     costs: main에서 만들어진 그래프를 받아오는 int** 타입의 parameter입니다.
 *     start_vertex: 최단 거리 계산의 시작점인 int 타입의 parameter입니다.
 *     visited: 방문 기록을 담기 위한 배열입니다. 동적 할당을 위해 bool* 타입으로 선언합니다.
 *     distance: 시작 정점에서 부터 다른 지역들까지의 비용을 담은 배열입니다. 동적 할당을 위해 int* 타입으로 선언합니다.
 *     min_cost_vertex: 최소 비용으로 갈 수 있는 다음 지역의 번호를 담는 int형 변수입니다.
 * **********************************************************************************************************************/
void shortestPath(int size, int** costs, int start_vertex)
{
    bool *visited = new bool[size];
    for (int i=0; i<size; i++) *(visited + i) = false;
    int *distance = new int[size];
    for (int i=0; i<size; i++) *(distance + i) = *(*(costs + start_vertex) + i);
    visited[start_vertex] = true;
    distance[start_vertex] = 0;

    int min_cost_vertex = start_vertex;
    for (int i=0; i<size; i++)
    {
        if (i == 0) std::cout << "Beginning (" << start_vertex << ") ";
        else std::cout << "Select: (" << min_cost_vertex << ") ";

        for (int j=0; j<size; j++)  std::cout << *(distance + j) << " ";
        std::cout << endl;

        min_cost_vertex = minCost(distance, size, visited);
        if (min_cost_vertex == -1) break;

        visited[min_cost_vertex] = true;
        for (int k=0; k<size; k++)
        {
            if (!visited[k])
            {
                if (distance[min_cost_vertex] + costs[min_cost_vertex][k] < distance[k])
                    distance[k] = distance[min_cost_vertex] + costs[min_cost_vertex][k];
            }
        }
    }

    delete visited;
    delete distance;
}

/*************************************************************************************************************************
 * 함수 : minCost
 * 설명 : 현재 지역을 기준으로 최소 비용으로 갈 수 있는 다음 지역의 번호를 계산합니다. 그 지역의 번호를 반환합니다.
 * 변수들:
 *      distance: 현재 지역에서부터 다른 모든 지역까지의 비용을 담은 int*형 parameter입니다.
 *      visited: 방문 기록이 담긴 bool*형 parameter입니다.
 *      size: distance의 크기를 알리기 위한 int형 변수입니다.
 *      min_cost: 최소 비용을 담기 위한 int형 변수로 10000으로 초기화합니다.
 *      min_cost_node: 최소 비용으로 갈 수 있는 다음 지역의 번호를 담는 int형 변수로 -1로 초기화합니다.
 * **********************************************************************************************************************/
int minCost(int* distance, int size, bool* visited)
{
    int min_cost = 10000;
    int min_cost_node = -1;
    for (int i=0; i<size; i++)
    {
        if (*(distance + i) < min_cost && !*(visited + i))
        {
            min_cost = distance[i];
            min_cost_node = i;
        }
    }
    return min_cost_node;
}