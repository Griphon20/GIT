// See https://aka.ms/new-console-template for more information

using System;
using System.Security.Cryptography;
using HomeWork1;


class Program
{
    public static void Main()
    {
        Console.WriteLine(RomanNumber.Add(new RomanNumber(20), new RomanNumber(10)));
        Console.WriteLine(RomanNumber.Sub(new RomanNumber(20), new RomanNumber(10)));
        Console.WriteLine(RomanNumber.Mul(new RomanNumber(20), new RomanNumber(10)));
        Console.WriteLine(RomanNumber.Div(new RomanNumber(20), new RomanNumber(10)));
        RomanNumber[] romanNumberArray = new RomanNumber[10];
        for (int i = 0; i < 10; i++)
        {
            romanNumberArray[i] = new RomanNumber((ushort)(new Random().Next(1, 1000)));
            Console.Write(romanNumberArray[i] + " ");
        }
        Console.WriteLine();

        Array.Sort(romanNumberArray);
        
        for (int i = 0; i < 10; i++)
        {
            Console.Write(romanNumberArray[i] + " ");
        }


    }
}