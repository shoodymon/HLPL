using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DB_MVVM.Model
{
    public class Room
    {
        public int RoomCode { get; set; }
        public int Number { get; set; }
        public int TypeCode { get; set; }
        public int Floor { get; set; }
        public int? WindowCount { get; set; }
    }
}
