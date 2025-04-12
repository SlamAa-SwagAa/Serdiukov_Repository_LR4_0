#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int markA, markB, markC;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...)
    { return false; }
    return true;
}

void EnterNumber(int& varLink, string label) {
    string str_input;
    cout << label << " = ";
    getline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << label << " = ";
        getline(cin, str_input);
    }
varLink = stoi(str_input);   
}

void enterMarkA()
{

}

void enterMarkB()
{

}

void enterMarkC()
{

}

void average_score()
{

}

void score_comparisons()
{

}

struct MenuItem {
        string title;
        function<void()> action;
    };
int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод оценки по матиматике A", enterMarkA}},
        {2, {"Ввод оценки по физике B", enterMarkB}},
        {3, {"Ввод оценки по химии С", enterMarkC}},
        {4, {"Calc of average score", average_score}},
        {5, {"Score comparisons(more than 4,00 or not)", score_comparisons}},

    };

    int choice = 0;

    while (true) {
        cout << "Меню: " << endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << std::endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Firstname Lastname" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некоректный ввод.";
        }
        cout << endl;
    }
    return 0;
}
