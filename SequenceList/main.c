#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 32

typedef struct _student
{
    char name[NAME_MAX];
    long tel;
    struct _student *next;
} Student;

#define SIZE sizeof(Student)

Student *init();
Student *node_create();
void input_node(Student *node);
void print_node(Student *node);
void show_all(Student *head);
void show_name(Student *head, char *name);
int exist(Student *head, char *name);
Student *append(Student *head);
Student *insert_after(Student *head, char *name);
Student *insert_before(Student *head, char *name);
Student *delete (Student *head, char *name);

void menu_main()
{
    printf("1. Display\n");
    printf("2. Add\n");
    printf("3. Delete\n");
    printf("4. Search\n");
    printf("5. Insert Before\n");
    printf("6. Insert After\n");
    printf("7. Exit\n");
}

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
            printf("Please input name: ");
            scanf("%s", name);
            link = delete (link, name);
            break;
        case 4:
            printf("Please input name: ");
            scanf("%s", name);
            show_name(link, name);
            break;
        case 5:
            printf("Please input name: ");
            scanf("%s", name);
            link = insert_before(link, name);
            break;
        case 6:
            printf("Please input name: ");
            scanf("%s", name);
            link = insert_after(link, name);
            break;
        case 7:
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
    printf("Please input Tele: ");
    scanf("%ld", &(node->tel));
}

void print_node(Student *node)
{
    printf("Name: %s\n", node->name);
    printf("Tele: %ld\n", node->tel);
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
            if (flag > 1) {
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