#!/usr/bin/php
<?php
use PHPUnit\Framework\TestCase;

include 'cmp_distributions.php';

class test extends TestCase
{
    public function test_do_factorial_1(): void
    {
        $res = do_factorial(10);
        $this->assertEquals(3628800, $res);
    }

    public function test_do_factorial_2(): void
    {
        $res = do_factorial(3);
        $this->assertEquals(6, $res);
    }

    public function test_overload_mode_0(): void
    {
        $res = overload(180, 0);
        $this->assertEqualsWithDelta(21.47, $res, 0.01);
    }

    public function test_overload_mode_1(): void
    {
        $res = overload(180, 1);
        $this->assertEqualsWithDelta(21.41, $res, 0.01);
    }
}
?>