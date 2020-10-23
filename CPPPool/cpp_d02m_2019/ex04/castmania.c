/*
** EPITECH PROJECT, 2020
** cpp_d02m_2019
** File description:
** castmania
*/

#include "castmania.h"
#include <stddef.h>
#include <stdio.h>

void  print_for_div(division_t *data)
{
    integer_op_t *integer = NULL;
    decimale_op_t *decimal = NULL;

    if (data->div_type == INTEGER) {
        integer = data->div_op;
        printf("%d\n", integer->res);
    } else {
        decimal = data->div_op;
        printf("%f\n", decimal->res);
    }
}

void  exec_operation(instruction_type_t  instruction_type, void *data)
{
    instruction_t *instruc = data;
    addition_t *addition = NULL;
    division_t *division = NULL;

    if (instruction_type == ADD_OPERATION) {
        addition = instruc->operation;
        exec_add(addition);
    } else {
        division = instruc->operation;
        exec_div(division);
    }
    if (instruc->output_type == VERBOSE) {
        if (instruction_type == ADD_OPERATION)
            printf("%d\n", addition->add_op.res);
        else
            print_for_div(division);
    }
}

void  exec_instruction(instruction_type_t  instruction_type, void *data)
{
    int *integer = 0;
    float *decimale = 0;

    if (instruction_type == PRINT_INT) {
        integer = data;
        printf("%d\n", *integer);
    } else if (instruction_type == PRINT_FLOAT) {
        decimale = data;
        printf("%f\n", *decimale);
    } else
        exec_operation(instruction_type, data);
}