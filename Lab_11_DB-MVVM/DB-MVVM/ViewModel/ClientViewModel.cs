using DB_MVVM.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace DB_MVVM.ViewModel
{
    public class ClientViewModel : ViewModelBase
    {
        private Client _client;

        public ClientViewModel()
        {
            _client = new Client();
        }

        public Client Client
        {
            get => _client;
            set
            {
                _client = value;
                OnPropertyChanged(nameof(Client));
            }
        }

        // Отдельные свойства с уведомлениями
        public string LastName
        {
            get => _client.LastName;
            set
            {
                _client.LastName = value;
                OnPropertyChanged(nameof(LastName));
            }
        }

        public string FirstName
        {
            get => _client.FirstName;
            set
            {
                _client.FirstName = value;
                OnPropertyChanged(nameof(FirstName));
            }
        }

        public string MiddleName
        {
            get => _client.MiddleName;
            set
            {
                _client.MiddleName = value;
                OnPropertyChanged(nameof(MiddleName));
            }
        }

        public string PassportNumber
        {
            get => _client.PassportNumber;
            set
            {
                _client.PassportNumber = value;
                OnPropertyChanged(nameof(PassportNumber));
            }
        }

        public void Validate()
        {
            // Базовая валидация данных клиента
            if (string.IsNullOrWhiteSpace(Client.LastName))
                throw new ArgumentException("Фамилия обязательна");

            if (string.IsNullOrWhiteSpace(Client.FirstName))
                throw new ArgumentException("Имя обязательно");

            if (string.IsNullOrWhiteSpace(Client.PassportNumber))
                throw new ArgumentException("Номер паспорта обязателен");

            // Дополнительная валидация формата паспорта (пример: 1234 567890)
            if (!Regex.IsMatch(Client.PassportNumber, @"^\d{4}\s?\d{6}$"))
                throw new ArgumentException("Неверный формат номера паспорта. Используйте формат: 1234 567890");
        }
    }
}
