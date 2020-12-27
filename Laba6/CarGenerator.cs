using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba6
{
    class CarGenerator
    {
        private static Random rand = new Random();
        public static List<Car> GenerateCars(int amount)
        {
            List<Car> cars = new List<Car>(amount);
            for (int i = 0; i < amount; ++i)
            {
                string number = GenerateNumber();
                string brand = GenerateBrand();
                string color = GenerateColor();
                cars.Add(new Car(number, brand, color));
            }
            return cars;
        }

        private static string GenerateColor()
        {
            string[] colors = new string[]
            {   "Aqua", 
                "Blue",
                "White",
                "Silver",
                "Black",
                "Grey", 
                "Red",
                "Brown",
                "Green",
            };
            return colors[rand.Next(0, colors.Length)];

        }

        private static string GenerateBrand()
        {
            string[] brands = new string[]
            {
                "Audi",
                "Alfa Romeo",
                "BMW",
                "Cadillac",
                "Chery",
                "Chevrolet",
                "Chrysler",
                "Citroen",
                "Dodge",
                "Ferrari",
                "Fiat",
                "Ford",
                "Honda",
                "Hyundai",
                "Infiniti",
                "Jaguar",
                "Jeep",
                "Kia",
                "Lamborghini",
                "Land Rover",
                "Lexus",
                "Lotus",
                "Maserati",
                "Mazda",
                "Mercedes",
                "Mitsubishi",
                "Nissan",
                "Opel",
                "Peugeot",
                "Pontiac",
                "Porsche",
                "Renault",
                "Skoda",
                "Toyota",
                "VAZ",
                "Volkswagen",
                "Volvo",
            };
            return brands[rand.Next(0, brands.Length)];
        }

        private static string GenerateNumber()
        {
            
            string number = "";
            number += (char)rand.Next('a', 'z' + 1);
            number += (char)(rand.Next('0', '9' + 1));
            number += (char)(rand.Next('0', '9' + 1));
            number += (char)(rand.Next('0', '9' + 1));
            number += (char)rand.Next('a', 'z' + 1);
            number += (char)rand.Next('a', 'z' + 1);
            if (rand.Next(0,2) == 0)
            {
                number += (char)(rand.Next('0', '9' + 1));
                number += (char)(rand.Next('0', '9' + 1));
            }
            else
            {
                number += (char)(rand.Next('1', '9' + 1));
                number += (char)(rand.Next('0', '9' + 1));
                number += (char)(rand.Next('0', '9' + 1));
            }

            return number;
        }
    }
}
