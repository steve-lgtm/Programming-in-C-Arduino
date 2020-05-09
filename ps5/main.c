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
#include <stddef.h>

int main(){
    struct container* create_container(struct container* first, enum container_type type, void* entry);
    struct container* destroy_containers(struct container* first);
    void* get_from_container_by_name(struct container *first, const char *name);

}