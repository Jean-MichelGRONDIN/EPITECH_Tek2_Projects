/*
** EPITECH PROJECT, 2020
** ex05
** File description:
** ex05
*/

#ifndef EX05_H_
#define EX05_H_

typedef union foo {
    struct one {
        short foo;
        union two {
            short foo;
            short bar;
        } bar;
    } foo;
    int bar;
} foo_t;

#endif /* !EX05_H_ */