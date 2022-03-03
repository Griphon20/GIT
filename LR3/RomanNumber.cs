using System;

namespace LR3
{
    public class RomanNumber : ICloneable, IComparable
    {
        private readonly ushort number;

        public RomanNumber(ushort n)
        {
            if (n <= 0 || n >= 4000)
            {
                throw new RomanNumberException();
            }
            number = n;
        }
        public static RomanNumber operator +(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 is null || n2 is null) throw new RomanNumberException();
            return new RomanNumber((ushort)(n1.number + n2.number));
        }
        public static RomanNumber operator -(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 is null || n2 is null) throw new RomanNumberException();
            if (n1.number <= n2.number) throw new RomanNumberException();
            return new RomanNumber((ushort)(n1.number - n2.number));
        }
        public static RomanNumber operator *(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 is null || n2 is null) throw new RomanNumberException();
            return new RomanNumber((ushort)(n1.number * n2.number));
        }
        public static RomanNumber operator /(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 is null || n2 is null) throw new RomanNumberException();
            if (
                n1.number % n2.number == 0 &&
                n1.number >= n2.number
            )
            {
                return new RomanNumber((ushort)(n1.number / n2.number));
            }
            else
            {
                throw new RomanNumberException();
            }
        }
        public override string ToString()
        {
            return toRoman(number);
        }
        private static string toRoman(int number)
        {
            if (number < 1) return string.Empty;
            if (number >= 1000) return "M" + toRoman(number - 1000);
            if (number >= 900) return "CM" + toRoman(number - 900);
            if (number >= 500) return "D" + toRoman(number - 500);
            if (number >= 400) return "CD" + toRoman(number - 400);
            if (number >= 100) return "C" + toRoman(number - 100);
            if (number >= 90) return "XC" + toRoman(number - 90);
            if (number >= 50) return "L" + toRoman(number - 50);
            if (number >= 40) return "XL" + toRoman(number - 40);
            if (number >= 10) return "X" + toRoman(number - 10);
            if (number >= 9) return "IX" + toRoman(number - 9);
            if (number >= 5) return "V" + toRoman(number - 5);
            if (number >= 4) return "IV" + toRoman(number - 4);
            if (number >= 1) return "I" + toRoman(number - 1);
            throw new RomanNumberException();
        }

        public object Clone()
        {
            return new RomanNumber(number);
        }

        public int CompareTo(object obj)
        {
            if (obj is RomanNumber num) return number.CompareTo(num.number);
            else throw new RomanNumberException("Некорректное значение аргумента");
        }

    }
}