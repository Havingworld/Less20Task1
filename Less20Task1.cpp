/*
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:

имя и фамилия человека;
количество денег, которые были выплачены лицу;
дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной суммой выплат.

Пример данных ведомости

Tom Hanks 35500 10.11.2020
Rebecca Williams 85000 1.1.2021
Sally Field 15600 15.8.2021
Michael Humphreys 29400 23.5.2020
Harold Herthum 74300 9.6.2019
George Kelly 45000 12.3.2018
Bob Penny 12500 13.5.2020
John Randall 23400 2.10.2020
Sam Anderson 6500 15.7.2020
Margo Moorer 12350 24.2.2019
*/
/*
Что нужно сделать
В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. Теперь требуется создать простую программу записи 
в эту ведомость.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. 
Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть расположен перевод строки.
При старте программы пользователь последовательно вводит данные для новой записи, которые записываются затем в файл в текстовом режиме.
Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.

Советы и рекомендации
Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.
Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с корректно указанным диапазоном символов в дате.
К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц для последующего анализа.

Что оценивается
Корректность работы программы. Программа должна дозаписывать данные в конец существующего списка.
*/

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
using namespace std;

int main()
{
    ofstream statement("statement.txt", ios::app);
    if (statement.is_open())
    {
        /*
        string firstname, secendname, data,
                bigFirstname, bigSecendname;
        float cash, bigCash = 0, summ = 0;
        
        while (!statement.eof())
        {
            statement >> firstname >> secendname >> cash >> data;
            if (cash > bigCash) {
                bigCash = cash;
                bigFirstname = firstname;
                bigSecendname = secendname;
            }
            summ += cash;
        }

        cout << "Summ of cash: " << summ << "$" << endl
            << "Bigger payment: " << bigFirstname << " "
            << bigSecendname << " - "
            << bigCash << "$";
        */
        //statement << endl << "new-newdata";

        string firstname, secondname, date;
        int cash;
        cout << "Input: Firstname Secondname Date(DD.MM.YYYY) Cash " << endl;
        cin >> firstname >> secondname >> date >> cash;
        
        //вставить цикл на проверку даты
        
        bool dateOk = false;
        while (!dateOk)
        {
            
            //string to int
            if (date.size() != 10) 
            {
                cout << "invalid date, try again1" << endl;
                cin >> date;
                continue;
            }
            int day = stoi(date.substr(0, 2));
            int month = stoi(date.substr(3, 2));
            int year = stoi(date.substr(6, 4));
            if (day > 0 && day < 32
                && month > 0 && month < 13
                && year > 1970 && year < 2222) dateOk = true;
            if (dateOk) break;
            cout << "invalid date, try again2" << endl;
            cin >> date;
        }

        statement << firstname << " " << secondname << " " << date << " " << cash << "rub" << endl;
    }
    else
    {
        // show message:
        cout << "Error opening file";
    }

    statement.close();
}