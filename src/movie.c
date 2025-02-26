/*
 * movie.c
 * Серверный модуль для работы со структурой «Жанры кино»
 * Реализация функций чтения, записи и фильтрации фильмов
 *
 * Автор: Ласицкий Никита, группа 12б
 */

#include <stdio.h>
#include <string.h>
#include "movie.h"

/*
 * movie_read_from_file - чтение фильмов из текстового файла
 * Формат: title;director_surname;director_name;year;country;cost;revenue;profit;genre
 * Возвращает: количество прочитанных записей
 */
int
movie_read_from_file(const char *filename, Movie *arr, int max_count)
{
        FILE    *fp;
        int     count = 0;

        fp = fopen(filename, "r");
        if (!fp) {
                printf("Error: cannot open file %s\n", filename);
                return 0;
        }

        while (count < max_count &&
               fscanf(fp, " %[^;];%[^;];%[^;];%d;%[^;];%lf;%lf;%lf;%[^\n]",
                      arr[count].title,
                      arr[count].director.surname,
                      arr[count].director.firstname,
                      &arr[count].year,
                      arr[count].country,
                      &arr[count].cost,
                      &arr[count].revenue,
                      &arr[count].profit,
                      arr[count].genre) == 9) {
                count++;
        }

        fclose(fp);

        return count;
}

/*
 * movie_write_to_file - запись фильмов в текстовый файл
 */
void
movie_write_to_file(const char *filename, Movie *arr, int count)
{
        FILE    *fp;
        int     i;

        fp = fopen(filename, "w");
        if (!fp) {
                printf("Error: cannot open file %s for writing\n", filename);
                return;
        }

        for (i = 0; i < count; i++) {
                fprintf(fp, "%s;%s;%s;%d;%s;%.2f;%.2f;%.2f;%s\n",
                        arr[i].title,
                        arr[i].director.surname,
                        arr[i].director.firstname,
                        arr[i].year,
                        arr[i].country,
                        arr[i].cost,
                        arr[i].revenue,
                        arr[i].profit,
                        arr[i].genre);
        }

        fclose(fp);
        printf("Results written to %s\n", filename);
}

/*
 * movie_print - вывод данных одного фильма
 */
void
movie_print(const Movie *m)
{
        printf("  Title: %s\n", m->title);
        printf("  Director: %s %s\n",
               m->director.surname, m->director.firstname);
        printf("  Year: %d\n", m->year);
        printf("  Country: %s\n", m->country);
        printf("  Cost: %.2f\n", m->cost);
        printf("  Revenue: %.2f\n", m->revenue);
        printf("  Profit: %.2f\n", m->profit);
        printf("  Genre: %s\n", m->genre);
}

/*
 * movie_print_all - вывод всех фильмов
 */
void
movie_print_all(Movie *arr, int count)
{
        int     i;

        for (i = 0; i < count; i++) {
                printf("\n--- Movie %d ---\n", i + 1);
                movie_print(&arr[i]);
        }
}

/*
 * movie_filter_children_after_2018 - фильтрация:
 *   детские фильмы (genre = "children"), выпущенные после 2018 года
 * Возвращает: количество найденных записей
 */
int
movie_filter_children_after_2018(Movie *src, int src_count,
                                  Movie *dst, int max_dst)
{
        int     i;
        int     count = 0;

        for (i = 0; i < src_count && count < max_dst; i++) {
                if (strcmp(src[i].genre, "children") == 0 &&
                    src[i].year > 2018) {
                        dst[count] = src[i];
                        count++;
                }
        }

        return count;
}
