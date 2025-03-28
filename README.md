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
📂 Library-Management-System/<br>
│── 📜 library.h # Header file containing struct definitions & function prototypes <br>
│── 📜 library.c # Implementation of library management functions <br>
│── 📜 main.c # Main program with user interface logic <br>
│── 📜 library.txt # Data file storing book records (generated at runtime) <br>
│── 📜 README.md # Project documentation<br>

## Shell

## 🛠️ Compilation & Execution (Linux/WSL)
### 🔨 Compile the program:
```bash
gcc library.c main.c cases.c -o guilib `pkg-config --cflags --libs gtk+-3.0`
```
## Run the Program
```
./library
```

## How to use?
```
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
```

## 🎯 Functionality of Each Option
1️⃣ Add Book – Allows the user to insert a new book by entering the ISBN number and book name. If the book already exists, the number of copies is incremented instead. <br>
2️⃣ Delete Book – Removes a book from the system based on the ISBN number. If the book is found, it gets deleted; otherwise, an error message is displayed. <br>
3️⃣ Search ISBN Number – Lets the user search for a book using its ISBN. If found, the book's name is displayed; otherwise, an error message is shown. <br>
4️⃣ Update Book Name Using ISBN – Updates the title of an existing book while ensuring it remains in the correct alphabetical category. <br>
5️⃣ Save to Library File – Saves all book records into library.txt, ensuring data persistence even after the program is closed. <br>
6️⃣ Display Library – Displays the entire book collection, organized alphabetically by the first letter of the book name. <br>
7️⃣ Quit – Exits the program after saving all book records to prevent data loss.



## Future Enhancements (Ideas 💡)
--> Borrow & Return System – Track issued books. <br>
--> User Accounts – Implement a login system. <br>
--> GUI Interface – A simple graphical frontend for better usability. <br>

## Why This Project?
This project demonstrates data structures (linked lists & hashmaps), file handling, and modular programming in C. It's designed to be lightweight, efficient, and extendable.

# Open-Source License 🚀
This project is open-source under the MIT License. That means you are free to use, modify, and distribute this software however you like!

Feel free to:<br>
✅ Use it in your own projects<br>
✅ Modify it to fit your needs<br>
✅ Share it with others<br>

Just make sure to include the original license and credit where due.<br>

# Legal Stuff
This software is provided "as is," without any guarantees. I’m not responsible for any issues that may arise from using it. Use at your own risk!
