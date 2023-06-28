#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Zalik {
public:
    string name;
    int o;
    int k;
};

void PrintZalikovka(Zalik* Temp, int size) {
    cout << endl << "Ваша залікова книжка " << endl;
    for (int i = 0; i < size; i++) {
        cout << "*********************************" << endl;
        cout << "Дисципліна ";
        cout << Temp[i].name << endl;
        cout << "Oцінкa з  предмету ";
        cout << Temp[i].o << endl;
        cout << "*********************************" << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Привіт, це Олександр, розробник цієї програми, вона створена задля розрахунку рейтингового балу " << endl;
    cout << "Cпочатку потрібно заповнити залікову книжку, це не займе більше 2 хв.)" << endl;
    int size;
    cout << "Введіть кількість предметів: ";
    cin >> size;
    Zalik* Zalikovka = new Zalik[size];
    for (int i = 0; i < size; i++) {
        cout << "Ведіть назву предмету ";
        cin >> Zalikovka[i].name;
        cout << "Ведіть коефіцієнт предмету ";
        cin >> Zalikovka[i].k;
        cout << "Ведіть оцінку предмету ";
        cin >> Zalikovka[i].o;
    }
    int* ko = new int[size];
    int sum_k = 0, sum_ko = 0;
    for (int i = 0; i < size; i++) {
        ko[i] = Zalikovka[i].k * Zalikovka[i].o;
        sum_k += Zalikovka[i].k;
        sum_ko += ko[i];
    }
    double rating;
    rating = 90.0 * (sum_ko) / (sum_k * 100);
    cout << "\033[2J\033[1;1H";
    bool menu;
    bool check = 1;
    while (check == 1) {
        cout << "\033[2J\033[1;1H";
        cout << "Ви потрапили у головне меню: залікова книжка(0); рейтингови бал(1)";
        cin >> menu;
        if (menu) {
            cout << "Ваш рейтинговий бал " << rating << endl;
        }
        else {
            PrintZalikovka(Zalikovka, size);
        }
        cout << endl << "Меню(1) Вийти(0)";
        cin >> check;
    }
    delete[] Zalikovka;
    delete[] ko;
}