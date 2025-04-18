/*
FONTE: becrowd
*/

/*

Read 3 double numbers (A, B and C) representing the sides of a triangle and arrange them 
in decreasing order, so that the side A is the biggest of the three sides. 
Next, determine the type of triangle that they can make, 
based on the following cases always writing an appropriate message:

if A ≥ B + C, write the message: NAO FORMA TRIANGULO
if A2 = B2 + C2, write the message: TRIANGULO RETANGULO
if A2 > B2 + C2, write the message: TRIANGULO OBTUSANGULO
if A2 < B2 + C2, write the message: TRIANGULO ACUTANGULO
if the three sides are the same size, write the message: TRIANGULO EQUILATERO
if only two sides are the same and the third one is different, write the message: TRIANGULO ISOSCELES




Input
The input contains three double numbers, A (0 < A) , B (0 < B) and C (0 < C).

Output
Print all the classifications of the triangle presented in the input.

Input Samples	O
7.0 5.0 7.0

Output Samples
TRIANGULO ACUTANGULO
TRIANGULO ISOSCELES


Input Samples
6.0 6.0 10.0

Output Samples
TRIANGULO OBTUSANGULO
TRIANGULO ISOSCELES


Input Samples
6.0 6.0 6.0

Output Samples
TRIANGULO ACUTANGULO
TRIANGULO EQUILATERO


Input Samples
5.0 7.0 2.0

Output Samples
NAO FORMA TRIANGULO


Input Samples
6.0 8.0 10.0

Output Samples
TRIANGULO RETANGULO
*/