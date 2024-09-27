using namespace std;
#include <iostream>

struct Date 
{
    int day;
    int month;
    int year;
};

bool Visokos(int year) 
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool dateKor(Date date) {
    if (date.month < 1 || date.month > 12) 
    {
        return false;
    }

    int maxDays;
    if (date.month == 2) 
    {
        maxDays = Visokos(date.year) ? 29 : 28;
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) 
    {
        maxDays = 30;
    }
    else 
    {
        maxDays = 31;
    }

    if (date.day < 1 || date.day > maxDays) 
    {
        return false;
    }

    return true;
}

int main() {
    setlocale(0, "rus");
    Date date;
    cout << "Введите день: ";
    cin >> date.day;
    cout << "Введите месяц: ";
    cin >> date.month;
    cout << "Введите год: ";
    cin >> date.year;
    if (dateKor(date)) 
    {
        cout << "Дата корректна." << endl;
    }
    else 
    {
        cout << "Дата некорректна." << endl;
    }
}
