<?php

include 'part_1.php';

function do_decresing($n, $k)
{
    $res = 1;
    $rem = $n;

    while ($rem > ($n - $k)) {
        $res *= $rem;
        $rem--;
    }
    return ($res);
}

function my_get_time()
{
    $exploded = explode(" ", microtime());

    return (($exploded[0] + $exploded[1]) * 1000);
}

function bin_dist_formula($n, $t)
{
    $prob = ((($n * 3500) / 8) / 3600) / 3500;

    return (do_decresing(3500, $t) / do_factorial($t)) * pow($prob, $t) * pow((1 - $prob), (3500 - $t));
}

function poiss_dist_formula($n, $t)
{
    $prob = $n / (8 * 3600 / 3500);

    return (exp(-$prob) * pow($prob, $t)) / do_factorial($t);
}

function do_table($mode, $time)
{
    $i = 0;
    $i2 = 1;
    $tmp = -1;

    while ($i <= 50) {
        printf("$i -> %.3f", $mode == 1 ? bin_dist_formula($time, $i) : poiss_dist_formula($time, $i));
        while ($i2 != 5 && $i != 50) {
            printf("\t%d -> %.3f", $i + $i2, $mode == 1 ? bin_dist_formula($time, $i + $i2) : poiss_dist_formula($time, $i + $i2));
            $i2++;
        }
        $i2 = 1;
        printf("\n");
        $i += 5;
    }
}

function overload($time, $mode)
{
    $res = 0;
    $res2 = 0;
    $i = 0;

    while ($i < 26) {
        if ($mode == 1) {
            $res += bin_dist_formula($time, $i);
        } else {
            $res += poiss_dist_formula($time, $i);
        }
        $i++;
    }
    $res2 = 1 - $res;
    $res = $res2 * 100;
    return ($res);
}

function binomial_distrib($time)
{
    printf("Binomial distribution:\n");
    $time_elapsed = my_get_time();
    do_table(1, $time);
    printf("Overload: %.1f%%\n", overload($time, 1));
    printf("Computation time: %.2f ms\n", my_get_time() - $time_elapsed);
}

function poisson_distrib($time)
{
    printf("Poisson distribution:\n");
    $time_elapsed = my_get_time();
    do_table(0, $time);
    printf("Overload: %.1f%%\n", overload($time, 0));
    printf("Computation time: %.2f ms\n", my_get_time() - $time_elapsed);
}

function cmp_distribution($time)
{
    binomial_distrib($time);
    printf("\n");
    poisson_distrib($time);
    return (0);
}

?>