<?php

function print_usage()
{
    printf("USAGE\n");
    printf("    ./201yams d1 d2 d3 d4 d5 c\n\n");
    printf("DESCRIPTION\n");
    printf("    d1     value of the first die (0 if not thrown)\n");
    printf("    d2     value of the second die (0 if not thrown)\n");
    printf("    d3     value of the third die (0 if not thrown)\n");
    printf("    d4     value of the fourth die (0 if not thrown)\n");
    printf("    d5     value of the fifth die (0 if not thrown)\n");
    printf("    c      expected combination\n");
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
    if ($step == 1)
        if ($int < 1) {
            fprintf(STDERR, "Error $arg_name cannot be lower than 1 !\n");
            return (84);
        }
    else
        if ($int < 0) {
            fprintf(STDERR, "Error $arg_name cannot be lower than 1 !\n");
            return (84);
        }
    if ($int > 6) {
        fprintf(STDERR, "Error $arg_name cannot be greater than 6 !\n");
        return (84);
    }
    return (0);
}

function do_factorial($nb_fact) {
    if ($nb_fact < 2) {
        return (1);
    }
    return $nb_fact * do_factorial($nb_fact - 1);
}

function do_form($nb_1, $nb_2)
{
    if ($nb_2 < 0)
        $nb_2 = 1;
    $res = do_factorial($nb_1) / (do_factorial($nb_2) * do_factorial($nb_1 - $nb_2)) * pow(1/6, $nb_2) * pow(5/6, $nb_1 - $nb_2);
    return $res;
}

function check_nb_arg($nb, $argv)
{
    $res = 0;
    $array = array(intval($argv[1]),
                    intval($argv[2]),
                    intval($argv[3]),
                    intval($argv[4]),
                    intval($argv[5]),
                    NULL,
                );
    for($i = 0; $i < 5; $i++)
        if ($array[$i] != intval($nb))
            $res += 1;
    return ($res);
}

function do_pair($argv, $nb)
{
    if (! $nb[1] || is_int_number($nb[1], "searched probability", 1))
        return 84;
    $tmp = check_nb_arg($nb[1], $argv);
    if ($tmp <= 3) {
        $res = 100;
    } else {
        $res = (do_form($tmp, $tmp - 3) + do_form($tmp, $tmp - 2) + do_form($tmp, $tmp - 1) + do_form($tmp, $tmp)) * 100;
    }
    printf("Chances to get a %d pair: %.2f%%\n", intval($nb[1]) ,$res);
    return (0);
}

function do_four($argv, $nb)
{
    if (! $nb[1] || is_int_number($nb[1], "searched probability", 1))
        return 84;
    $tmp = check_nb_arg($nb[1], $argv);
    if ($tmp <= 1) {
        $res = 100;
    } else {
        $res = (do_form($tmp, $tmp - 1) + do_form($tmp, $tmp)) * 100;
    }
    printf("Chances to get a %d four-of-a-kind: %.2f%%\n", intval($nb[1]) ,$res);
    return (0);
}

function do_three($argv, $nb)
{
    if (! $nb[1] || is_int_number($nb[1], "searched probability", 1))
        return 84;
    $tmp = check_nb_arg($nb[1], $argv);
    if ($tmp <= 2) {
        $res = 100;
    } else {
        $res = (do_form($tmp, $tmp - 2) + do_form($tmp, $tmp - 1) + do_form($tmp, $tmp)) * 100;
    }
    printf("Chances to get a %d three-of-a-kind: %.2f%%\n", intval($nb[1]) ,$res);
    return (0);
}

function do_yams($argv, $nb)
{
    if (! $nb[1] || is_int_number($nb[1], "searched probability", 1))
        return 84;
    $tmp = check_nb_arg($nb[1], $argv);
    if ($tmp == 0) {
        $res = 100;
    } else {
        $res = do_form($tmp, $tmp) * 100;
    }
    printf("Chances to get a %d yams: %.2f%%\n", intval($nb[1]) ,$res);
    return (0);
}

function do_full($argv, $nb)
{
    return (84);
}

function check_arg_straight($argv, $dice)
{
    $res = 0;
    $idx_dice = 1;
    $array = array(intval($argv[1]),
                    intval($argv[2]),
                    intval($argv[3]),
                    intval($argv[4]),
                    intval($argv[5]),
                    NULL,
                );
    $straight = array(
        0 => 0,
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
    );
    if ($dice == 6)
        $idx_dice = 2;
    for ($inc = 0; $inc < 5; $inc++) {
        for($i = 0; $i < 5; $i++)
            if ($array[$i] == $idx_dice && $straight[$inc] != 1) {
                $straight[$inc] = 1;
                $res += 1;
            }
        $idx_dice += 1;
    }
    return ($res);
}

function do_straight($argv, $nb)
{
    if (! $nb[1] || is_int_number($nb[1], "searched probability", 1) || intval($nb[1]) < 5 || intval($nb[1]) > 6)
        return 84;
    $tmp = check_arg_straight($argv, intval($nb[1]));
    if ($tmp == 5) {
        $res = 100;
    } else {
        $res = (do_form(5 - $tmp, (5 - $tmp) - 5) + do_form(5 - $tmp, (5 - $tmp) - 4) + do_form(5 - $tmp, (5 - $tmp) - 3) + do_form(5 - $tmp, (5 - $tmp) - 2) + do_form(5 - $tmp, (5 - $tmp) - 1) + do_form(5 - $tmp, 5 - $tmp)) * 10;
    }
    printf("Chances to get a %d straight: %.2f%%\n", intval($nb[1]) ,$res);
    return (0);
}

function do_right_fct($argv)
{
    $fct_arr = array(
        'pair_' => 'do_pair',
        'three_' => 'do_three',
        'four_' => 'do_four',
        'full_' => 'do_full',
        'straight_' => 'do_straight',
        'yams_' => 'do_yams',
    );
    $nb = explode('_', $argv[6]);
    $fct = substr($argv[6], 0, strpos($argv[6], '_') + 1);
    if (array_key_exists($fct, $fct_arr))
        return ($fct_arr[$fct]($argv, $nb));
    else
        return 84;
}

function main($argc, $argv)
{
    $i = 0;

    if ($argv[1] == "-h") {
        print_usage();
        return (0);
    }
    if ($argc != 7) {
        fprintf(STDERR, "Error wrong number of argument !\n");
        return (84);
    }
    $i += is_int_number($argv[1], "d1", 0);
    $i += is_int_number($argv[2], "d2", 0);
    $i += is_int_number($argv[3], "d3", 0);
    $i += is_int_number($argv[4], "d4", 0);
    $i += is_int_number($argv[5], "d5", 0);
    if ($i != 0) {
        return (84);
    } else {
        return do_right_fct($argv);
    }
}
//
// yams = 1/6 pow 5 * 100
?>