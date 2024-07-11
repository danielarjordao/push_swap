/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:15:48 by marvin            #+#    #+#             */
/*   Updated: 2024/07/11 15:15:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para verificar se um argumento é um número
int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+') // Se o primeiro caractere for um sinal
        i++; // Avança para o próximo caractere
    while (str[i]) // Enquanto houver caracteres na string
    {
        if (!ft_isdigit(str[i])) // Se o caractere não for um dígito
            return (0); // Não é um número
        i++; // Avança para o próximo caractere
    }
    return (1); // Se o loop terminar, é um número
}
// Função para verificar se um argumento é um número inteiro
int is_integer(char *str)
{
    long long num;

    if (!is_number(str)) // Se o argumento não for um número
        return (0); // Não é um inteiro
    num = ft_atoi(str); // Converte a string para um inteiro
    if (num > INT_MAX || num < INT_MIN) // Se o número estiver fora do intervalo de inteiros
        return (0); // Não é um inteiro válido
    return (1); // Se o número for um inteiro válido, é um inteiro
}

// Função para verificar se um argumento é um número repetido
int is_duplicate(t_stack *stack, int num)
{
    t_node  *current;

    current = stack->top; // Inicia a partir do topo da pilha
    while (current) // Enquanto houver nós na pilha
    {
        if (current->content == num) // Se o número for repetido
            return (1); // É um número repetido
        current = current->next; // Avança para o próximo nó da pilha
    }
    return (0); // Se o loop terminar, não é um número repetido
}

// Função para contar o número de palavras em um array de strings
int countwords(char **words)
{
    int i;

    i = 0;
    while (words[i]) // Enquanto houver palavras
        i++; // Incrementa o contador
    return (i); // Retorna o número de palavras
}

// Função para verificar se os argumentos são válidos
int check_args(int argc, char **argv, t_stack *stack)
{
    int i;

    i = 1;
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' '); // Separa os argumentos em palavras
        argc = countwords(argv); // Conta o número de palavras
        i = 0; // Inicia a partir do primeiro argumento
    }
    while (i < argc) // Enquanto houver argumentos
    {
        if (!is_integer(argv[i])) // Se o argumento não for um número inteiro
            return (0); // Argumento inválido
        if (is_duplicate(stack, ft_atoi(argv[i]))) // Se o número for repetido
            return (0); // Argumento inválido
        push(stack, ft_atoi(argv[i])); // Adiciona o número à pilha
        i++; // Avança para o próximo argumento
    }
    return (1); // Se o loop terminar, os argumentos são válidos
}