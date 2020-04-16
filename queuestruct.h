#ifndef queuestruct
#define queuestruct

typedef struct QNode {
    char kata[300];
    struct QNode* next; 																// struct dengan isi node yang isinya string
} QNode;

typedef struct Queue {
    struct QNode *front, *rear; 														// struct dengan isi data front mana belakang (rear) mana
} Queue;

#endif