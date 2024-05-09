#include <iostream>
#include "Queue.h"
#include "Man.h"

void instructions(void);

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    
    int n, choice;
    cout << "Сколько очередей вы собираетесь использовать?" << endl;
    cin >> n;
    if (n > 0)
    {
        Queue* List = new Queue[n];
        instructions();
        cout << "Введите выбор: ";
        cin >> choice;
        while (choice != 0)
        {
            switch (choice)
            {
            case 0:
                cout << "Завершение программы" << endl;
                break;
            case 1:
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].tek_znach();
                }
                else
                {
                    List[0].tek_znach();
                }
                break;
            case 2:
                float znach;
                cout << "Какое значение вы хотите добавить? ";
                cin >> znach;
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].add_nach(znach);
                }
                else
                {
                    List[0].add_nach(znach);
                }
                break;
            case 3:
                float znach1;
                cout << "Какое значение вы хотите добавить? ";
                cin >> znach1;
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].add_con(znach1);
                }
                else
                {
                    List[0].add_con(znach1);
                }
                break;
            case 4:
                float old_value, new_value;
                cout << "Введите новое значение и то, которое вы хотите заменить: ";
                cin >> new_value >> old_value;
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].change(old_value, new_value);
                }
                else
                {
                    List[0].change(old_value, new_value);
                }
                break;
            case 5:
                float value;
                cout << "Введите значение, которое хотите удалить: ";
                cin >> value;
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].del_info(value);
                }
                else
                {
                    List[0].del_info(value);
                }
                break;
            case 6:
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].del_all();
                }
                else
                {
                    List[0].del_all();
                }
                break;
            case 7:
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].sort();
                }
                else
                {
                    List[0].sort();
                }
                break;
            case 8:
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    cout<<List[number - 1];
                }
                else
                {
                    cout << List[0];
                }
                break;
            case 9:
                if (n > 1)
                {
                    int number;
                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                    cin >> number;
                    List[number - 1].inversion();
                }
                else
                {
                    List[0].inversion();
                }
            default:
                cout << "\nВыберете существующее значение" << endl << endl;
                instructions();
                break;
            }
            cout << "\n Введите следующую команду: ";
            cin >> choice;
        }
    }
    return 0;
}

void instructions(void)
{
    cout << "Выберете действвие: \n 1)узнать текущее состояние"
        "\n 2)Вставить до(в начало)"
        "\n 3)Вставить после(в конец)"
        "\n 4)Заменить элемент"
        "\n 5)Удалить элемент"
        "\n 6)Удалить всю очередь"
        "\n 7)Упорядочить очередь"
        "\n 8)Распечатать очередь"
        "\n 9)Инвертровать очередь"
        "\n 10)Сложить две очереди"
        "\n 11)Слить две очереди"
        "\n 12)Удалить двойников в очереди"
        "\n 13)Проверить, не пуста ли очередь"
        "\n 0)Завершить\n";
}
