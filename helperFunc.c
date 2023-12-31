#include "main.h"

/**
 * convertSizeUnsignd - function that casts a number to the specified size
 *
 * Description: this function cast a number to the specified size
 * It return the casted value of the input number.
 *
 * @num: the number to be casted
 * @size: the number indicating the type to be casted
 *
 * Return: Casted value of num
*/
long int convertSizeUnsignd(unsigned long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);


	return ((unsigned int)num);
}

/**
 * isDigit - function that checks if a char is a digit
 *
 * Description: this function checks if a characters is a digit (0-9).
 *
 * @ch: Char to be evaluated.
 *
 * Return: true if ch is a digit, false otherwise
*/
bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * isPrintable - function that evaluates if a char is printable or not
 *
 * Description: checks if a characters is printable
 * (ASCII value between 32 and 127).
 *
 * @ch: Char to be evaluated.
 *
 * Return: true of ch is printable, false otherwise.
*/
bool isPrintable(char ch)
{
	return (ch >= 32 && ch < 127);
}

/**
 * appendHexaCode - this function append ascci in hexadecimal code to buffer.
 *
 * Description: this function appends the ASCII code.
 * in hexadecimal to a character array at the given index.
 * It return 3, representing the number of charaters appended.
 *
 * @buffer: an array of characters.
 * @ind: Index at which to start appending.
 * @asciiCode: the ASCII CODE.
 *
 * Return: Always 3.
*/
int appendHexaCode(char asciiCode, char buffer[], int ind)
{
	char mapto[] = "0123456789ABCDEF";

	if (asciiCode < 0)
		asciiCode *= -1;
	buffer[ind++] = '\\';
	buffer[ind++] = 'x';
	buffer[ind++] = mapto[asciiCode / 16];
	buffer[ind] = mapto[asciiCode % 16];
	return (3);
}

/**
 * convertSizeNumber - function that casts a number to the specified size
 *
 * Description: this function cast a number to the specified size
 * It return the casted value of the input number.
 *
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num.
*/
long int convertSizeNumber(long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((short)num);

	return ((int)num);
}
