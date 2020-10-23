/*
** EPITECH PROJECT, 2020
** ex03
** File description:
** pyramid
*/

int search_path(int x, int y, int max, const int **map)
{
    int one = map[x][y];
    int two = map[x][y];

    if (max == 1)
        return (map[x][y]);
    one = one + search_path(x + 1, y, max -1, map);
    two = two + search_path(x + 1, y + 1, max - 1, map);
    if (one < two)
        return (one);
    return (two);
}

int  pyramid_path(int size, const int **map)
{
    return (search_path(0, 0, size, map));
}
