//// ������ 2: ������� ��� ��������, �������� �� ����� �������
//
//#include <iostream>
//
//bool isPrime(int n) {
//    if (n <= 1) return false; // 0 � 1 �� �������� �������� �������
//    for (int i = 2; i * i <= n; ++i) {
//        if (n % i == 0) return false; // ���� n ������� �� i, ��� �� �������
//    }
//    return true; // ���� ��������� �� �������, n - ������� �����
//}
//
//int main() {
//    setlocale(0, "");
//    int number = 7;
//    std::string surname = "��������";
//
//    if (isPrime(number)) {
//        std::cout << surname << ": " << number << " �������� ������� ������." << std::endl;
//    }
//    else {
//        std::cout << surname << ": " << number << " �� �������� ������� ������." << std::endl;
//    }
//
//    system("pause");
//    return 0;
//}

//// ������ 3: ������ ������� ���������
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
//    double principal = 1000.0; // ��������� �����
//    double rate = 5.0; // ���������� ������
//    int years = 10; // ���������� ���
//    std::string surname = "��������";
//
//    double amount = calculateCompoundInterest(principal, rate, years);
//
//    std::cout << surname << ": ����� ����� " << years << " ���: " << amount << std::endl;
//
//    system("pause");
//    return 0;
//}

//// ������ 4: ������ ����� ��������������
//
//#include <iostream>
//
//// ������� ��� ������� ����� ��������������
//double calculateBreakEvenPoint(double fixedCosts, double variableCostPerUnit, double pricePerUnit) {
//    // ��������, ��� ���� ������� ������ ���������� ������
//    if (pricePerUnit <= variableCostPerUnit) {
//        throw std::invalid_argument("���� ������� ������ ���� ������ ���������� ������.");
//    }
//
//    // ���������� ����� ��������������, ������������ �� �������
//    return fixedCosts / (pricePerUnit - variableCostPerUnit);
//}
//
//int main() {
//    setlocale(0, "");
//
//    // ������������� ����������
//    double fixedCosts = 5000.0; // ������������� ������� (��������, ������, ��������)
//    double variableCostPerUnit = 20.0; // ���������� ������� �� ������� (��������, �����)
//    double pricePerUnit = 50.0; // ���� ������� �� �������
//    std::string surname = "��������";
//
//    try {
//        // ����� ������� ������� ����� �������������� � ���������� ���������� � ����������
//        double breakEvenPoint = calculateBreakEvenPoint(fixedCosts, variableCostPerUnit, pricePerUnit);
//
//        // ����� ���������� �� �����
//        std::cout << surname << ": ����� ��������������: " << breakEvenPoint << " ������." << std::endl;
//    }
//    catch (const std::invalid_argument& e) {
//        // ��������� ����������, ���� ���� ������� ������ ��� ����� ���������� ��������
//        std::cerr << surname << ": " << e.what() << std::endl; // ����� ��������� �� ������
//    }
//
//    system("pause");
//    return 0;
//}

//// ������ 5: �������, ����������� ������ ������� � �������� ���������
//
//#include <iostream>
//#include <vector>
//#include <functional> // ��� ������������� std::function
//
//// ������� ��� ������� ��������� ��������
//// ��������� ��� ����� � ������� ��� ������� ���������
//double calculateDeliveryCost(double weight, std::function<double(double)> costFunction) {
//    return costFunction(weight); // �������� ���������� ������� � ����� �����
//}
//
//// ������� ������� ��������� ����������� ��������
//// �������� ��� �� 5.0 (��������� �� �� ��� ����������� ��������)
//double standardDelivery(double weight) {
//    return weight * 5.0; // ���������� ��������� ��������
//}
//
//// ������� ������� ��������� ��������-��������
//// �������� ��� �� 10.0 (��������� �� �� ��� ��������-��������)
//double expressDelivery(double weight) {
//    return weight * 10.0; // ���������� ��������� ��������
//}
//
//int main() {
//    // ������ � ������ ������ (� ��)
//    std::vector<double> cargoWeights = { 10.0, 20.0, 5.0, 15.0 };
//
//    setlocale(0, "");
//    std::string surname = "��������";
//
//    // ����� ��������� �������� ��� ������������ ��������
//    std::cout << surname << ": ��������� �������� (�����������):" << std::endl;
//    for (double weight : cargoWeights) {
//        // ����� ������� calculateDeliveryCost � ����� � ����������� ��������
//        double cost = calculateDeliveryCost(weight, standardDelivery);
//
//        // ����� ���� ����� � ��������� ��� ��������
//        std::cout << "���: " << weight << " ��, ���������: " << cost << " ���." << std::endl;
//    }
//
//    // ����� ��������� �������� ��� �������� ��������
//    std::cout << "\n��������� �������� (�������):" << std::endl;
//    for (double weight : cargoWeights) {
//        // ����� ������� calculateDeliveryCost � ����� � �������� ��������-��������
//        double cost = calculateDeliveryCost(weight, expressDelivery);
//
//        // ����� ���� ����� � ��������� ��� ��������
//        std::cout << "���: " << weight << " ��, ���������: " << cost << " ���." << std::endl;
//    }
//
//    system("pause");
//    return 0;
//}

