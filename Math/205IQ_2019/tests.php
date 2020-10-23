#!/usr/bin/php
<?php
use PHPUnit\Framework\TestCase;

include 'functions.php';

class test extends TestCase
{
    public function test_inferiorCalc_1(): void
    {
        $res = inferiorCalc(100, 24, 90);
        $this->assertEqualsWithDelta(33.8, $res, 0.1);
    }

    public function test_betweenCalc_0(): void
    {
        $res = betweenCalc(100, 24, 90, 95);
        $this->assertEqualsWithDelta(7.90227, $res, 0.1);
    }
}

?>