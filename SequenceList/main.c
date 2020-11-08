#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 32
#define TEL_MAX 50

typedef struct _tel
{
    char name[NAME_MAX];
    long tel;
} Tel;

typedef struct _tel_list
{
    Tel tel_list[TEL_MAX];
    int size;
} TelList;

typedef struct _student
{
    char name[NAME_MAX];
    TelList tel_list;
    struct _student *next;
} Student;

#define SIZE sizeof(Student)

void menu_main();
void menu_tel();
Student *init();
Student *node_create();
void input_node(Student *node);
void print_node(Student *node);
void show_all(Student *head);
void show_name(Student *head, char *name);
int exist(Student *head, char *name);
Student *search(Student *head, char *name);
Student *append(Student *head);
Student *insert_after(Student *head, char *name);
Student *insert_before(Student *head, char *name);
Student *delete (Student *head, char *name);
void input_tel(TelList* tel_list);
Student *tel_list_main(Student *head, char *name);
TelList *tel_display(TelList *tel_list);
TelList *tel_add(TelList *tel_list);
TelList *tel_delete(TelList *tel_list, char *name);

int main(int argc, char *argv[])
{
    Student *link = init();
    char c = 'y';
    int n = 0;
    char name[NAME_MAX];
    int flag_exit = 0;
    while (1)
    {
        menu_main();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            show_all(link);
            break;
        case 2:
            link = append(link);
            break;
        case 3:
            printf("Please input ` name: ");
            scanf("%s", name);
            link = delete (link, name);
            break;
        case 4:
            printf("Please input user name: ");
            scanf("%s", name);
            show_name(link, name);
            break;
        case 5:
            printf("Please input user name: ");
            scanf("%s", name);
            link = insert_before(link, name);
            break;
        case 6:
            printf("Please input user name: ");
            scanf("%s", name);
            link = insert_after(link, name);
            break;
        case 7:
            printf("Please input user name: ");
            scanf("%s", name);
            link = tel_list_main(link, name);
            break;
        case 8:
            flag_exit = 1;
            break;
        default:
            printf("Wrong Number! Please try again! ");
            break;
        }
        if (flag_exit == 1)
        {
            break;
        }
    }

    return 0;
}

void menu_main()
{
    printf("1. Display\n");
    printf("2. Add\n");
    printf("3. Delete\n");
    printf("4. Search\n");
    printf("5. Insert Before\n");
    printf("6. Insert After\n");
    printf("7. Tel List\n");
    printf("8. Exit\n");
}

void menu_tel()
{
    printf("1. Display\n");
    printf("2. Add\n");
    printf("3. Delete\n");
    printf("4. Exit\n");
}

Student *init()
{
    return NULL;
}

Student *node_create()
{
    Student *node = (Student *)malloc(SIZE * 1);
    input_node(node);
    return node;
}

void input_node(Student *node)
{
    printf("Please input Name: ");
    scanf("%s", node->name);
    node->tel_list.size = 0;
    printf("Input TeleList now? (Y/n)\n");
    char user_in;
    scanf("%c", &user_in);
    if (user_in == 'Y' || user_in == 'y')
    {
        input_tel(&(node->tel_list));
    }
}

void print_node(Student *node)
{
    printf("Name: %s\n", node->name);
    // printf("Tele: %ld\n", node->tel);
}

void show_all(Student *head)
{
    Student *p = head;
    printf("===== Start =====\n");
    while (p != NULL)
    {
        print_node(p);
        if (p->next != NULL)
        {
            printf("\n");
        }
        p = p->next;
    }
    printf("=====  End  =====\n");
}

// show all the node with the name 'name' in list 'head'
void show_name(Student *head, char *name)
{
    int flag = 0;
    Student *p = head;
    printf("===== Start =====\n");
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            flag++;
            if (flag > 1)
            {
                printf("\n");
            }
            print_node(p);
        }
        p = p->next;
    }
    if (flag == 0)
    {
        printf("Can't Find the person with name %s.\n", name);
    }
    printf("=====  End  =====\n");
}

int exist(Student *head, char *name)
{
    int flag = 0;
    Student *p = head;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    return flag;
}

Student *search(Student *head, char *name)
{
    Student *p = head;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Student *append(Student *head)
{
    Student *node = node_create();
    node->next = NULL;
    if (head == NULL)
    {
        return node;
    }
    Student *p = head;
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            p->next = node;
            break;
        }
        p = p->next;
    }
    return head;
}

Student *insert_after(Student *head, char *name)
{
    if (head == NULL)
    {
        return head;
    }
    Student *p = head;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            Student *node = node_create();
            Student *next = p->next;
            p->next = node;
            node->next = next;
            break;
        }
        p = p->next;
    }
    return head;
}

Student *insert_before(Student *head, char *name)
{
    if (head == NULL)
    {
        return head;
    }
    if (strcmp(name, head->name) == 0)
    {
        Student *node = node_create();
        node->next = head;
        return node;
    }
    Student *before = head;
    Student *p = head->next;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            Student *node = node_create();
            before->next = node;
            node->next = p;
            break;
        }
    }
    return head;
}

// delete the first node with the name 'name' in list 'head'
Student *delete (Student *head, char *name)
{
    if (head == NULL)
    {
        return head;
    }
    if (strcmp(name, head->name) == 0)
    {
        Student *new_head = head->next;
        free(head);
        return new_head;
    }
    Student *before = head;
    Student *p = head->next;
    Student *free_node = NULL;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            before->next = p->next;
            free(free_node);
            break;
        }
        before = before->next;
        p = p->next;
    }
    return head;
}

Student *tel_list_main(Student *head, char *main)
{
    if (head == NULL)
    {
        return head;
    }
    Student *node = search(head, main);
    if (node == NULL)
    {
        return head;
    }
    TelList *tel_list = &(node->tel_list);
    menu_tel();
    int n = 0;
    int flag_exit = 0;
    char name[NAME_MAX];
    scanf("%d", &n);
    while (1)
    {
        switch (n)
        {
        case 1:
            tel_display(tel_list);
            break;
        case 2:
            tel_add(tel_list);
            break;
        case 3:
            printf("Please input name: ");
            scanf("%s", name);
            tel_delete(tel_list, name);
            break;
        case 4:
            flag_exit = 1;
            break;
        default:
            printf("Wrong number, please input again.\n");
            break;
        }
        if (flag_exit == 1)
        {
            break;
        }
    }
    return head;
}

void input_tel(TelList* tel_list)
{
    if (tel_list->size == TEL_MAX) {
        printf("The list is full!\n");
        return;
    }
    printf("Please input Name: ");
    scanf("%s", tel_list->tel_list->name);
}

TelList *tel_display(TelList *tel_list)
{
    printf("===== Start =====\n");
    for (int i = 0; i < tel_list->size; i++) {
        printf("Name: %s\n", tel_list->tel_list[i].name);
        printf("Tel:  %ld\n", tel_list->tel_list[i].tel);
        printf("\n");
    }
    printf("=====  End  =====\n");
}

TelList *tel_add(TelList *tel_list)
{
    if (tel_list == NULL) {
        return tel_list;
    }
    printf("Please input name: ");
    scanf("%s", tel_list->tel_list->name);
    printf("Please input tele: ");
    scanf("%ld", &(tel_list->tel_list->tel));
    return tel_list;
}


TelList *tel_delete(TelList *tel_list, char *name)
{
}
