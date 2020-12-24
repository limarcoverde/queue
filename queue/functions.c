#include "queue.h"

struct list{
        int value;
        struct list *next;
};

struct list *head;
struct list *tail;
struct list *size;

struct list *start()
{
        struct list *new = malloc(sizeof(struct list));

        new->value = 0;
        new->next = NULL;

        return new;
}

void insert(int *value)
{
        struct list *new = malloc(sizeof(struct list));

        new->value = *value;
        if(size->value == 0){
                head = new;
                tail = new;
        }else{
                tail->next = new;
                tail = new;
        }
        new->next = NULL;
        size->value++;
}

void delete()
{
        struct list *aux = head;
        if(size->value>0){
                head = head->next;
                size->value--;
                free(aux);
        }else{
                printf("Você não pode mais retirar pois a fila está vazia\n");
        }
}

void update(int *out, int *in)
{
        struct list *aux = head;
        int flag = 0;
        
        while(aux!=NULL){
                if(aux->value == *out){
                        aux->value = *in;
                        flag = 1;
                        break;
                }
                aux = aux->next;
        }
        if(flag == 0){
                printf("Valor %d não encontrado, favor tente novamente!\n",*out);
        }
}

void printar()
{
        struct list *aux = head;
        int count=1;
        printf("queue: ");
        while(aux!=NULL){
                printf("%d ",aux->value);
                aux = aux->next;
                count++;
        }
        printf("\n");
        printf("size = %d\n",size->value);
}

void init(int argc, char **argv)
{

        head = start();
        tail = start();
        size = start();

        char *ptr;
        int value;

        for(int i=1;i<argc;i++){
                value = strtol(argv[i], &ptr, 10);
                insert(&value);
        }

        value = 0;
        while(value != 5){
                value = menu();
                direct(&value);
        }
}

int menu()
{
        int choice;
        printf("---------- MENU ----------\n");
        printf("|  1. Adicionar na fila  |\n");
        printf("|  2. Retirar na fila    |\n");
        printf("|  3. atualizar a fila   |\n");
        printf("|  4. Mostrar a fila     |\n");
        printf("|  5. Sair do programa   |\n");
        printf("--------------------------\n");
        printf("O que você deseja fazer? ");
        scanf("%d",&choice);
        getchar();

        return choice;
}

void direct(int *choice)
{
        int valor;
        int in;
        switch (*choice){
        case 1:
                printf("Digite o valor para inserção: ");
                scanf("%d",&valor);
                getchar();

                insert(&valor);
                break; 
        case 2:     
                delete();
                break;
        case 3:
                printf("Digite o valor contido na fila: ");
                scanf("%d",&valor);
                getchar();

                printf("Digite o valor substituto: ");
                scanf("%d",&in);
                getchar();

                update(&valor,&in);
                break;
        case 4:
                printar();
                break;
        default:
                if(*choice!=5){
                        printf("tente novamente, valor invalido!\n");
                }
                break;
        }
}