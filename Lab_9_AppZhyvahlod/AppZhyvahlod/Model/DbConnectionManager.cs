using System;
using System.Configuration;
using System.Data.SqlClient;

namespace AppZhyvahlod.Model
{
    public class DbConnectionManager
    {
        private static string GetConnectionString()
        {
            return ConfigurationManager.ConnectionStrings["HotelDatabase"].ConnectionString;
        }

        public static SqlConnection GetConnection()
        {
            SqlConnection connection = new SqlConnection(GetConnectionString());
            return connection;
        }
    }
}