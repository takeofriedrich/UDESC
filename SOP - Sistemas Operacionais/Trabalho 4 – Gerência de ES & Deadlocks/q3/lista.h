/*
    Código adaptado de: https://github.com/dxtr/list
    Autor do código base: Kim Lidström

    Alterações feitas por Vinícius Takeo para incluir uma interface de inserção e remoção mais fácil na lista.
*/

#ifndef LISTA_H
#define LISTA_H

typedef struct list_node
{
    void *data;
    struct list_node *next;
} list_node;

typedef struct list
{
    list_node *first;
    int tam;
    int tipo;
} list;

/* linked list */

list *list_create(int tipo);
int push(list *lista, void *data, int index);
int pop(list *lista, int index);
void *elementAt(list *list, int index);
void *replaceAt(list *list, int index, void *data);
void printList(list *lista, void*(imprime)(void *valor));
list_node *node_create(void *data, int tipo);
void node_destroy(list_node **list);
void list_destroy(list *lista);
list_node *node_insert_after(list_node *node, void *data, int tipo);
list_node *node_insert_beginning(list_node *list, void *data, int tipo);
list_node *node_insert_end(list_node *list, void *data, int tipo);
void node_remove(list_node **list, list_node *node);
void node_remove_by_data(list_node **list, void *data);
list_node *node_find_node(list_node *list, list_node *node);
list_node *node_find_by_data(list_node *list, void *data);
list_node *node_find(list_node *list, int (*func)(list_node *, void *), void *data);

#endif