#include <iostream>
#include <memory> // подключение библиотеки хранящей в себе описание классов представляющих умные указатели
#include "Shared_ptr.hpp"



int main() {
    setlocale(LC_ALL, "ru");
    int n;

    // Умный указатель на уникальную память
   /*

    n = 15;
    // std::unique_ptr<int> uniq1(&n); // умный указатель
    int* ptmp = new int{ 7 };
    std::unique_ptr<int> uniq2(ptmp);
    // std::cout << "*uniq1 = " << *uniq1 << std::endl;
    std::cout << "*uniq2 = " << *uniq2 << std::endl;
    uniq2.reset(new int[3]);  // умное перенаправление указателя (удалит то что было до этого)
    uniq2.get(); // получение самого указателя из класса

    // std::unique_ptr<int>uniq3 = uniq2; //ошибка! два умныйх уникальных указателя направляются на одну память
    std::unique_ptr<int> uniq4(ptmp);

    auto uniq5(std::make_unique<int>()); // Более "умное" выделение памяти
    */

    // Общий указатель
    /*
    std::shared_ptr<int> shared1(new int);
    std::shared_ptr<int> shared2 = shared1;
    *shared1 = 50;
    std::cout << *shared2 << std::endl;
*/

    // Слабый указатель
    std::weak_ptr<int> weak(std::make_shared<int>(50)); // 
    // std::weak_ptr<int> weak(std::make_weak<int>(50)); // ОШИБКА

    // проверка собственного общего указателя
    my::shared_ptr_test(new int{ 10 });


    return 0;
}
