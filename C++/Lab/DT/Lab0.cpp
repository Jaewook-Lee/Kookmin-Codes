#include <fstream>
#include <iostream>
using namespace std;

void wordCount(string file_name);
void minAndMax(int data[], int size);
int main()
{
    wordCount("lab0-1.dat");
    cout << "\n";
    int raw_data[10] = {90, 40, 60, 10, 50, 80, 20, 70, 30, 100};
    minAndMax(raw_data, 10);
}

void wordCount(const string file_name)
{
    const int BUFFER_SIZE = 80;
    ifstream reader;
    reader.open(file_name);
    char line[BUFFER_SIZE];
    int word_cnt = 0, sum_cnt = 0;
    
    while (!reader.eof())
    {
        reader.getline(line, BUFFER_SIZE);

        if (reader.eof())
            break;
        else
        {
            for (int i=0; line[i] != '\0'; i++)
            {
                if (line[i] == ' ')
                {
                    word_cnt++;
                }
            }
            word_cnt++;
            cout << line << "\n" << "The number of words : " << word_cnt << endl;
            sum_cnt += word_cnt;
            word_cnt = 0;
        }
    }
    cout << "Total Number of Words : " << sum_cnt << endl;
    reader.close();
}

void minAndMax(int data[], int size)
{
    int min = data[0], max = data[0];
    int min_idx = 0, max_idx = 0;
    for (int i=1; i<size; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
            min_idx = i;
        }
        else if (data[i] > max)
        {
            max = data[i];
            max_idx = i;
        }
    }

    cout << "Minimum number is " << min << " at position " << min_idx + 1 << ", \n";
    cout << "Maximum number is " << max << " at position " << max_idx + 1 << endl;
}