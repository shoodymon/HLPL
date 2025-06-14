using DB_MVVM.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DB_MVVM.ViewModel
{
    public class EntryViewModel : ViewModelBase
    {
        private Entry _entry;

        public EntryViewModel()
        {
            _entry = new Entry();
        }

        public Entry Entry
        {
            get => _entry;
            set
            {
                _entry = value;
                OnPropertyChanged(nameof(Entry));
            }
        }

        public DateTime CheckInDate
        {
            get => _entry.CheckInDate;
            set
            {
                _entry.CheckInDate = value;
                OnPropertyChanged(nameof(CheckInDate));
            }
        }

        public DateTime? CheckOutDate
        {
            get => _entry.CheckOutDate;
            set
            {
                _entry.CheckOutDate = value;
                OnPropertyChanged(nameof(CheckOutDate));
            }
        }

        public void Validate()
        {
            if (_entry.CheckInDate > DateTime.Now)
                throw new ArgumentException("Дата заезда не может быть в будущем");

            if (_entry.CheckOutDate.HasValue && _entry.CheckOutDate < _entry.CheckInDate)
                throw new ArgumentException("Дата выезда не может быть раньше даты заезда");
        }
    }
}
