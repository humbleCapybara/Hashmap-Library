#ifndef LIBRARY_H
#define LIBRARY_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUMOFALPHA 26

typedef struct book {
    int copies;
    char* ISBN;
    char* name;
    struct book* next;
} Node;

extern Node* head[NUMOFALPHA];
extern const char* filename;

Node* createNode(Node* head, char* ISBN, char *data);
Node* createList(Node* head, char* ISBN, char *data);
int deleteBook(char* ISBN);
char* search(Node* head, char* ISBN);
char* searchBook(char* ISBN);
void displayBook(Node* head);
void insertBooks(char* ISBN, char* bookName);
int count(Node* head);
void displayBoard();
void updateBookName(char* ISBN, char* newBookName);
void flush();
void storeLibrary(const char* filename);
void loadLibrary(const char* filename);
int mainWindow();
void clear();
void wait();
void closeProgram();

void createAddBookWindow(int argc, char* argv[]);
void createDeleteBookWindow(int argc, char* argv[]);
void searchBookWindow(int argc, char* argv[]);

#endif
