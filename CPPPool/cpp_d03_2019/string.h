/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** string
*/

#ifndef DAY03_H_
#define DAY03_H_

#include <stdlib.h>
#include <string.h>

typedef struct string {
    char    *str;
    void  (*assign_s)(struct string *this, const  struct string *str);
    void  (*assign_c)(struct string *this, const  char *s);
    void  (*append_s)(struct string *this, const  struct string *ap);
    void  (*append_c)(struct string *this, const  char *ap);
    char (*at)(const  struct string *this, size_t  pos);
    void  (*clear)(struct string *this);
    int  (*size)(const  struct string *this);
    int  (*compare_s)(const  struct string *this, const  struct string *str);
    int  (*compare_c)(const  struct string *this, const  char *str);
    size_t  (*copy)(const  struct string *this,
        char *s, size_t n, size_t  pos);
    const  char *(*c_str)(const  struct string *this);
    int  (*empty)(const  struct string *this);
    int  (*find_s)(const  struct string *this,
        const  struct string *str, size_t  pos);
    int  (*find_c)(const  struct string *this, const  char *str, size_t  pos);
    void  (*insert_s)(struct string *this, size_t pos,
        const  struct string *str);
    void  (*insert_c)(struct string *this, size_t pos, const  char *str);
    int  (*to_int)(const  struct string *this);
} string_t;

void  string_init(string_t *this, const  char *s);
void  string_destroy(string_t *this);
void  assign_s(string_t *this, const  string_t *str);
void  assign_c(string_t *this, const  char *s);
void  append_s(string_t *this, const  string_t *ap);
void  append_c(string_t *this, const  char *ap);
char at(const  string_t *this, size_t  pos);
void  clear(string_t *this);
int  size(const  string_t *this);
int  compare_s(const  string_t *this, const  string_t *str);
int  compare_c(const  string_t *this, const  char *str);
size_t  copy(const  string_t *this, char *s, size_t n, size_t  pos);
const  char *c_str(const  string_t *this);
int  empty(const  string_t *this);
int  find_s(const  string_t *this, const  string_t *str, size_t  pos);
int  find_c(const  string_t *this, const  char *str, size_t  pos);
void  insert_s(string_t *this, size_t pos, const  string_t *str);
void  insert_c(string_t *this, size_t pos, const  char *str);
int  to_int(const  string_t *this);
string_t  **split_s(const  string_t *this, char  separator);
char **split_c(const  string_t *this, char  separator);

#endif