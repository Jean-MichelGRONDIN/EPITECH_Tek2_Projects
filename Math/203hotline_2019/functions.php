<?php

include 'cmp_distributions.php';

function print_usage()
{
    printf("USAGE\n");
    printf("    ./203hotline [n k | d]\n\n");
    printf("DESCRIPTION\n");
    printf("    n     n value for the computation of C(n, k)\n");
    printf("    k     k value for the computation of C(n, k)\n");
    printf("    d     average duration of calls (in seconds)\n");
}

function is_int_number($arg, $arg_name, $step)
{
    $int = intval($arg);
    $float = floatval($arg);

    if (is_numeric($arg) == FALSE) {
        fprintf(STDERR, "Error $arg_name must a number !\n");
        return (84);
    }
    if ($int != $float) {
        fprintf(STDERR, "Error $arg_name must be an integer !\n");
        return (84);
    }
    if ($step == 1) {
        if ($int < 1) {
            fprintf(STDERR, "Error $arg_name cannot be lower than 1 !\n");
            return (84);
        }
    } else {
        if ($int < 0) {
            fprintf(STDERR, "Error $arg_name cannot be lower than 1 !\n");
            return (84);
        }
        if ($int > 6) {
            fprintf(STDERR, "Error $arg_name cannot be greater than 6 !\n");
            return (84);
        }
    }
    return (0);
}

function main($argc, $argv)
{
    $i = 0;

    if ($argv[1] == "-h") {
        print_usage();
        return (0);
    }
    if ($argc != 2 && $argc != 3) {
        fprintf(STDERR, "Error wrong number of argument !\n");
        return (84);
    }
    if ($argc == 3) {
        $i += is_int_number($argv[1], "n", 1);
        $i += is_int_number($argv[2], "k", 1);
    } else {
        $i += is_int_number($argv[1], "d", 1);
    }
    if ($i != 0) {
        return (84);
    }
    if ($argc == 3) {
        if ($argv[2] > $argv[1]) {
            return (84);
        }
        binomial_coheficien($argv[1], $argv[2]);
        return (0);
    }
    return (cmp_distribution($argv[1]));
}

?>