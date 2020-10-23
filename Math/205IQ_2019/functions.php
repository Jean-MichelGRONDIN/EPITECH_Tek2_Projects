<?php

function formula($x, $sigma, $micro) {
    $expo = (-1 * pow($x - $micro, 2)) / (2 * pow($sigma, 2));
    $res = exp($expo) / ($sigma * sqrt(2 * M_PI));
    return ($res);
}

function inferiorCalc($u, $s, $iq1)
{
    $res = 0.0;

    for ($i = 0 ; $i < $iq1 ; $i += 0.001) {
        $res += formula($i, $s, $u);
    }
    printf("%.1f%% of people have an IQ inferior to %d\n", $res / 10, $iq1);
    return ($res / 10);
}

function betweenCalc($u, $s, $iq1, $iq2)
{
    $res = 0.0;

    for ($i = $iq1 ; $i < $iq2 ; $i += 0.001) {
        $res += formula($i, $s, $u);
    }
    printf("%.1f%% of people have an IQ between %d and %d\n", $res / 10, $iq1, $iq2);
    return ($res / 10);
}

function densityCalc($u, $s)
{
    $res = 0.0;

    for ($i = 0; $i <= 200 ; $i++) {
        $res = formula($i, $s, $u);
        printf("%d %.5f\n", $i, $res);
    }
    return (0);
}

function is_int_number($arg, $arg_name)
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
    if ($int < 0) {
        fprintf(STDERR, "Error $arg_name cannot be lower than 1 !\n");
        return (84);
    }
    return (0);
}

?>