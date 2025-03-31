#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <stdexcept>

const std::string STUDENT_NAME = "Живоглод";

// Функция для Примера 1: std::async
void example1() {
    std::cout << "\n=== Пример 1: Пример асинхронного выполнения в C++ ===\n";
    std::cout << "Студент: " << STUDENT_NAME << "\n\n";

    // Функция, выполняемая асинхронно
    auto asyncFunction = [](int x) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация долгой работы
        return x * x; // Возвращает квадрат числа
        };

    // Запуск функции асинхронно
    std::future<int> result = std::async(std::launch::async, asyncFunction, 5);

    // Выполняем другие действия в основном потоке
    std::cout << "Выполняем другие задачи в основном потоке..." << std::endl;

    // Получаем результат асинхронной функции
    std::cout << "Ожидание завершения асинхронной задачи..." << std::endl;
    int value = result.get(); // Блокирует выполнение до получения результата

    // Вывод результата
    std::cout << "Результат асинхронной задачи: " << value << std::endl;
    std::cout << "Студент: " << STUDENT_NAME << std::endl;
}

// Функция для Примера 2: std::promise и std::future
void example2() {
    std::cout << "\n=== Пример 2: Пример асинхронного выполнения в C++ с использованием std::promise и std::future ===\n";
    std::cout << "Студент: " << STUDENT_NAME << "\n\n";

    // Функция, выполняемая в отдельном потоке
    auto asyncFunction = [](std::promise<int> prom) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация долгой работы
        prom.set_value(42); // Устанавливаем значение в promise
        };

    // Создаем promise и получаем future
    std::promise<int> prom;
    std::future<int> result = prom.get_future();

    // Запускаем асинхронную функцию в отдельном потоке
    std::thread t(asyncFunction, std::move(prom));

    // Выполняем другие действия в основном потоке
    std::cout << "Выполняем другие задачи в основном потоке..." << std::endl;

    // Получаем результат из future
    std::cout << "Ожидание завершения асинхронной задачи..." << std::endl;
    int value = result.get(); // Блокирует выполнение до получения результата

    // Вывод результата
    std::cout << "Результат асинхронной задачи: " << value << std::endl;
    std::cout << "Студент: " << STUDENT_NAME << std::endl;

    // Завершаем поток
    t.join();
}

// Функция для Примера 3: Обработка ошибок с std::promise
void example3() {
    std::cout << "\n=== Пример 3: Использование std::promise для обработки ошибок ===\n";
    std::cout << "Студент: " << STUDENT_NAME << "\n\n";

    // Функция, выполняемая в отдельном потоке
    auto asyncFunction = [](std::promise<int> prom) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация долгой работы
        // Генерируем ошибку
        prom.set_exception(std::make_exception_ptr(std::runtime_error("Произошла ошибка")));
        };

    // Создаем promise и получаем future
    std::promise<int> prom;
    std::future<int> result = prom.get_future();

    // Запускаем асинхронную функцию в отдельном потоке
    std::thread t(asyncFunction, std::move(prom));

    // Выполняем другие действия в основном потоке
    std::cout << "Выполняем другие задачи в основном потоке..." << std::endl;

    // Обработка результата из future
    try {
        std::cout << "Ожидание завершения асинхронной задачи..." << std::endl;
        int value = result.get(); // Блокирует выполнение до получения результата
        std::cout << "Результат асинхронной задачи: " << value << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl; // Обработка ошибки
        std::cout << "Студент: " << STUDENT_NAME << std::endl;
    }

    // Завершаем поток
    t.join();
}

int main() {
    setlocale(0, "");

    std::cout << "Примеры асинхронного выполнения кода на C++\n";
    std::cout << "Студент: " << STUDENT_NAME << "\n";

    example1();
    example2();
    example3();

    std::cout << "\nНажмите Enter для завершения...\n";
    std::cin.get();
    return 0;
}