#include <stdio.h>
#include <assert.h>
#include <string.h>   // Inclure pour strcmp
#include "db_structures.h"
#include "db_functions.c"

int main() {
    printf("Initialisation de la table...\n");
    Table table;
    init_table(&table, "Students");
    printf("Table '%s' initialisée avec %d colonnes et %d lignes.\n", table.name, table.column_count, table.row_count);
    assert(table.column_count == 0);
    assert(table.row_count == 0);

    // Test : Ajout de colonnes
    printf("\nAjout de colonnes 'ID', 'Name', 'Age'...\n");
    add_column(&table, "ID", "INT");
    add_column(&table, "Name", "STRING");
    add_column(&table, "Age", "INT");
    printf("Colonnes ajoutées. Total de colonnes : %d\n", table.column_count);
    for (int i = 0; i < table.column_count; i++) {
        printf("Colonne %d : Nom = %s, Type = %s\n", i + 1, table.columns[i].name, table.columns[i].type);
    }
    assert(table.column_count == 3);

    // Test : Vérification des noms de colonnes
    assert(strcmp(table.columns[0].name, "ID") == 0);
    assert(strcmp(table.columns[1].name, "Name") == 0);
    assert(strcmp(table.columns[2].name, "Age") == 0);

    // Test : Insertion de lignes
    printf("\nInsertion de lignes...\n");
    char row1_data[MAX_COLUMNS][MAX_ROW_LENGTH] = { "1", "Alice", "20" };
    char row2_data[MAX_COLUMNS][MAX_ROW_LENGTH] = { "2", "Bob", "21" };
    insert_row(&table, row1_data);
    insert_row(&table, row2_data);
    printf("Lignes insérées. Total de lignes : %d\n", table.row_count);
    for (int i = 0; i < table.row_count; i++) {
        printf("Ligne %d : ", i + 1);
        for (int j = 0; j < table.column_count; j++) {
            printf("%s = %s, ", table.columns[j].name, table.rows[i].data[j]);
        }
        printf("\n");
    }
    assert(table.row_count == 2);

    // Test : Vérification du contenu des lignes
    assert(strcmp(table.rows[0].data[0], "1") == 0);
    assert(strcmp(table.rows[0].data[1], "Alice") == 0);
    assert(strcmp(table.rows[0].data[2], "20") == 0);

    assert(strcmp(table.rows[1].data[0], "2") == 0);
    assert(strcmp(table.rows[1].data[1], "Bob") == 0);
    assert(strcmp(table.rows[1].data[2], "21") == 0);

    printf("\nTable '%s' a %d colonnes et %d lignes.\n", table.name, table.column_count, table.row_count);
    printf("Tous les tests ont réussi !\n");

    return 0;
}
