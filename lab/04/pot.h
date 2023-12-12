#ifndef POT_H
#define POT_H

struct Honeypot
{
    int id;
    char name[50];
};

struct Node
{
    struct Honeypot data;
    struct Node *next;
};

void initQueue();
int isEmpty();
void enqueue(struct Honeypot honeypot);
struct Honeypot dequeue();
struct Honeypot peek();
void displayQueue();

#endif
