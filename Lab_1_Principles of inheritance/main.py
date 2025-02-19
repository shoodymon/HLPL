from display import display_all_carpets
from management_system import WoolCarpet, SyntheticCarpet


def main():
    # 2.1. Создать массив указателей на тип CarpetItem размерностью 20.
    ARR_SIZE = 20
    arr_carpets = [None] * ARR_SIZE

    # 2.2. Добавить в массив информацию о трех шерстяных коврах и двух синтетических коврах.
    arr_carpets[0] = WoolCarpet("Иванов", 3.5, 2000.0, "овечья")
    arr_carpets[1] = WoolCarpet("Петров", 2.8, 1800.0, "альпака")
    arr_carpets[2] = WoolCarpet("Сидоров", 4.2, 2500.0, "мериносовая")
    arr_carpets[3] = SyntheticCarpet("Кузнецов", 3.0, 1500.0, "полиэстер")
    arr_carpets[4] = SyntheticCarpet("Смирнов", 2.5, 1200.0, "нейлон")

    # 2.4. Вывести информацию о всех коврах на экран.
    print("Первоначальная информация:")
    display_all_carpets(arr_carpets, ARR_SIZE)

    # 2.3. Заменить данные любого элемента массива.
    arr_carpets[1] = WoolCarpet("Новиков", 3.0, 2100.0, "кашемир")

    print("\nИнформация после замены элемента:")
    display_all_carpets(arr_carpets, ARR_SIZE)

    # 2.5. Увеличить цену за чистку для 1-го и 3-го ковров.
    arr_carpets[0].update_price(500.0)
    arr_carpets[2].update_price(300.0)

    # 2.6. Вывести информацию о всех коврах на экран.
    print("\nИнформация после увеличения цены для 1-го и 3-го ковров:")
    display_all_carpets(arr_carpets, ARR_SIZE)

    # 2.7. Увеличить цену за чистку для 5-го ковра.
    arr_carpets[4].update_price(200.0)

    # 2.8. Снова вывести информацию о коврах на экран.
    print("\nИнформация после увеличения цены для 5-го ковра:")
    display_all_carpets(arr_carpets, ARR_SIZE)

    # В Python сборщик мусора автоматически освобождает память,
    # но можно явно удалить ссылки на объекты, если нужно
    for i in range(ARR_SIZE):
        arr_carpets[i] = None

if __name__ == "__main__":
    main()