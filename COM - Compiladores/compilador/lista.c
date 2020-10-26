#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include "stdio.h"

list *list_create(int tipo)
{
    list *lista = (list *)malloc(sizeof(list));
    lista->tam = 0;
    lista->tipo = tipo;
    lista->first = NULL;
    return lista;
}

int push(list *lista, void *data, int index)
{
    if (index > lista->tam + 1 || index < -1)
    {
        return -1;
    }
    else if (lista->first == NULL)
    {
        lista->first = node_create(data, lista->tipo);
        lista->tam++;
        return 1;
    }
    else if (index == 0)
    {
        lista->first = node_insert_beginning(lista->first, data, lista->tipo);
        lista->tam++;
        return 1;
    }
    else if (index == lista->tam + 1)
    {
        list_node *aux = lista->first;
        while (aux != NULL)
        {
            aux = aux->next;
        }
        node_insert_end(aux, data, lista->tipo);
        lista->tam++;
    }
    else
    {
        list_node *aux = lista->first;
        for (int i = 0; i < index - 1; i++)
        {
            aux = aux->next;
        }
        node_insert_after(aux, data, lista->tipo);
        lista->tam++;
    }
}

void *elementAt(list *lista, int index)
{
    if (index > lista->tam + 1 || index < -1 || lista->first == NULL)
    {
        return NULL;
    }
    else if (index == 0)
    {
        return lista->first->data;
    }
    else if (index == lista->tam + 1 || index == -1)
    {
        list_node *aux = lista->first;
        while (aux != NULL)
        {
            aux = aux->next;
        }
        return aux->data;
    }
    else
    {
        list_node *aux = lista->first;
        for (int i = 0; i < index; i++)
        {
            aux = aux->next;
        }
        return aux->data;
    }
}

void *replaceAt(list *lista, int index, void *data){
    if (index > lista->tam + 1 || index < -1 || lista->first == NULL)
    {
        return NULL;
    }
    else if (index == 0)
    {
        memcpy(lista->first->data, data, lista->tipo);
    }
    else if (index == lista->tam + 1 || index == -1)
    {
        list_node *aux = lista->first;
        while (aux != NULL)
        {
            aux = aux->next;
        }
        memcpy(aux->data, data, lista->tipo);
    }
    else
    {
        list_node *aux = lista->first;
        for (int i = 0; i < index; i++)
        {
            aux = aux->next;
        }
        memcpy(aux->data, data, lista->tipo);
    }
}

void printList(list *lista, void*(imprime)(void *valor))
{
    list_node *aux = lista->first;
    while (aux != NULL)
    {
        imprime(aux->data);
        aux = aux->next;
    }
    printf("\n");
}

list_node *node_create(void *data, int tipo)
{
    list_node *l = malloc(sizeof(list_node));
    if (l != NULL)
    {
        l->next = NULL;
        l->data = (void*)malloc(sizeof(tipo));
        if(l->data != NULL){
            memcpy(l->data, data, tipo);
        }
        
    }

    return l;
}

/* Completely destroys a list
 * Arguments: A pointer to a pointer to a list
 */
void node_destroy(list_node **list)
{
    if (list == NULL)
        return;
    while (*list != NULL)
    {
        node_remove(list, *list);
    }
}
void list_destroy(list *lista)
{
    if (lista->first!=NULL) {
        list_node *next = lista->first->next;
        list_node *now = lista->first;

        while (next!=NULL) {
            if(now->data!=NULL){
                free(now->data);
            }
            free(now);
            now = next;
            next = next->next;
        }
        free(now);
    }
    free(lista);
}

int pop(list *lista, int index) {
    list_node *tmp = NULL;
    if (lista == NULL || lista->first==NULL || index > lista->tam)
        return -1;
    if (index == 0)
    {
        tmp = lista->first;
        lista->first = lista->first->next;
        free(tmp);
        lista->tam--;
        return 1;
    }
    else if (index == lista->tam)
    {
        tmp = lista->first;
        list_node *back = NULL;
        while (tmp->next!=NULL) {
            back = tmp;
            tmp = tmp->next;
        }
        free(back->next);
        back->next = NULL;
        lista->tam--;
        return 1;

    }
    else {
        tmp = lista->first;
        list_node *back = NULL;
        for (int i=0;i<index;i++) {
            back = tmp;
            tmp = tmp->next;
        }
        back->next = tmp->next;
        free(tmp);
        lista->tam--;
        return 1;
    }
}

/* Creates a list node and inserts it after the specified node
 * Arguments: A node to insert after and the data the new node will contain
 */
list_node *node_insert_after(list_node *node, void *data, int tipo)
{
    list_node *new_node = node_create(data, tipo);
    if (new_node)
    {
        new_node->next = node->next;
        node->next = new_node;
    }
    return new_node;
}

/* Creates a new list node and inserts it in the beginning of the list
 * Arguments: The list the node will be inserted to and the data the node will
 * contain
 */
list_node *node_insert_beginning(list_node *list, void *data, int tipo)
{
    list_node *new_node = node_create(data, tipo);
    if (new_node != NULL)
    {
        new_node->next = list;
    }
    return new_node;
}

/* Creates a new list node and inserts it at the end of the list
 * Arguments: The list the node will be inserted to and the data the node will
 * contain
 */
list_node *node_insert_end(list_node *list, void *data, int tipo)
{
    list_node *new_node = node_create(data, tipo);
    if (new_node != NULL)
    {
        for (list_node *it = list; it != NULL; it = it->next)
        {
            if (it->next == NULL)
            {
                it->next = new_node;
                break;
            }
        }
    }
    return new_node;
}

/* Removes a node from the list
 * Arguments: The list and the node that will be removed
 */
void node_remove(list_node **list, list_node *node)
{
    list_node *tmp = NULL;
    if (list == NULL || *list == NULL || node == NULL)
        return;

    if (*list == node)
    {
        *list = (*list)->next;
        free(node);
        node = NULL;
    }
    else
    {
        tmp = *list;
        while (tmp->next && tmp->next != node)
            tmp = tmp->next;
        if (tmp->next)
        {
            tmp->next = node->next;
            free(node);
            node = NULL;
        }
    }
}

/* Removes an element from a list by comparing the data pointers
 * Arguments: A pointer to a pointer to a list and the pointer to the data
 */
void node_remove_by_data(list_node **list, void *data)
{
    if (list == NULL || *list == NULL || data == NULL)
        return;
    node_remove(list, node_find_by_data(*list, data));
}

/* Find an element in a list by the pointer to the element
 * Arguments: A pointer to a list and a pointer to the node/element
 */
list_node *node_find_node(list_node *list, list_node *node)
{
    while (list)
    {
        if (list == node)
            break;
        list = list->next;
    }
    return list;
}

/* Finds an elemt in a list by the data pointer
 * Arguments: A pointer to a list and a pointer to the data
 */
list_node *node_find_by_data(list_node *list, void *data)
{
    while (list)
    {
        if (list->data == data)
            break;
        list = list->next;
    }
    return list;
}

/* Finds an element in the list by using the comparison function
 * Arguments: A pointer to a list, the comparison function and a pointer to the
 * data
 */
list_node *node_find(list_node *list, int (*func)(list_node *, void *), void *data)
{
    if (!func)
        return NULL;
    while (list)
    {
        if (func(list, data))
            break;
        list = list->next;
    }
    return list;
}