<?php

function do_factorial($nb)
{
    if ($nb <= 1)
        return 1;
    return ($nb * do_factorial($nb - 1));
}

function binomial_coheficien($n, $k)
{
    $output = shell_exec("python3 my_python_fact.py $n $k");
    printf("%s", $output);
    return (0);
}

?>