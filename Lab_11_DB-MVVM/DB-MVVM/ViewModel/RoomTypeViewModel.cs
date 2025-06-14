using DB_MVVM.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DB_MVVM.ViewModel
{
    public class RoomTypeViewModel : ViewModelBase
    {
        private RoomType _roomType;

        public RoomTypeViewModel()
        {
            _roomType = new RoomType();
        }

        public RoomType RoomType
        {
            get => _roomType;
            set
            {
                _roomType = value;
                OnPropertyChanged(nameof(RoomType));
            }
        }

        public string Type
        {
            get => _roomType.Type;
            set
            {
                _roomType.Type = value;
                OnPropertyChanged(nameof(Type));
            }
        }

        public decimal Price
        {
            get => _roomType.Price;
            set
            {
                _roomType.Price = value;
                OnPropertyChanged(nameof(Price));
            }
        }

        public void Validate()
        {
            if (string.IsNullOrWhiteSpace(RoomType.Type))
                throw new ArgumentException("Тип комнаты обязателен");

            if (RoomType.Price <= 0)
                throw new ArgumentException("Цена должна быть положительным числом");
        }
    }
}
