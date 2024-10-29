#ifndef DB_STRUCTURES_H
#define DB_STRUCTURES_H

#define MAX_COLUMNS 10
#define MAX_COLUMN_NAME_LENGTH 50
#define MAX_ROW_LENGTH 100

typedef struct {
    char name[MAX_COLUMN_NAME_LENGTH];
    char type[10];
} Column;

typedef struct {
    char data[MAX_COLUMNS][MAX_ROW_LENGTH];
} Row;

typedef struct {
    char name[50];          
    Column columns[MAX_COLUMNS];
    int column_count;
    Row *rows;
    int row_count;
} Table;

#endif
