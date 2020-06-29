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
        private const string cmdFormat = "year month date year month date";

        static void Main(string[] args)
        {
            DateTime time1;
            DateTime time2;

            try
            {
                switch (args.Length)
                {
                    case 0:
                        /*Display info about the program*/
                        Console.WriteLine("Created in Canada by Weston McNamara.");
                        Console.WriteLine($"Format: {cmdFormat}");
                        Console.WriteLine("You can use the word \"today\" instead of typing it out.");
                        Console.WriteLine("");
                        Console.WriteLine($"Example: deltat 2020 06 20 2020 03 10");
                        Console.WriteLine($"Example: deltat today 2001 06 17");
                        return;
                    case 4:
                        /*Today and a date*/
                        if (args[0] != "today")
                        {
                            Console.WriteLine($"Argument {args[0]} is invalid.");
                            return;
                        }

                        time1 = DateTime.Today;
                        time2 = new DateTime(Int32.Parse(args[1]), Int32.Parse(args[2]), Int32.Parse(args[3]));
                        break;
                    case 6:
                        //Get numbers from the command line arguments
                        time1 = new DateTime(Int32.Parse(args[0]), Int32.Parse(args[1]), Int32.Parse(args[2]));
                        time2 = new DateTime(Int32.Parse(args[3]), Int32.Parse(args[4]), Int32.Parse(args[5]));
                        break;
                    default:
                        /*Error*/
                        Console.WriteLine($"Incorrect arguments. Please use this format: {cmdFormat}");
                        Console.WriteLine($"Example: 2020 06 20 2020 03 10");
                        return;

                }
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
