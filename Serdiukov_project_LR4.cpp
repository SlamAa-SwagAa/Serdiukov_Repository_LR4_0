#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <limits>
#include <cctype>

using namespace std;

int markA, markB, markC;
char mathGrade;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...) {
        return false;
    }
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

void enterMarkA() {
    const map<char, string> validGrades = {
        {'A', "Отлично"},
        {'B', "Хорошо"},
        {'C', "Удовлетворительно"},
        {'D', "Неудовлетворительно"},
        {'F', "Неудача"}
    };

    while (true) {
        cout << "\nВведите оценку по математике (A, B, C, D, F): ";
        char input;
        cin >> input;
        input = toupper(input);

        if (validGrades.find(input) != validGrades.end()) {
            mathGrade = input;
            cout << "Оценка по математике: " << mathGrade
                 << " (" << validGrades.at(mathGrade) << ")\n";
            break;
        } else {
            cout << "Ошибка! Допустимые оценки: A, B, C, D, F. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void enterMarkB() {
}

void enterMarkC() {
}

void average_score() {
}

void score_comparisons() {
}

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод оценки по математике A", enterMarkA}},
        {2, {"Ввод оценки по физике B", enterMarkB}},
        {3, {"Ввод оценки по химии C", enterMarkC}},
        {4, {"Расчет среднего балла", average_score}},
        {5, {"Сравнение оценок (больше 4.00 или нет)", score_comparisons}},
    };

    int choice = 0;

    while (true) {
        cout << "Меню: " << endl;
        for (const auto& item : menu) {
            cout << "Задача " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некоректный ввод. Пожалуйста, введите число.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Firstname Lastname" << endl;
            break;
        }

        cout << endl;
        if (menu.find(choice) != menu.end()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menu[choice].action();
        } else {
            cout << "Некоректный ввод.";
        }
        cout << endl;
    }
    return 0;
}
