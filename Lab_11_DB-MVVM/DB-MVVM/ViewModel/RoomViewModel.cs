using DB_MVVM.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DB_MVVM.ViewModel
{
    public class RoomViewModel : ViewModelBase
    {
        private Room _room;

        public RoomViewModel()
        {
            _room = new Room();
        }

        public Room Room
        {
            get => _room;
            set
            {
                _room = value;
                OnPropertyChanged(nameof(Room));
            }
        }

        // Отдельные свойства с уведомлениями
        public int Number
        {
            get => _room.Number;
            set
            {
                _room.Number = value;
                OnPropertyChanged(nameof(Number));
            }
        }

        public int TypeCode
        {
            get => _room.TypeCode;
            set
            {
                _room.TypeCode = value;
                OnPropertyChanged(nameof(TypeCode));
            }
        }

        public int Floor
        {
            get => _room.Floor;
            set
            {
                _room.Floor = value;
                OnPropertyChanged(nameof(Floor));
            }
        }

        public int? WindowCount
        {
            get => _room.WindowCount;
            set
            {
                _room.WindowCount = value;
                OnPropertyChanged(nameof(WindowCount));
            }
        }

        public void Validate()
        {
            if (Room.Number <= 0)
                throw new ArgumentException("Номер комнаты должен быть положительным числом");

            if (Room.Floor <= 0)
                throw new ArgumentException("Номер этажа должен быть положительным числом");

            if (Room.WindowCount.HasValue && Room.WindowCount < 0)
                throw new ArgumentException("Количество окон не может быть отрицательным");
        }
    }
}
