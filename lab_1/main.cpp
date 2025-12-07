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

void vectorConsoleOutput(vector<string> vec)
{
    cout << "This vector have:" << endl;
    cout << "Vector size: " << vec.size() << endl;
    cout << "--------------------------" << endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << "[" << setw(3) << i << "] " << vec[i] << endl;
    }

    cout << "--------------------------" << endl;
}

void vectorToFile(vector<string> vec)
{
    const string filename = "output.txt";
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cerr « "ОШИБКА: не удалось открыть файл '" « filename « "' для записи!" « endl;
        return;
    }

    int count = 0;
    for (const auto& line : vec) {
        outFile « line « endl;
        count++;
    }

    outFile.close();
    cout « "✓ Успешно записано " « count « " строк в файл '" « filename « "'" « endl;
}
