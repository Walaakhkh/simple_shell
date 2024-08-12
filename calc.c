#include <stdio.h>
#include <stdlib.h>

/**
 * main - A simple calculator that performs basic arithmetic operations
 * @argc: Argument count
 * @argv: Argument vector (array of strings)
 *
 * Description: This program accepts three command-line arguments:
 * a number, an operator (+, -, *, /), and another number.
 * It then performs the requested operation and prints the result.
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	char operator;
	int result;

	if (argc != 4)
	{
	printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
	return (EXIT_FAILURE);
	}

	num1 = atoi(argv[1]);
	operator = argv[2][0];
	num2 = atoi(argv[3]);

	switch (operator)
	{
	case '+':
	result = num1 + num2;
	break;
	case '-':
	result = num1 - num2;
	break;
	case '*':
	result = num1 * num2;
	break;
	case '/':
	if (num2 == 0)
	{
	printf("Error: Division by zero\n");
	return (EXIT_FAILURE);
	}
	result = num1 / num2;
	break;
	default:
	printf("Error: Unsupported operator '%c'\n", operator);
	return (EXIT_FAILURE);
	}

	printf("%d %c %d = %d\n", num1, operator, num2, result);
	return (EXIT_SUCCESS);
}
