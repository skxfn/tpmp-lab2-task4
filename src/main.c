/*
 * main.c
 * Клиентский модуль для задания 4, вариант 13
 * Чтение данных о фильмах из файла, фильтрация детских фильмов
 * после 2018 года, запись результата в новый файл
 *
 * Автор: Ласицкий Никита, группа 12б
 */

#include <stdio.h>
#include "movie.h"

int
main(int argc, char *argv[])
{
        Movie   movies[MAX_MOVIES];
        Movie   filtered[MAX_MOVIES];
        int     total;
        int     filtered_count;
        const char *input_file = "data/input.txt";
        const char *output_file = "data/output.txt";

        if (argc >= 2) {
                input_file = argv[1];
        }
        if (argc >= 3) {
                output_file = argv[2];
        }

        /* Чтение данных из файла */
        total = movie_read_from_file(input_file, movies, MAX_MOVIES);
        if (total == 0) {
                printf("No data found.\n");
                return 1;
        }

        printf("=== All movies (%d) ===", total);
        movie_print_all(movies, total);

        /* Фильтрация: детские фильмы после 2018 года */
        filtered_count = movie_filter_children_after_2018(
                movies, total, filtered, MAX_MOVIES);

        printf("\n\n=== Children's movies after 2018 (%d) ===",
               filtered_count);

        if (filtered_count > 0) {
                movie_print_all(filtered, filtered_count);
                movie_write_to_file(output_file, filtered, filtered_count);
        } else {
                printf("\nNo children's movies after 2018 found.\n");
        }

        return 0;
}
