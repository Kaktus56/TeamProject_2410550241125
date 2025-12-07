#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <windows.h>

using namespace std;

void fileToVector(string path, vector<string>& outputVec)
{
    // Реализация участником №1
}

void vetorConsoleOutput(vector<string> vec)
{
    // Реализация участником №2
}

void vectorToFile(vector<string> vec)
{
    const string filename = "output.txt";
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cerr << "ОШИБКА: не удалось открыть файл '" << filename << "' для записи!" << endl;
        return;
    }

    int count = 0;
    for (const auto& line : vec) {
        outFile << line << endl;
        count++;
    }

    outFile.close();
    cout << "✓ Успешно записано " << count << " строк в файл '" << filename << "'" << endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<string> someStr;
    fileToVector("data.txt", someStr);
    vetorConsoleOutput(someStr);
    vectorToFile(someStr);

    return 0;
}


