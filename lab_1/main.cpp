#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


void fileToVector(string path)
{
    /*
    ifstream file(path); // Открыть файл для чтения
    if (!file.is_open()) {
        wcout << L"Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;
    string parametr;

    while (getline(file, line)) { // Чтение строки до '\n'
        Window current;
        parametr = "";
        stringstream sline(line);
        struct_vector.push_back(line);
    }
    file.close(); // Закрыть файл
    */
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

}

int main()
{
    vector<string> someStr;
    someStr.push_back("Hello world!");
    someStr.push_back("This is test string 1");
    someStr.push_back("This is test string 2");
    someStr.push_back("This is test string 3");
    fileToVector("data.txt");
    vectorConsoleOutput(someStr);
    vectorToFile(someStr);

    return 0;
}
