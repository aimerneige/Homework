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
Student* node_create();
void input_node(Student *node);
void print_node(Student *node);
void show_all(Student *head);
void show_name(Student *head, char *name);
int exist(Student *head, char *name);
Student *append(Student *head);
Student *insert_after(Student *head, char *name);
Student *insert_before(Student *head, char *name);
Student *delete (Student *head, char *name);

int main(int argc, char *argv[])
{
    // Student *head = NULL;
    // head = (Student *)malloc(SIZE * 1);
    // input_node(head);
    // head->next = NULL;
    // show_all(head);
    // show_name(head, "AimerNeige");
    // show_name(head, "A");

    Student *link = init();

    return 0;Student* node_create();
}

Student *init()
{
    return NULL;
}

Student* node_create()
{
    Student* node = (Student*) malloc(SIZE * 1);
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
        if (strcmp(name, head->name) == 0)
        {
            flag = 1;
            print_node(p);
        }
        if (p->next != NULL)
        {
            printf("\n");
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
        if (strcmp(name, head->name) == 0)
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
    if (head == NULL)
    {
        Student *node = node_create();
        node->next = NULL;
        return node;
    }
    Student *p = head;
    while (p != NULL)
    {
        if (p->next == NULL) {
            Student* node = node_create();
            node->next = NULL:
            p->next = node;
        }
        break;
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
        if (strcmp(name, head->name) == 0)
        {
            Student *node = node_create();
            Student *next = p->next;
            p->next = node;
            node->next = next;
            break;
        }
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
        if (strcmp(name, head->name) == 0)
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
        if (strcmp(name, head->name) == 0)
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
