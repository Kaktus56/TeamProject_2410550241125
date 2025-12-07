#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


int fileToVector(string path, vector<string> *someVec)
{
    ifstream file(path); // Открыть файл для чтения
    if (!file.is_open()) {
        wcout << L"Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;

    while (getline(file, line)) { // Чтение строки до '\n'
        someVec->push_back(line);
    }
    file.close(); // Закрыть файл
    return 0;
}

void vetorConsoleOutput(vector<string> vec)
{

}

void vectorToFile(vector<string> vec)
{

}

int main()
{
    vector<string> someStr;

    fileToVector("data.txt", &someStr);
    vetorConsoleOutput(someStr);
    vectorToFile(someStr);

    return 0;
}
