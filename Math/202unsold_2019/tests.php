#!/usr/bin/php
<?php
use PHPUnit\Framework\TestCase;

include 'prob_functions.php';

class test extends TestCase
{
    public function test_from_pdf_1(): void
    {
        $res = prob(60, 70, 10, 10);
        $this->assertEquals($res, 0.100);
    }

    public function test_from_pdf_2(): void
    {
        $res = prob(60, 70, 50, 50);
        $this->assertEquals($res, 0.006666666666666667);
    }
}
?>