#include <iostream>
#include <string>
#include <vector>
#include <fstream> // 맵을 txt 형식으로 저장했기에 읽을 녀석이 필요함
using namespace std;

int** ReturnLevel(int a); //맵 리턴
int ReturnChar(int** t, int&); //캐릭터 위치 리턴
vector <vector<int>> Returnthree(int a);//3의 위치 값