//// ������ 6: �������, ������������ ������ �������
//
//#include <iostream>
//#include <functional> // ���������� ��� ������������� std::function
//
//using namespace std; // ������������� ������������ ���� std ��� ��������
//
//// �������, ������� ���������� ������ ������� ��� ������� ��������� ��������
//function<double(double)> createDeliveryCostCalculator(double baseRate, double perKmRate) {
//    // ������������ �������, ����������� ���������� � �������������� ���������
//    return [baseRate, perKmRate](double distance) {
//        // ������ ��������� ��������: ������� ������ + ������ �� �������� * ����������
//        return baseRate + (perKmRate * distance);
//        };
//}
//
//int main() {
//    // ��������� ������� ��� ������ ����� ��������
//    // ����������� ��������: ������� ������ 5, 1 ����� �� ��������
//    auto standardDelivery = createDeliveryCostCalculator(5.0, 1.0);
//
//    setlocale(0, "");
//    string surname = "��������";
//
//    // ��������-��������: ������� ������ 10, 2 ����� �� ��������
//    auto expressDelivery = createDeliveryCostCalculator(10.0, 2.0);
//
//    // ���������� ��� �������� ����������, ���������� �������������
//    double distance;
//
//    // ������ � ������������ ���������� ��������
//    cout << "������� ���������� ��� �������� (� ��): ";
//    cin >> distance; // ������ ���������� � ����������
//
//    // ������ ��������� ����������� �������� ����� �������� ���������� � �������
//    double standardCost = standardDelivery(distance);
//
//    // ������ ��������� ��������-�������� ����� �������� ���������� � �������
//    double expressCost = expressDelivery(distance);
//
//    // ����� ��������� ����������� ��������
//    cout << surname << ": ��������� ����������� ��������: " << standardCost << " ���." << endl;
//
//    // ����� ��������� ��������-��������
//    cout << surname << ": ��������� ��������-��������: " << expressCost << " ���." << endl;
//
//    system("pause");
//    return 0;
//}

//// ������ 7: �������������� ���������������� �� ����������� �����������
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//
//// ������� ��� ��������, �������� �� ����� ������
//bool isEven(int number) {
//    return number % 2 == 0;
//}
//
//// ������� ��� �������� �����
//int doubleValue(int number) {
//    return number * 2;
//}
//
//// �������� �������
//int main() {
//    // �������� ������ �����
//    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    setlocale(0, "");
//    std::string surname = "��������";
//
//    // ���������� ������ �����
//    std::vector<int> evenNumbers;
//    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenNumbers), isEven);
//
//    // �������������� ������ ����� (��������)
//    std::vector<int> doubledEvenNumbers;
//    std::transform(evenNumbers.begin(), evenNumbers.end(), std::back_inserter(doubledEvenNumbers), doubleValue);
//
//    // ����� ����������
//    std::cout << surname << ": ������ �����, ���������: ";
//    for (int num : doubledEvenNumbers) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    system("pause");
//    return 0;
//}

// ������ 8: ������������� ������-������� ��� ���������� ������� �����������

#include <iostream>
#include <vector>
#include <algorithm> // ��� std::copy_if

// ��������� ��� ������������� ����������
struct Car {
    std::string name; // �������� ����������
    double weight; // ��� ���������� � �����������
};

int main() {
    // ������� ������ ����������� � �� ���������� � ������
    std::vector<Car> cars = {
        {"Toyota", 900},
        {"BMW", 1200},
        {"Honda", 950},
        {"Ford", 1100},
        {"Fiat", 800}
    };

    setlocale(0, "");
    std::string surname = "��������";

    // ������ ��� �������� ��������������� �����������
    std::vector<Car> lightweightCars;

    // ���������� std::copy_if ��� ���������� �����������
    std::copy_if(cars.begin(), cars.end(), std::back_inserter(lightweightCars),
        // ������-������� ��� �������� ������� ����������
        [](const Car& car) { return car.weight < 1000; });

    // ����� ����������� ���������������� ������ �����������
    std::cout << surname << ": ������ � ����� ����� 1 �����:" << std::endl;
    for (const auto& car : lightweightCars) {
        std::cout << car.name << " (���: " << car.weight << " ��)" << std::endl;
    }

    system("pause");
    return 0;
}