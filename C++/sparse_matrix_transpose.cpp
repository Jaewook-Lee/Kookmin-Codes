/*************************************************************************************
 * Name : 이재욱
 * Student ID : 20181670
 * Program ID : HW #1-1
 * Description : This program is written for assignment.
 *               Main purpose is transposing a sparse matrix.
 * Algorithm : 'Fast Transpose' in lecture slide #13 named 'char2 array.pdf'
 * Variables :
 *     fast_transpose : A function used for transposing a matrix.
 *                      Doesn't have return value.
 *     array_sort : A function used for sorting a matrix.
 *                  Doesn't have return value.
 *     main : Reading a matrix from file 'lab2-1.txt' and printout transposed matrix.
 * ***********************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

void fast_transpose(int a[][3], int b[][3], int r);
void array_sort(int array[][3], int r);

int main()
{
    ifstream reader;
    reader.open("lab2-1.txt");
    int row_cnt, col_cnt, val_cnt;
    reader >> row_cnt >> col_cnt >> val_cnt;
    int origin_array[val_cnt][3];
    int transposed_array[val_cnt][3];

    int idx = 0;
    while(!reader.eof())
    {
        int row, col, val;
        reader >> row >> col >> val;
        origin_array[idx][0] = row;
        origin_array[idx][1] = col;
        origin_array[idx][2] = val;

        idx++;
    }

    reader.close();
    
    fast_transpose(origin_array, transposed_array, val_cnt);

    cout << row_cnt << " " << col_cnt << " " << val_cnt << endl;
    for (int i=0; i<val_cnt; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << transposed_array[i][j] << " ";
        }
        cout << "\n";
    }
}

/******************************************************
 * Function : fast_transpose
 * description : Transposing array 'a'
 *               and save at array 'b'.
 *               And 'b' has to be sorted.
 * Variables :
 *     a : A parameter getting array not transposed.
 *     b : A parameter saving array will be transposed.
 *     r : A parameter using for limit of procedure.
 * ****************************************************/
void fast_transpose(int a[][3], int b[][3], int r)
{
    for (int i=0; i<r; i++)
    {
        b[i][0] = a[i][1];
        b[i][1] = a[i][0];
        b[i][2] = a[i][2];
    }

    array_sort(b, r);
}

/********************************************************************
 * Function : array_sort
 * description : Sorting array by row.
 * Variables :
 *     row_tmp, col_tmp, val_tmp : Variables for changing elements.
 *     i, j : Variables indicates row index and column index.
 * ******************************************************************/
void array_sort(int array[][3], int r)
{
    int row_tmp, col_tmp, val_tmp;
    for (int i=0; i<r-1; i++)
    {
        for (int j=i+1; j<r; j++)
        {
            if (array[i][0] > array[j][0])
            {
                row_tmp = array[i][0];
                array[i][0] = array[j][0];
                array[j][0] = row_tmp;

                col_tmp = array[i][1];
                array[i][1] = array[j][1];
                array[j][1] = col_tmp;

                val_tmp = array[i][2];
                array[i][2] = array[j][2];
                array[j][2] = val_tmp;
            }
        }
    }
}