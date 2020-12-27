using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba6
{
    abstract class Vehicle
    {
        public Vehicle(string num, string brand, string color)
        {
            Id = IdGen++;
            Number = num;
            Brand = brand;
            Color = color;
            
        }
        async public void Park()
        {
            ParkingTimeout = new Random().Next(60000,1800000);
            Parked = true;
            OnParked(this, new EventArgs());
            await Task.Delay(ParkingTimeout);
            Unpark();
        }
  
        async public void Unpark()
        {
            ParkingTimeout = new Random().Next(60000, 1800000);
            Parked = true;
            OnUnparked(this, new EventArgs());
            await Task.Delay(ParkingTimeout);
            Park();

        }
        

        public event EventHandler OnParked;
        public event EventHandler OnUnparked;


        protected static int IdGen { get; set; } = 0;
        public string Number { get; }
        public int Id { get; }
        public string Brand { get; }
        public string Color { get; set; }
        public int ParkingTimeout { get; set; } = 0;
        public bool Parked { get; protected set; } = false;
        

    }
}
