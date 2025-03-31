// Подключаем пространство имен для работы с событиями изменения свойств
using System.ComponentModel;

namespace AppZhyvahlod.ViewModel
{
    // Класс BaseViewModel реализует интерфейс INotifyPropertyChanged
    // Он служит базовым классом для других моделей представления, обеспечивая уведомления об изменениях свойств
    public class BaseViewModel : INotifyPropertyChanged
    {
        // Событие, которое срабатывает при изменении свойства
        public event PropertyChangedEventHandler PropertyChanged;

        // Метод для вызова события изменения свойства
        protected void OnPropertyChanged(string propertyName = null)
        {
            // Проверяем, есть ли подписчики на событие PropertyChanged
            // Если есть, вызываем событие, передавая информацию об измененном свойстве
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }

}
