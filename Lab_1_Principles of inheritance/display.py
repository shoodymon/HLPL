from management_system import CarpetItem


def display_all_carpets(carpets, size):
    print("\n========= Информация о коврах =========")
    for i in range(size):
        if carpets[i] is not None:
            print(f"Ковер #{i + 1}:")
            carpets[i].show_details()
            print()
    print(f"Общее количество ковров: {CarpetItem.get_total_carpets()}")
    print("=======================================")