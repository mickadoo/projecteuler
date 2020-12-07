<?php
declare(strict_types=1);

$exp = 1000;
$res = pow(2, $exp);
$res = number_format($res,0,'.','');
$total = 0;
for ($i = 0; $i < strlen($res); $i ++) {
    $total += intval($res[$i]);
}
echo $total. PHP_EOL;