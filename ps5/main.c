#include "container.h"
#include "parser.h"
#include "room.h"
#include "world.h"
#include "item.h"
#include "game.h"
#include "backpack.h"
#include "command.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(){
    struct container* create_container(struct container* first, enum container_type type, void* entry);
    struct container* destroy_containers(struct container* first);
    void* get_from_container_by_name(struct container *first, const char *name);
    struct container* remove_container(struct container *first, void *entry);
struct room* create_room(char *name, char *description);
struct item* destroy_item(struct item* item);
struct command* destroy_command(struct command* command);
void set_exits_from_room(struct room *room, struct room *north, struct room *south, struct room *east, struct room *west);
void show_room(const struct room* room);
void delete_item_from_room(struct room* room, struct item* item);
void add_item_to_room(struct room* room, struct item* item);
struct item* get_item_from_room(const struct room* room, const char* name);
char *first_text = calloc(100, 1);
    char *second_text = calloc(100, 1);
    strcpy(first_text, "First text");
    strcpy(second_text, "Second text");
    struct container *first = create_container(NULL, TEXT, first_text);
    struct container *second = create_container(first, TEXT, second_text);

    printf("TEXT:\t%s\n", first->text);
    printf("TEXT:\t%p\n", first->next);
    printf("TEXT:\t%s\n", second->text);
    struct container *found = get_from_container_by_name(first, "First tEXT");
    if (found != NULL)
    {
        printf("FOUND:\t%s\n", found->text);
    }
    else
    {
        printf("FOUND:\t%p\n", found);
    }
    destroy_containers(first);

}