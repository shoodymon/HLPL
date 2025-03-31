// Подключаемые пространства имен:
// Указывают, какие библиотеки и классы используются в этом файле.
using System;
using System.Windows.Input; // Для работы с интерфейсом ICommand


namespace AppZhyvahlod.ViewModel
{
    // Класс RelayCommand реализует интерфейс ICommand
    // Он позволяет связывать действия (команды) с пользовательским интерфейсом
    public class RelayCommand : ICommand
    {
        private readonly Action _execute; // Действие, которое будет выполнено при вызове команды
        private readonly Func<bool> _canExecute; // Функция, определяющая, может ли команда выполниться

        // Событие, которое вызывается при изменении возможности выполнения команды
        public event EventHandler CanExecuteChanged;

        // Конструктор класса RelayCommand
        // Принимает действие для выполнения и функцию проверки возможности выполнения
        public RelayCommand(Action execute, Func<bool> canExecute = null)
        {
            _execute = execute; // Инициализация действия
            _canExecute = canExecute; // Инициализация функции проверки возможности выполнения
        }

        // Метод для проверки, может ли команда выполниться
        public bool CanExecute(object parameter)
        {
            // Если функция проверки не задана, команда может выполняться
            // Если задана, вызываем её для проверки
            return _canExecute == null || _canExecute();
        }

        // Метод для выполнения команды
        public void Execute(object parameter)
        {
            _execute(); // Вызываем действие, связанное с командой
        }

        // Метод для вызова события CanExecuteChanged
        // Позволяет обновить состояние команды в пользовательском интерфейсе
        public void RaiseCanExecuteChanged()
        {
            CanExecuteChanged?.Invoke(this, EventArgs.Empty); // Вызываем событие, если есть подписчики
        }
    }

}
