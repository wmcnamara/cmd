using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Management;

namespace WestMac
{
    class Program
    {
        private const string cmdFormat = "YEAR MONTH DAY YEAR MONTH DAY";

        static void Main(string[] args)
        {
            //Display info about program.
            if (args.Length == 0)
            {
                Console.WriteLine("Created in Canada by Weston McNamara.");
                Console.WriteLine($"Format: {cmdFormat}");
                Console.WriteLine($"Example: deltat 2020 06 20 2020 03 10");
                return;
            }

            //If arguments are wrong
            if (args.Length != 6)
            {
                Console.WriteLine($"Incorrect arguments. Please use this format: {cmdFormat}");
                Console.WriteLine($"Example: 2020 06 20 2020 03 10");
                return;
            }

            DateTime time1;
            DateTime time2;

            try
            {
                //Get numbers from the command line arguments
                time1 = new DateTime(Int32.Parse(args[0]), Int32.Parse(args[1]), Int32.Parse(args[2]));
                time2 = new DateTime(Int32.Parse(args[3]), Int32.Parse(args[4]), Int32.Parse(args[5]));
            }
            catch (System.FormatException)
            {
                //If the format is incorrect, return.
                Console.WriteLine($"Incorrect arguments.");
                Console.WriteLine($"Proper Example: 2020 06 20 2020 03 10");
                return;
            }
            catch (System.ArgumentOutOfRangeException)
            {
                //If the format is incorrect, return.
                Console.WriteLine($"Invalid Date.");
                Console.WriteLine($"Proper Example: 2020 06 20 2020 03 10");
                return;
            }
            //This should never be thrown. If it is, the exception it threw should be added to a catch block.
            catch (System.Exception e)
            {
                Console.WriteLine($"Exception Thrown {e}");
                return;
            }

            //Calculate delta and display it.
            TimeSpan delta = time1 - time2;
            Console.WriteLine($"Difference: {delta.Days} days");
            Console.WriteLine($"Difference: {delta.Days / 7} weeks");
        }
    }
}
