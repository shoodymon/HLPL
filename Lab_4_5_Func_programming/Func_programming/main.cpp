//// Пример 2: Функция для проверки, является ли число простым
//
//#include <iostream>
//
//bool isPrime(int n) {
//    if (n <= 1) return false; // 0 и 1 не являются простыми числами
//    for (int i = 2; i * i <= n; ++i) {
//        if (n % i == 0) return false; // Если n делится на i, оно не простое
//    }
//    return true; // Если делителей не найдено, n - простое число
//}
//
//int main() {
//    setlocale(0, "");
//    int number = 7;
//    std::string surname = "Живоглод";
//
//    if (isPrime(number)) {
//        std::cout << surname << ": " << number << " является простым числом." << std::endl;
//    }
//    else {
//        std::cout << surname << ": " << number << " не является простым числом." << std::endl;
//    }
//
//    system("pause");
//    return 0;
//}

//// Пример 3: Расчет сложных процентов
//
//#include <iostream>
//#include <cmath>
//
//double calculateCompoundInterest(double principal, double rate, int years) {
//    return principal * std::pow(1 + rate / 100, years);
//}
//
//int main() {
//    setlocale(0, "");
//
//    double principal = 1000.0; // Начальная сумма
//    double rate = 5.0; // Процентная ставка
//    int years = 10; // Количество лет
//    std::string surname = "Живоглод";
//
//    double amount = calculateCompoundInterest(principal, rate, years);
//
//    std::cout << surname << ": Сумма через " << years << " лет: " << amount << std::endl;
//
//    system("pause");
//    return 0;
//}

//// Пример 4: Расчет точки безубыточности
//
//#include <iostream>
//
//// Функция для расчета точки безубыточности
//double calculateBreakEvenPoint(double fixedCosts, double variableCostPerUnit, double pricePerUnit) {
//    // Проверка, что цена продажи больше переменных затрат
//    if (pricePerUnit <= variableCostPerUnit) {
//        throw std::invalid_argument("Цена продажи должна быть больше переменных затрат.");
//    }
//
//    // Возвращаем точку безубыточности, рассчитанную по формуле
//    return fixedCosts / (pricePerUnit - variableCostPerUnit);
//}
//
//int main() {
//    setlocale(0, "");
//
//    // Инициализация переменных
//    double fixedCosts = 5000.0; // Фиксированные затраты (например, аренда, зарплата)
//    double variableCostPerUnit = 20.0; // Переменные затраты на единицу (например, сырьё)
//    double pricePerUnit = 50.0; // Цена продажи за единицу
//    std::string surname = "Живоглод";
//
//    try {
//        // Вызов функции расчета точки безубыточности и сохранение результата в переменной
//        double breakEvenPoint = calculateBreakEvenPoint(fixedCosts, variableCostPerUnit, pricePerUnit);
//
//        // Вывод результата на экран
//        std::cout << surname << ": Точка безубыточности: " << breakEvenPoint << " единиц." << std::endl;
//    }
//    catch (const std::invalid_argument& e) {
//        // Обработка исключения, если цена продажи меньше или равна переменным затратам
//        std::cerr << surname << ": " << e.what() << std::endl; // Вывод сообщения об ошибке
//    }
//
//    system("pause");
//    return 0;
//}

//// Пример 5: Функция, принимающая другую функцию в качестве аргумента
//
//#include <iostream>
//#include <vector>
//#include <functional> // Для использования std::function
//
//// Функция для расчета стоимости доставки
//// Принимает вес груза и функцию для расчета стоимости
//double calculateDeliveryCost(double weight, std::function<double(double)> costFunction) {
//    return costFunction(weight); // Вызываем переданную функцию с весом груза
//}
//
//// Функция расчета стоимости стандартной доставки
//// Умножает вес на 5.0 (стоимость за кг для стандартной доставки)
//double standardDelivery(double weight) {
//    return weight * 5.0; // Возвращает стоимость доставки
//}
//
//// Функция расчета стоимости экспресс-доставки
//// Умножает вес на 10.0 (стоимость за кг для экспресс-доставки)
//double expressDelivery(double weight) {
//    return weight * 10.0; // Возвращает стоимость доставки
//}
//
//int main() {
//    // Массив с весами грузов (в кг)
//    std::vector<double> cargoWeights = { 10.0, 20.0, 5.0, 15.0 };
//
//    setlocale(0, "");
//    std::string surname = "Живоглод";
//
//    // Вывод стоимости доставки для стандартного варианта
//    std::cout << surname << ": Стоимость доставки (стандартная):" << std::endl;
//    for (double weight : cargoWeights) {
//        // Вызов функции calculateDeliveryCost с весом и стандартной функцией
//        double cost = calculateDeliveryCost(weight, standardDelivery);
//
//        // Вывод веса груза и стоимости его доставки
//        std::cout << "Вес: " << weight << " кг, Стоимость: " << cost << " руб." << std::endl;
//    }
//
//    // Вывод стоимости доставки для срочного варианта
//    std::cout << "\nСтоимость доставки (срочная):" << std::endl;
//    for (double weight : cargoWeights) {
//        // Вызов функции calculateDeliveryCost с весом и функцией экспресс-доставки
//        double cost = calculateDeliveryCost(weight, expressDelivery);
//
//        // Вывод веса груза и стоимости его доставки
//        std::cout << "Вес: " << weight << " кг, Стоимость: " << cost << " руб." << std::endl;
//    }
//
//    system("pause");
//    return 0;
//}

