using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Laba6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            DataStorage dataStorage = new DataStorage();

            InitializeComponent();
            DataStorage.Cars.ForEach(x => { x.Park(); });
            
            DataStorage.Cars.ForEach(x =>
            {
                x.OnParked += ReloadParkedListBox;
                x.OnUnparked += ReloadParkedListBox;
            });

            label15.Text = "Total: " + DataStorage.ParkedCars.Count.ToString();
            label16.Text = "Total: " + DataStorage.Cars.Count.ToString();

            parkedCarBox.DataSource = DataStorage.ParkedCars;
            parkedCarBox.DisplayMember = "Number";
            parkedCarBox.ValueMember = "Id";
            catchedCars.DataSource = DataStorage.Cars;
            catchedCars.DisplayMember = "Number";
            parkedCarBox.ValueMember = "Id";
           
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            

        }

        private void ReloadParkedListBox(object sender, EventArgs e)
        {
            parkedCarBox.DataSource = null;
            parkedCarBox.DataSource = DataStorage.ParkedCars;
            parkedCarBox.DisplayMember = "Number";
            parkedCarBox.ValueMember = "Id";
            label15.Text = "Total: " + DataStorage.ParkedCars.Count.ToString();

        }



        private void parkedCarBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            int carId = parkedCarBox.SelectedIndex;
            Car car = DataStorage.ParkedCars.Find(x=>x.Id == carId);
            if (car != null)
            {
                label5.Text = car.Brand;
                label6.Text = car.Color;
                label7.Text = car.Number;
            }
        }



        private void catchedCars_SelectedIndexChanged(object sender, EventArgs e)
        {
            int carId = catchedCars.SelectedIndex;
            Car car = DataStorage.Cars.Find(x => x.Id == carId);
            label10.Text = car.Brand;
            label11.Text = car.Color;
            label12.Text = car.Number;
        }
    }
}
