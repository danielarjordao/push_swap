/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:15:48 by marvin            #+#    #+#             */
/*   Updated: 2024/07/14 14:48:27 by dramos-j         ###   ########.fr       */
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

    current = stack->current; // Inicia a partir do currento da pilha
    while (current) // Enquanto houver nós na pilha
    {
        if (current->content == num) // Se o número for repetido
            return (1); // É um número repetido
        current = current->next; // Avança para o próximo nó da pilha
    }
    return (0); // Se o loop terminar, não é um número repetido
}

// Função para contar o número de argumentos
int count_args(char **argv)
{
    int i;

    i = 0;
    while (argv[i]) // Enquanto houver argumentos
        i++; // Conta o argumento
    return (i); // Retorna o número de argumentos
}

// Função para verificar se os argumentos são válidos
int check_args(int argc, char **argv, t_stack *stack)
{
    int flag; // Se houver flag, deve ser considerado o primeiro argumento, pois após o split argv[0] não é mais o nome do programa

    flag = 0; 
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        argc = count_args(argv);
        flag = 1; 
    }
    argc--; // Decrementa o número de argumentos
    while (argc > 0) // Enquanto i for menor que o número de argumentos
    {
        if (!is_integer(argv[argc])) // Se o argumento não for um número inteiro
            return (0); // Argumento inválido
        if (is_duplicate(stack, ft_atoi(argv[argc]))) // Se o número for repetido
            return (0); // Argumento inválido
        push(stack, ft_atoi(argv[argc])); // Adiciona o número à pilha
        argc--; // Avança para o próximo argumento
    }
    if (flag) // Se houver flag, adiciona o primeiro argumento à pilha
        push(stack, ft_atoi(argv[0])); 
    return (1); // Se o loop terminar, os argumentos são válidos
}