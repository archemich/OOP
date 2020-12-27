using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba6
{
    class DataStorage
    {
        public DataStorage()
        {
            Cars.AddRange(CarGenerator.GenerateCars(1000));
            Cars.ForEach(x =>
            {
                x.OnParked += OnParked_handler;
                x.OnUnparked += OnUnparked_handler;
            });
        }

        private void OnUnparked_handler(object sender, EventArgs e)
        {
            ParkedCars.Remove((Car)sender);

        }

        private void OnParked_handler(object sender, EventArgs e)
        {
            ParkedCars.Add((Car)sender);
        }

        public static List<Car> Cars { get; private set; } = new List<Car>();
        public static List<Car> ParkedCars { get; } = new List<Car>();
        
    };
}
