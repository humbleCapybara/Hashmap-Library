#include "library.h"

Node* head[26] = {NULL};
const char* filename = "library.txt";

Node* createNode(Node* head, char* ISBN, char *data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    temp->copies = 1;
    temp->ISBN = strdup(ISBN);
    temp->name = strdup(data);
    return temp;
}

Node* createList(Node* head, char* ISBN, char *data) {
    Node* temp = createNode(head, ISBN, data);
    if (head != NULL) {
        Node* ptr;
        for (ptr = head; ptr->next != NULL; ptr = ptr->next);
        ptr->next = temp;
    } else {
        head = temp;
    }
    return head;
}

int deleteBook(char* ISBN) {
    for (int i = 0; i < NUMOFALPHA; i++) {
        Node* current = head[i];
        Node* prev = NULL;

        while (current != NULL) {
            if (strcmp(current->ISBN, ISBN) == 0) {
                if (prev == NULL) {
                    head[i] = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current->ISBN);
                free(current->name);
                free(current);
                return 1;
            }
            prev = current;
            current = current->next;
        }
    }
    return -1;
}

char* search(Node* head, char* ISBN) {
    Node* ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        if (strcmp(ptr->ISBN, ISBN) == 0) {
            return ptr->name;
        }
    }
    return NULL;
}

char* searchBook(char* ISBN) {
    char* bookname = NULL;
    for (int i = 0; i < NUMOFALPHA; i++) {
        bookname = search(head[i], ISBN);
        if (bookname != NULL) break;
    }
    return bookname;
}

void displayBook(Node* head) {
    Node* ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        printf(" [ %s | %s | copies: %d ] ", ptr->ISBN, ptr->name, ptr->copies);
    }
}


void insertBooks(char* ISBN, char* bookName) {
    for (int i = 0; i < NUMOFALPHA; i++) {
        Node* current = head[i];
        while (current != NULL) {
            if (strcmp(current->ISBN, ISBN) == 0) {
                current->copies++;
                printf("[INFO] Duplicate entry found. Incremented copies to %d.\n", current->copies);
                return;
            }
            current = current->next;
        }
    }

    char firstLetter = bookName[0];
    int index = (int) toupper(firstLetter) - (int) 'A';

    head[index] = createList(head[index], ISBN, bookName);
    printf("[SUCCESS] Book Added!\n");
}



int count(Node* head) {
    int cnt = 0;
    Node* ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        cnt++;
    }
    return cnt;
}

void displayBoard() {
    for (int i = 0; i < NUMOFALPHA; i++) {
        if (count(head[i]) > 0) {
            printf("%c ->", (char)(i + 65));
            displayBook(head[i]);
            printf(";\n");
        }
    }
}

void updateBookName(char* ISBN, char* newBookName) {
    for (int i = 0; i < NUMOFALPHA; i++) {
        Node* current = head[i];
        Node* prev = NULL;
        while (current != NULL) {
            if (strcmp(current->ISBN, ISBN) == 0) {
                // Save ISBN to reuse
                char* savedISBN = strdup(current->ISBN);
                
                // Remove the node from current list
                if (prev == NULL) {
                    head[i] = current->next;
                } else {
                    prev->next = current->next;
                }

                // Free old node memory
                free(current->ISBN);
                free(current->name);
                free(current);

                // Insert it into the correct list with updated name
                insertBooks(savedISBN, newBookName);
                free(savedISBN);

                printf("[SUCCESS] Book name updated and moved to proper node!\n");
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    printf("[ERROR] Book with ISBN not found!\n");
}


void flush() {
    while (getchar() != '\n' && getchar() != EOF);
}

void storeLibrary(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("[ERROR] File could not be opened for writing!\n");
        return;
    }

    for (int i = 0; i < NUMOFALPHA; i++) {
        Node* temp = head[i];
        while (temp != NULL) {
            fprintf(file, "%s|%s|%d\n", temp->ISBN, temp->name, temp->copies);
            temp = temp->next;
        }
    }
    fclose(file);
    printf("[SUCCESS] Library data stored to file!\n");
}


void loadLibrary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("[INFO] No previous library file found. Starting fresh!\n");
        return;
    }

    char line[300];
    while (fgets(line, sizeof(line), file)) {
        char* isbn = strtok(line, "|");
        char* name = strtok(NULL, "|");
        char* copiesStr = strtok(NULL, "\n");

        if (isbn && name && copiesStr) {
            int copies = atoi(copiesStr);

            // Add book with correct copies
            for (int i = 0; i < copies; i++) {
                insertBooks(isbn, name);
            }
        }
    }
    fclose(file);
    printf("[SUCCESS] Library data loaded from file!\n");
}


int mainWindow() {
    int ch;
    printf("+------------------------------------------------+\n");
    printf("|        Welcome to Axis library System          |\n");
    printf("+------------------------------------------------+\n");
    printf("| 1. Add Book                                    |\n");
    printf("| 2. Delete Book                                 |\n");
    printf("| 3. Search ISBN number                          |\n");
    printf("| 4. Update Bookname using ISBN                  |\n");
    printf("| 5. Save to library file                        |\n");
    printf("| 6. Display Library                             |\n");
    printf("| 7. Quit                                        |\n");
    printf("+------------------------------------------------+\n");
    printf("| Enter your choice:                             |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf("%d", &ch);
    flush();
    printf("+------------------------------------------------+\n");
    return ch;
}

void clear() {
    system("clear");
}

void wait() {
    printf("Press Enter to continue...");
    getchar();
}

void closeProgram() {
    storeLibrary(filename);
    clear();
    printf("Exiting and saving library data. Bye!\n");
    exit(0);
}