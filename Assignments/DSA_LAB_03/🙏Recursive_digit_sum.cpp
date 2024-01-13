/*11 April, 2023
We define super digit of an integer  using the following rules:

Given an integer, we need to find the super digit of the integer.

If x has only 1 digit, then its super digit is x.
Otherwise, the super digit of  is equal to the super digit of the sum of the digits of x.
For example, the super digit of  will be calculated as:

	super_digit(9875)   	9+8+7+5 = 29 
	super_digit(29)     	2 + 9 = 11
	super_digit(11)		    1 + 1 = 2
	super_digit(2)	    	= 2 
    
Function Description:

Complete the function superDigit in the editor below. It must return the calculated 
super digit as an integer.

superDigit has the following parameter(s):
string n: a string representation of an integer
int k: the times to concatenate n to make p
    
Returns:
int: the super digit of n repeated k times

Input Format:
The first line contains two space separated integers, n and k.

Constraints:
1<=n<=10^100000
1<=k<=10^5
*/