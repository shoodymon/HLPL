using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DB_MVVM.Model
{
    public class Entry
    {
        public int EntryCode { get; set; }
        public int ClientCode { get; set; }
        public int RoomCode { get; set; }
        public DateTime CheckInDate { get; set; }
        public DateTime? CheckOutDate { get; set; }
    }
}
