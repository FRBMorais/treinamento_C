/* FONTE:

Escreva um programa em C que realize as seguintes operações com um array de inteiros.
Na primeira linha, o programa recebe um inteiro que indica a quantidade de elementos no array.
Se a quantidade for zero ou negativa, exiba:
    Array vazio. Nenhum valor fornecido.
Caso contrário, o programa deverá:
  1. Encontrar e exibir o maior valor do array.
  2. Calcular e exibir a média dos elementos (apresentada com uma casa decimal).
  3. Verificar se o array é um palíndromo (ou seja, se a sequência de elementos é igual quando lida de trás para frente) e exibir:
       "Array é palíndromo." ou "Array não é palíndromo."
  4. Inverter os elementos do array e exibi-los.
  5. Encontrar e exibir o segundo maior valor do array (considerando valores distintos; se não houver, exiba "Segundo maior valor: N/A").
  6. Contar e exibir a quantidade de números pares e de números ímpares.

*/

/*
Input 001:
0

Expected Output 001:
Array vazio. Nenhum valor fornecido.
*/

/*
Input 002:
7
3 5 7 9 7 5 3

Expected Output 002:
Maior valor: 9
Média: 5.0
Array é palíndromo.
Array invertido: 3 5 7 9 7 5 3
Segundo maior valor: 7
Pares: 0
Ímpares: 7
*/

/*
Input 003:
10
0 -1 4 -5 7 8 -9 10 -2 3

Expected Output 003:
Maior valor: 10
Média: 0.7
Array não é palíndromo.
Array invertido: 3 -2 10 -9 8 7 -5 4 -1 0
Segundo maior valor: 8
Pares: 5
Ímpares: 5
*/

/*
Input 004:
5
100 90 80 70 60

Expected Output 004:
Maior valor: 100
Média: 80.0
Array não é palíndromo.
Array invertido: 60 70 80 90 100
Segundo maior valor: 90
Pares: 5
Ímpares: 0
*/

/*
Input 005:
8
42 42 42 42 42 42 42 42

Expected Output 005:
Maior valor: 42
Média: 42.0
Array é palíndromo.
Array invertido: 42 42 42 42 42 42 42 42
Segundo maior valor: N/A
Pares: 8
Ímpares: 0
*/

/*
Input 006:
9
-10 -5 0 5 10 5 0 -5 -10

Expected Output 006:
Maior valor: 10
Média: 0.0
Array é palíndromo.
Array invertido: -10 -5 0 5 10 5 0 -5 -10
Segundo maior valor: 5
Pares: 5
Ímpares: 4
*/
