/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** main
*/

int strace(int ac, char **av, char **env);

int main(int ac, char **av, char **env)
{
    return (strace(ac, av, env));
}