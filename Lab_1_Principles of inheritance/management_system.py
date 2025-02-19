from abc import ABC, abstractmethod

class ICarpet(ABC):
    @abstractmethod
    def get_information(self):
        pass

class CarpetItem(ICarpet):
    total_carpets = 0  # статическая переменная для учета общего количества ковров

    def __init__(self, name="", carpet_size=0.0, price=0.0):
        self._name = name
        self._carpet_size = carpet_size
        self._price = price
        CarpetItem.total_carpets += 1

    def __del__(self):
        CarpetItem.total_carpets -= 1

    def __copy__(self):
        new_instance = type(self)()
        new_instance.__dict__.update(self.__dict__)
        return new_instance

    @abstractmethod
    def show_details(self):
        pass

    def update_price(self, amount):
        self._price += amount

    @staticmethod
    def get_total_carpets():
        return CarpetItem.total_carpets

    def get_information(self):
        print(f"Клиент: {self._name}, Размер ковра: {self._carpet_size} кв.м, Цена: {self._price} руб.")

    # Геттеры
    def get_name(self):
        return self._name

    def get_carpet_size(self):
        return self._carpet_size

    def get_price(self):
        return self._price

    # Сеттеры
    def set_name(self, new_name):
        self._name = new_name

    def set_carpet_size(self, new_size):
        self._carpet_size = new_size

    def set_price(self, new_price):
        self._price = new_price


class WoolCarpet(CarpetItem):
    def __init__(self, name="", carpet_size=0.0, price=0.0, wool_type="none"):
        super().__init__(name, carpet_size, price)
        self._wool_type = wool_type

    def show_details(self):
        print("=== Шерстяной ковер ===")
        self.get_information()
        print("========================")

    def get_information(self):
        super().get_information()
        print(f"Тип шерсти: {self._wool_type}")

    # Геттер и сеттер
    def get_wool_type(self):
        return self._wool_type

    def set_wool_type(self, new_wool_type):
        self._wool_type = new_wool_type


class SyntheticCarpet(CarpetItem):
    def __init__(self, name="", carpet_size=0.0, price=0.0, material="none"):
        super().__init__(name, carpet_size, price)
        self._material = material

    def show_details(self):
        print("=== Синтетический ковер ===")
        self.get_information()
        print("============================")

    def get_information(self):
        super().get_information()
        print(f"Материал: {self._material}")

    # Геттер и сеттер
    def get_material(self):
        return self._material

    def set_material(self, new_material):
        self._material = new_material