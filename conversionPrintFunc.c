#include "main.h"

/**
 * printfChar - function that  prints a char
 * Description: this function prints a character. It takes a list
 * of arguments, a buffer for printing, and various
 * formatting parameters such as flags, width, precision,
 * and size.The function retrieves the character from
 * the argument list and delegates the printing task to
 * handleWriteChar. The return value is the number of
 * bytes or characters printed.
 * @listType: a list a of arguments
 * @buffer: a buffer array to handle print
 * @flags:  to calculates active flags
 * @width: to get the width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of bytes or characters printed
 */

int printfChar(va_list listType, char buffer[], int flags, int width,
		int precision, int size)
{
char ch = va_arg(listType, int);
return (handleWriteChar(ch, buffer, flags, width, precision, size));
}

/**
 * printfString - function that prints a string
 *
 * Description: this function prints a string, handling formatting
 * options such as width, precision, and alignment flags
 * It calculates the length, considers special cases for
 * NULL strings, and prints the formatted string
 *
 * @listType: a list of arguments
 * @buffer: the buffer array to handle print
 * @flags:  to calculates active flags
 * @width: to get the width.
 * @precision: the precision specification
 * @size: the size specifier
 *
 * Return: the number of characters printed.
 */

int printfString(va_list listType, char buffer[], int flags, int width,
		int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(listType, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

/**
 * printfPercentSign - function that prints a percent sign
 *
 * Description: this function prints a percent sign ("%").
 * It ignores formatting parameters and directly writes the
 * percent sign to the output.
 *
 * @listType: a list of arguments
 * @buffer: the buffer array to handle print
 * @flags:  to calculates active flags
 * @width: to get the width.
 * @precision: the precision specification
 * @size: the size specifier
 *
 * Return: the number of bytes or characters printed
 */

int printfPercentSign(va_list listType, char buffer[], int flags, int width,
		int precision, int size)
{
	UNUSED(listType);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * printfInteger - function that prints an integer number
 * Description: this function prints an integer with specified formatting
 * options. It converts the input number, processes digits,
 * and utilizes writeNumber for printing. The return is
 * the count of characters printed.
 * @listType: a list of arguments
 * @buffer: buffer array to handle print
 * @flags:  to calculates active flags
 * @width: get the  width.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of characters printed
 */

int printfInteger(va_list listType, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int isNegative = 0;
	long int numbers = va_arg(listType, long int);
	unsigned long int num;

	numbers = convertSizeNumber(numbers, size);
	if (numbers == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)numbers;
	if (numbers < 0)
	{
		num = (unsigned long int)((-1) * numbers);
		isNegative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (writeNumber(isNegative, i, buffer, flags, width,
				precision, size));
}

/**
 * printfUnsigned - function that prints an unsigned number
 *
 * Description: this function prints an unsigned number, handling
 * various formatting options such as width, precision, and flags.
 * It converts the input number, processes each digit, and
 * delegates the printing task to writeUnsigned function.
 *
 * @listType: a list a of arguments
 * @buffer: buffer array to handle print
 * @flags:  to calculates active flags
 * @width: to get the width
 * @precision: the precision specification
 * @size: the size specifier
 *
 * Return: the number of bytes or characters printed
 */

int printfUnsigned(va_list listType, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(listType, unsigned long int);

	num = convertSizeUnsignd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (writeUnsignd(0, i, buffer, flags, width, precision, size));
}
