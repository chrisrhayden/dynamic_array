#include <stdio.h>

#include "../src/dynamic_array.h"

void drop_char_ele(void *ele) {
    free(ele);
}

bool search_char(void *to_find, void *element) {
    return (*(char *)to_find == *(char *)element);
}

int main() {
    size_t initial_len = 2;
    size_t char_size = sizeof(char *);

    DynamicArray *dynamic_array =
        create_dyn_array(char_size, initial_len, search_char, drop_char_ele);

    for (size_t i = 33; i <= 43; ++i) {

        char *ele = malloc(sizeof(char));
        *ele = i;

        if (insert_dyn_array(dynamic_array, ele) == false) {
            printf("bad insert\n");
            break;
        }
    }

    printf(" > ");
    for (size_t i = 0; i <= 10; ++i) {
        void *ele = get_element_dyn_array(dynamic_array, i);

        printf("%c", *(char *)ele);
    }
    printf(" < \n");

    char to_find = '+';
    size_t ind = search_dyn_array(dynamic_array, &to_find);

    if (ind == -1) {
        printf("did not find the element \n");
    } else if (ind == -2) {
        printf("no search callback \n");
    } else {
        printf(">>>>>>> %c\n",
               *(char *)get_element_dyn_array(dynamic_array, ind));
    }

    drop_dyn_array(dynamic_array);
    printf("done\n");

    return 0;
}
