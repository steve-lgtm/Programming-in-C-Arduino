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
struct command* create_command(char* name, char* description, char* pattern, size_t nmatch);
struct command* destroy_command(struct command* command);
struct item* create_item(char* name, char* description, unsigned int properties);
struct item* destroy_item(struct item* item);
struct container* add_room_to_world(struct container* world, struct room* room);
struct room* get_room(struct container* world, char* name);
char*naradie="fdgf";
char* description="fdgfdg";
struct item* itemko= create_item(naradie,description, EXAMINABLE);

int i=5;
struct backpack* batoh =create_backpack(i);
add_item_to_backpack(batoh, itemko);
add_item_to_backpack(batoh, itemko1);
add_item_to_backpack(batoh, itemko2);
add_item_to_backpack(batoh, itemko3);
add_item_to_backpack(batoh, itemko4);

destroy_backpack(batoh);


}


