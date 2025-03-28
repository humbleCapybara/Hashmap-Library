# 📚 Library Management System (C Program)

## 📌 Overview
This is a **Library Management System** written in C that allows users to manage book records efficiently using **linked lists**. It provides functionalities to **add, delete, search, update, and display books** using their **ISBN numbers**. Books are categorized alphabetically, and the system supports **persistent storage** using a file.

## 🚀 Features
- ✅ **Add Books** – Insert new books and handle duplicate ISBNs by increasing copy count.
- ✅ **Delete Books** – Remove books from the library using ISBN.
- ✅ **Search Books** – Find books quickly using their ISBN.
- ✅ **Update Book Names** – Modify book titles while keeping alphabetical organization.
- ✅ **Display Library** – Show all books grouped by their starting letter.
- ✅ **Persistent Storage** – Save and load books from `library.txt` for data retention.

## 🏗️ Project Structure
📂 Library-Management-System/
│── 📜 library.h # Header file containing struct definitions & function prototypes 
│── 📜 library.c # Implementation of library management functions 
│── 📜 main.c # Main program with user interface logic 
│── 📜 library.txt # Data file storing book records (generated at runtime) 
│── 📜 README.md # Project documentation

## Shell

## 🛠️ Compilation & Execution (Linux/WSL)
### 🔨 Compile the program:
```bash
gcc main.c library.c -o library
```
## Run the Program
./library

## How to use?
+------------------------------------------------+
|        Welcome to Axis Library System          |
+------------------------------------------------+
| 1. Add Book                                    |
| 2. Delete Book                                 |
| 3. Search ISBN number                          |
| 4. Update Book Name using ISBN                 |
| 5. Save to library file                        |
| 6. Display Library                             |
| 7. Quit                                        |
+------------------------------------------------+
Books are automatically saved in library.txt on exit.

## Future Enhancements (Ideas 💡)
--> Borrow & Return System – Track issued books.
--> User Accounts – Implement a login system.
--> GUI Interface – A simple graphical frontend for better usability.

## Why This Project?
This project demonstrates data structures (linked lists & hashmaps), file handling, and modular programming in C. It's designed to be lightweight, efficient, and extendable.

# Open-Source License 🚀
This project is open-source under the MIT License. That means you are free to use, modify, and distribute this software however you like!

Feel free to:
✅ Use it in your own projects
✅ Modify it to fit your needs
✅ Share it with others

Just make sure to include the original license and credit where due.

Legal Stuff:
This software is provided "as is," without any guarantees. I’m not responsible for any issues that may arise from using it. Use at your own risk!

Happy coding! 💻✨
