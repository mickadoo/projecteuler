<?php
declare(strict_types=1);

const MAX_X = 20;
const MAX_Y = MAX_X;

$grid = [];
for ($x = MAX_X; $x >= 0; $x--) {
    for ($y = MAX_Y; $y >= 0; $y--) {
        if ($y === MAX_Y && $x === MAX_X) {
            $grid[$x][$y] = 1;
            continue;
        }
        $grid[$x][$y] = ($grid[$x + 1][$y] ?? 0) + ($grid[$x][$y + 1] ?? 0);
    }
}

echo $grid[0][0]. PHP_EOL;