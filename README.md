ALX Software Engineering - Custom Printf Team Project

Project Description:
The team's project is to develop a custom printf function for the C programming language called _printf. This function serves as an optimized replacement for the standard library function printf, providing the ability to format and output data to stdout without relying on any standard library files. The _printf function utilizes a local buffer of 1024 bytes for printing but can handle larger datasets as well.

Function Signature:
int _printf(const char *format, ...);

Function Return:
The _printf function returns the total number of characters printed to stdout (excluding the null byte at the end of strings) after a successful execution. In case of an output error, it returns a negative value of -1.

Format of the Format String:
The format string is a character string enclosed within double quotes. It can consist of ordinary characters (not preceded by %) and conversion specifications, each denoted by a % followed by a conversion specifier.

Each conversion specification may contain (in this order):

Zero or more flags
An optional field width
An optional precision modifier
An optional length modifier
Flag Characters:

For o conversions, adds a prefix of "0" to the output string. For x and X conversions, adds "0x" or "0X" respectively to nonzero results.
0 (Not implemented yet) - Pads numeric conversions with zeros on the left. If both 0 and - flags are present, 0 is ignored. Precision overrides the 0 flag if provided with numeric conversions.
(Minus sign, not implemented yet) - Left-justifies the converted value on the field boundary, padding with blanks on the right. Overrides 0 if both are given.
' ' (Blank Space) - Pads the argument with a single blank space before positive numbers or empty strings produced by signed conversions.
Always places a sign (+ or -) before a number produced by a signed conversion. By default, only negative numbers have this sign.
Field Width:

An optional decimal digit string specifies the minimum field width. If the converted value has fewer characters than the field width, it will be padded accordingly with spaces on the left or right (based on the - flag).

Precision:

An optional precision, indicated by a period ('.'), followed by an optional decimal digit string. It specifies the minimum number of digits for certain conversions or the maximum number of characters to print from a string.

Length Modifiers:

l - Converts an integer to a long int or unsigned long int argument.
h - Converts an integer to a short int or unsigned short int argument.
Conversion Specifiers:

d, i - Converts the argument int to a signed decimal notation. Precision pads with zeros on the left if the converted value requires fewer digits.
o, u, x, X - Converts the argument to unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation. Precision pads with zeros on the left if required.
c - Converts the int argument to an unsigned char and writes the resulting character based on ASCII coding.
s - Expects a pointer type char * to an array of characters, prints characters up to (but not including) a null byte. Precision determines the number of characters to print.
p - Prints a void * pointer argument as hexadecimal in lowercase, representing an address in memory.
% - Writes a ' % ' character without performing any conversion (%%).
b - Converts the argument to an unsigned int value and prints its binary representation (base 2).
S - Expects a pointer type char * to an array of characters. Non-printable characters (ASCII value < 32 or >= 127) are printed as \x followed by the ASCII code value in hexadecimal (upper case - always 2 characters).
r - Expects a pointer type char * to an array of characters. Prints characters in reverse order up to (but not including) a null byte ('\0').
R - Expects a pointer type char * to an array of characters. Encodes characters to ROT13 and prints them in order up to (but not including) a null byte ('\0').
Author: Yassine Hachami
