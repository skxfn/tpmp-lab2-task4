/*
 * movie.h
 * Интерфейсный модуль для работы со структурой «Жанры кино»
 * Автор: Ласицкий Никита, группа 12б
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <stdio.h>

#define MAX_TITLE_LEN 200
#define MAX_NAME_LEN 100
#define MAX_COUNTRY_LEN 50
#define MAX_GENRE_LEN 50
#define MAX_MOVIES 50

/*
 * Структура Director - режиссёр
 */
typedef struct {
        char    surname[MAX_NAME_LEN];
        char    firstname[MAX_NAME_LEN];
} Director;

/*
 * Структура Movie - жанры кино
 * title    - название фильма
 * director - режиссёр (фамилия, имя)
 * year     - год выхода
 * country  - страна
 * cost     - стоимость
 * revenue  - доход
 * profit   - прибыль
 * genre    - жанр
 */
typedef struct {
        char      title[MAX_TITLE_LEN];
        Director  director;
        int       year;
        char      country[MAX_COUNTRY_LEN];
        double    cost;
        double    revenue;
        double    profit;
        char      genre[MAX_GENRE_LEN];
} Movie;

/* Чтение массива фильмов из текстового файла */
int     movie_read_from_file(const char *filename, Movie *arr, int max_count);

/* Запись массива фильмов в текстовый файл */
void    movie_write_to_file(const char *filename, Movie *arr, int count);

/* Вывод одного фильма на экран */
void    movie_print(const Movie *m);

/* Вывод всех фильмов */
void    movie_print_all(Movie *arr, int count);

/* Фильтрация: детские фильмы, выпущенные после 2018 года */
int     movie_filter_children_after_2018(Movie *src, int src_count,
                                         Movie *dst, int max_dst);

#endif /* MOVIE_H */
