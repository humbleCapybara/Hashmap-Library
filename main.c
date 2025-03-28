// compiler command: gcc library.c main.c cases.c -o guilib `pkg-config --cflags --libs gtk+-3.0`
#include "library.h"

int main(int argc, char* argv[]) {
    loadLibrary(filename);
    clear();
    while (1) {
        int choice = mainWindow();
        switch (choice) {
            case 1: {
                createAddBookWindow(argc, argv);
                break;
            }

            case 2: {
                createDeleteBookWindow(argc, argv);
                break;
            }

            case 3: {
                // clear();
                // char ISBN[100];
                // printf("\n-------[Find Book by ISBN]-------\n");
                // printf("Enter ISBN: ");
                // fgets(ISBN, sizeof(ISBN), stdin);
                // ISBN[strcspn(ISBN, "\n")] = 0;
                // char* found = searchBook(ISBN);
                // if (found != NULL)
                //     printf("Book name: %s\n", found);
                // else
                //     printf("[ERROR] Book not found!\n");
                // wait();
                searchBookWindow(argc,argv);
                break;
            }

            case 4: {
                clear();
                char ISBN[100], newBookName[100];
                printf("Enter ISBN of the book you want to update: ");
                fgets(ISBN, sizeof(ISBN), stdin);
                ISBN[strcspn(ISBN, "\n")] = 0;

                printf("Enter new book name: ");
                fgets(newBookName, sizeof(newBookName), stdin);
                newBookName[strcspn(newBookName, "\n")] = 0;

                updateBookName(ISBN, newBookName);
                printf("[SUCCESS] Book name updated!\n");
                wait();
                break;
            }

            case 5:
                storeLibrary(filename);
                printf("[SUCCESS] Library saved!\n");
                wait();
                break;

            case 6:
                clear();
                displayBoard();
                wait();
                break;

            case 7:
                closeProgram();
                break;

            default:
                clear();
                printf("\n--: Please select a correct option :--\n");
                wait();
        }
    }

    return 0;
}