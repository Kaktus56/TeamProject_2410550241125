#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

#pragma pack(push, 1)
struct Window
{
    string ser_num;
    double hight;
    double width;
    bool canOpen;
    string colorFrame;
};
#pragma pack(pop)

string Window_toString(const Window *comp)
{
    string str =
        "Window:\n Serial Number: " + comp->ser_num
        + "\n Hight: " + to_string(comp->hight)
        + "\n width: " + to_string(comp->width)
        + "\n Can Open: " + to_string(comp->canOpen)
        + "\n Color of Frame: " + comp->colorFrame;
    return str;
};

void Window_ConsoleOutputList(const Window *arr, int size)
{
    for (int i=0; i<size; i++)
    {
        cout << i << " "<<
        Window_toString(&arr[i])
        << "\n"
        << endl;
    };
};

stringstream Window_VectorToStringStream(const vector<Window> *vec)
{
    stringstream str;
    str << "Serial Num"<< setw(12)
        << "Hight" << setw(12)
        <<"Width" << setw(12)
        << "Open" << setw(12)
        << "FrameColor" << endl;
    for (auto current : (*vec))
    {
        str << current.ser_num << setw(12)
        << to_string(current.hight) << setw(12)
        << to_string(current.width) << setw(6)
        << to_string(current.canOpen) << setw(12)
        << current.colorFrame << endl;
    }
    return str;
};

void Window_MaxSpace(const Window *arr, int size)
{
    int max_index = 0;
    double max_space = 0.0;
    double space;
    for (int i=0; i<size; i++)
    {
        space = arr[i].width * arr[i].hight;
        if (max_space < space)
        {
            max_space = space;
            max_index = i;
        }
    };
    cout << "Window with max space is: \n"
        << Window_toString(&arr[max_index])
        << endl;
};



int main()
{
    vector<Window> struct_vector;

    ifstream file("data.txt"); // Открыть файл для чтения
    if (!file.is_open()) {
        wcout << L"Ошибка открытия файла!" << endl;
        return 1;
    }

    string line;
    string parametr;

    while (getline(file, line)) { // Чтение строки до '\n'
        Window current;

        parametr = "";
        //cout << line << endl;
        stringstream sline(line);

        sline >> current.ser_num;
        sline >> current.hight;
        sline >> current.width;
        sline >> parametr;
        current.canOpen = parametr=="true" ? true : false;
        sline >> current.colorFrame;
        struct_vector.push_back(current);
    }
    file.close(); // Закрыть файл

    stringstream srime = Window_VectorToStringStream(&struct_vector);
    cout << srime.str();

    cout << endl << "// Writing in .bin file..." << endl;
    ofstream out("window_out.bin", ios::binary);
    size_t siz = srime.str().size();
    out.write(reinterpret_cast<char*>(&srime.str()[0]), siz);
    out.close();
    cout << "// Writing ended" << endl;

    /*
    do something changes for Git #1
    */

    /*
    do something changes for Git #2
    */

    /*
    do something changes for Git #3
    */


    /*
    int arsize = 4;

    Window *Arr = new Window[arsize]{
        {"0000-0000-0000", 5, 4,false, "gray"},
        {"0001-3333-2222", 16, 9, true, "pink"},
        {"9178-6666-3333", 20, 15, true, "black"},
        {"7466-4976-2342", 11, 11, false, "white"}
    };
    Window_ConsoleOutputList(Arr, arsize);
    Window_MaxSpace(Arr, arsize);

    delete[] Arr;
    */

    return 0;
}