//// Пример 6: Функция, возвращающая другую функцию
//
//#include <iostream>
//#include <functional> // библиотека для использования std::function
//
//using namespace std; // Использование пространства имен std для удобства
//
//// Функция, которая возвращает другую функцию для расчета стоимости доставки
//function<double(double)> createDeliveryCostCalculator(double baseRate, double perKmRate) {
//    // Возвращаемая функция, принимающая расстояние и рассчитывающая стоимость
//    return [baseRate, perKmRate](double distance) {
//        // Расчет стоимости доставки: базовая ставка + ставка за километр * расстояние
//        return baseRate + (perKmRate * distance);
//        };
//}
//
//int main() {
//    // Настройка функций для разных типов доставки
//    // Стандартная доставка: базовая ставка 5, 1 рубль за километр
//    auto standardDelivery = createDeliveryCostCalculator(5.0, 1.0);
//
//    setlocale(0, "");
//    string surname = "Живоглод";
//
//    // Экспресс-доставка: базовая ставка 10, 2 рубля за километр
//    auto expressDelivery = createDeliveryCostCalculator(10.0, 2.0);
//
//    // Переменная для хранения расстояния, введенного пользователем
//    double distance;
//
//    // Запрос у пользователя расстояния доставки
//    cout << "Введите расстояние для доставки (в км): ";
//    cin >> distance; // Чтение расстояния с клавиатуры
//
//    // Расчет стоимости стандартной доставки путем передачи расстояния в функцию
//    double standardCost = standardDelivery(distance);
//
//    // Расчет стоимости экспресс-доставки путем передачи расстояния в функцию
//    double expressCost = expressDelivery(distance);
//
//    // Вывод стоимости стандартной доставки
//    cout << surname << ": Стоимость стандартной доставки: " << standardCost << " руб." << endl;
//
//    // Вывод стоимости экспресс-доставки
//    cout << surname << ": Стоимость экспресс-доставки: " << expressCost << " руб." << endl;
//
//    system("pause");
//    return 0;
//}

//// Пример 7: Функциональное программирование со стандартной библиотекой
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//
//// Функция для проверки, является ли число четным
//bool isEven(int number) {
//    return number % 2 == 0;
//}
//
//// Функция для удвоения числа
//int doubleValue(int number) {
//    return number * 2;
//}
//
//// Основная функция
//int main() {
//    // Исходный вектор чисел
//    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    setlocale(0, "");
//    std::string surname = "Живоглод";
//
//    // Фильтрация четных чисел
//    std::vector<int> evenNumbers;
//    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers), isEven);
//
//    // Преобразование четных чисел (удвоение)
//    std::vector<int> doubledEvenNumbers;
//    std::transform(evenNumbers.begin(), evenNumbers.end(), std::back_inserter(doubledEvenNumbers), doubleValue);
//
//    // Вывод результата
//    std::cout << surname << ": Четные числа, удвоенные: ";
//    for (int num : doubledEvenNumbers) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    system("pause");
//    return 0;
//}

// Пример 8: Использование лямбда-функций для фильтрации массива автомобилей

#include <iostream>
#include <vector>
#include <algorithm> // Для std::copy_if

// Структура для представления автомобиля
struct Car {
    std::string name; // Название автомобиля
    double weight; // Вес автомобиля в килограммах
};

int main() {
    // Создаем вектор автомобилей с их названиями и весами
    std::vector<Car> cars = {
        {"Toyota", 900},
        {"BMW", 1200},
        {"Honda", 950},
        {"Ford", 1100},
        {"Fiat", 800}
    };

    setlocale(0, "");
    std::string surname = "Живоглод";

    // Вектор для хранения отфильтрованных автомобилей
    std::vector<Car> lightweightCars;

    // Используем std::copy_if для фильтрации автомобилей
    std::copy_if(cars.begin(), cars.end(), std::back_inserter(lightweightCars),
        // Лямбда-функция для проверки условия фильтрации
        [](const Car& car) { return car.weight < 1000; });

    // Вывод результатов отфильтрованного списка автомобилей
    std::cout << surname << ": Машины с весом менее 1 тонны:" << std::endl;
    for (const auto& car : lightweightCars) {
        std::cout << car.name << " (вес: " << car.weight << " кг)" << std::endl;
    }

    system("pause");
    return 0;
}