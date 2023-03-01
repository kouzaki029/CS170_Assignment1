# CS170_Assignment1

1) 
Write a program to calculate the number of days between two dates. Each date is represented by three integers: day, month, and year. Validate the user input and if it is invalid, ask the user to enter again. If user enters three times an invalid day or month, announce that the program will exit and exit the program. Use the following rules for determining leap years: A leap year is one whose number is exactly divisible by four.  Century years, however, are only leap years if they are exactly divisible by 400. Hence 1900 was not a leap year but 2000 was. Your program should not use arrays or vectors. 



2) 
The game of Nim. Two players alternately take marbles from a pile. In each move, a player chooses how many marbles to take. The player must take at least one, but at most half of the marbles. Then the other player takes a turn. The player who takes the last marble looses. 

Write a program in which the computer plays against a human opponent. The computer can play in two modes: smart or stupid. In stupid mode, the computer simply takes a random legal value (between 1 and half of the marbles) from the pile whenever it has a turn. In smart mode the computer takes off enough marbles to make the size of the pile a power of two minus 1 (that is 3, 7, 15, 63, etc.). That is always a legal move, except if the size of the pile is currently one less than a power of 2. In that case, the computer makes a random legal move. (Note that the computer cannot be beaten in smart mode when it has the first move unless the pile size happens to be a power of 2 minus 1. Of course, a human player who has the first turn and knows the winning strategy can win against the computer.)

Minimum requirements: ask the user to enter the initial size of the pile between 10 and 100, to decide who has the first turn, and to decide whether the computer plays in stupid or smart mode. Then play the game accordingly.



3) 
Credit card number check.  The last digit of a credit card number is the check digit, which protects again transcription errors such as an error in a single digit or switching two digits. The following method is used to verify actual credit card numbers, but for simplicity we will describe it for 8 digits instead of 16:
•	Starting from the rightmost digit, calculate the sum of every other digit. For example, if the credit card number is 43589795, then you form the sum 5 + 7 + 8 + 3 = 23.
•	Double all the digits that were not included in the preceding step. For example, with the number give above you double the digits 9, 9, 5, and 4, which yield 18, 18, 10, and 8. Adding all the digits in these numbers gives 1+8+1+8+1+0+8 = 27.
•	Add the sums of the two preceding steps. If the last digit of the result is 0, the number is valid. In our example, 23 + 27 = 50, so the number is valid.
Write a program that implements this algorithm. Do not use arrays or vectors. Do not use a string representation of numbers.  The user should supply a number (not individual digits, but a single number with any number of digits that you can store in a variable of type long), and you should print out whether the number is valid or not.  Suggested extension: also print the value of the check digit that would make the number valid.

