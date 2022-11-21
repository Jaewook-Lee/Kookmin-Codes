#include "Array.h"

const int MAP_SIZE = 10; // 맵 사이즈는 정해져 있기에 상수로 선언
int** ReturnLevel(int a) {
	ifstream reader; // 맵 리더기 선언
	int** array = new int*[MAP_SIZE]; // 맵 정보를 저장할 이차원 배열 선언

	if (a == 1) {
		reader.open("Level1.txt");
		int data;
		for (int i = 0; i<MAP_SIZE; i++)
		{
			array[i] = new int[MAP_SIZE];
			for (int j = 0; j<MAP_SIZE; j++)
			{
				reader >> data;
				array[i][j] = data;
			}
		}
	}
	else if (a == 2) {
		reader.open("Level2.txt");
		int data;
		for (int i = 0; i<MAP_SIZE; i++)
		{
			array[i] = new int[MAP_SIZE];
			for (int j = 0; j<MAP_SIZE; j++)
			{
				reader >> data;
				array[i][j] = data;
			}
		}
	}
	else if (a == 3) {
		reader.open("Level3.txt");
		int data;
		for (int i = 0; i<MAP_SIZE; i++)
		{
			array[i] = new int[MAP_SIZE];
			for (int j = 0; j<MAP_SIZE; j++)
			{
				reader >> data;
				array[i][j] = data;
			}
		}
	}
	else if (a == 4) {
		reader.open("Level4.txt");
		int data;
		for (int i = 0; i<MAP_SIZE; i++)
		{
			array[i] = new int[MAP_SIZE];
			for (int j = 0; j<MAP_SIZE; j++)
			{
				reader >> data;
				array[i][j] = data;
			}
		}
	}
	reader.close();
	return array;
}

int ReturnChar(int** t, int& col_idx) {
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			if (t[i][j] == 9) {
				col_idx = j;
				return i;
			}
		}
	}
}
vector <vector<int>> Returnthree(int a) {
	int array[10][10];
	vector <vector<int>> threeidx;
	if (a == 1) {
		int array[10][10] = {
			{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 4, 1, 1, 1, 1, 1, 4, 4 },
		{ 4, 4, 4, 1, 0, 0, 0, 1, 4, 4 },
		{ 4, 4, 4, 1, 3, 3, 3, 1, 4, 4 },
		{ 4, 4, 4, 1, 2, 2, 2, 1, 1, 4 },
		{ 4, 4, 4, 1, 0, 0, 0, 0, 1, 4 },
		{ 4, 4, 4, 1, 0, 9, 0, 0, 1, 4 }, //9는 캐릭터임
		{ 4, 4, 4, 1, 1, 1, 1, 1, 1, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
		};
		for (int i = 0; i<10; i++) {
			for (int j = 0; j<10; j++) {
				if (array[i][j] == 3) {
					vector <int> idx;
					idx.push_back(i); idx.push_back(j);
					threeidx.push_back(idx);
				}
			}
		}
	}
	else if (a == 2) {
		int array[10][10] = {
			{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 1, 1, 1, 1, 1, 1, 1, 1, 4 },
		{ 4, 1, 3, 0, 0, 0, 0, 0, 1, 4 },
		{ 4, 1, 0, 3, 2, 2, 2, 9, 1, 4 }, //9는 캐릭터임
		{ 4, 1, 3, 0, 0, 0, 0, 0, 1, 4 },
		{ 4, 1, 1, 1, 1, 1, 0, 0, 1, 4 },
		{ 4, 4, 4, 4, 4, 1, 1, 1, 1, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		};
		for (int i = 0; i<10; i++) {
			for (int j = 0; j<10; j++) {
				if (array[i][j] == 3) {
					vector <int> idx;
					idx.push_back(i); idx.push_back(j);
					threeidx.push_back(idx);
				}
			}
		}
	}
	else if (a == 3) {
		int array[10][10] = {
			{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
			{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 1, 1, 1, 1, 1, 1, 1, 4 },
		{ 4, 4, 1, 0, 3, 2, 3, 0, 1, 4 },
		{ 4, 4, 1, 0, 2, 3, 2, 0, 1, 4 },
		{ 4, 4, 1, 0, 3, 2, 3, 0, 1, 4 },
		{ 4, 4, 1, 0, 2, 3, 2, 0, 1, 4 },
		{ 4, 4, 1, 0, 0, 9, 0, 0, 1, 4 }, //9는 캐릭터임
		{ 4, 4, 1, 1, 1, 1, 1, 1, 1, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
		};
		for (int i = 0; i<10; i++) {
			for (int j = 0; j<10; j++) {
				if (array[i][j] == 3) {
					vector <int> idx;
					idx.push_back(i); idx.push_back(j);
					threeidx.push_back(idx);
				}
			}
		}
	}
	else {
		int array[10][10] = {
			{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 1, 1, 1, 1, 4, 4, 4, 4, 4 },
		{ 4, 1, 0, 0, 1, 1, 1, 1, 4, 4 },
		{ 4, 1, 0, 0, 0, 0, 0, 1, 1, 4 },
		{ 1, 1, 0, 1, 1, 0, 0, 0, 1, 4 },
		{ 1, 3, 0, 3, 1, 0, 9, 2, 1, 1 }, //9는 캐릭터임
		{ 1, 0, 0, 0, 1, 0, 2, 2, 0, 1 },
		{ 1, 0, 0, 3, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
		};
		for (int i = 0; i<10; i++) {
			for (int j = 0; j<10; j++) {
				if (array[i][j] == 3) {
					vector <int> idx;
					idx.push_back(i); idx.push_back(j);
					threeidx.push_back(idx);
				}
			}
		}
	}
	return threeidx;
}