#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db_structures.h"


void init_table(Table *table, const char *name) {
    strncpy(table->name, name, sizeof(table->name));
    table->column_count = 0;
    table->row_count = 0;
    table->rows = NULL;
}


void add_column(Table *table, const char *column_name, const char *type) {
    if (table->column_count < MAX_COLUMNS) {
        Column *col = &table->columns[table->column_count++];
        strncpy(col->name, column_name, MAX_COLUMN_NAME_LENGTH);
        strncpy(col->type, type, sizeof(col->type));
    } else {
        printf("Limite maximale de colonnes atteinte.\n");
    }
}


void insert_row(Table *table, char data[MAX_COLUMNS][MAX_ROW_LENGTH]) {
    table->rows = realloc(table->rows, (table->row_count + 1) * sizeof(Row));
    Row *new_row = &table->rows[table->row_count++];
    for (int i = 0; i < table->column_count; i++) {
        strncpy(new_row->data[i], data[i], MAX_ROW_LENGTH);
    }
}

void db_insert(Table *table, char data[MAX_COLUMNS][MAX_ROW_LENGTH]) {
    insert_row(table, data);
    printf("Ligne insérée avec succès dans la table %s.\n", table->name);
}

void db_select(Table *table) {
    printf("Affichage des données de la table %s :\n", table->name);
    for (int i = 0; i < table->row_count; i++) {
        printf("Ligne %d : ", i + 1);
        for (int j = 0; j < table->column_count; j++) {
            printf("%s = %s, ", table->columns[j].name, table->rows[i].data[j]);
        }
        printf("\n");
    }
}
