# Advanced E-Commerce Platform User Manual: OOP in C++ for Authentication, Product Management, and Admin Features 🛒📘

Welcome to the **Advanced E-Commerce Platform**! This project demonstrates various features of an e-commerce platform, implemented using **C++** and **Object-Oriented Programming (OOP)** principles. Below you will find an overview of the system’s components and basic operation steps.

---

## Project Overview 🚀

This platform supports multiple user roles, including buyers, sellers, and administrators. It covers authentication, product management, transaction handling, and more.

---

## Files in the Project 📂

Here is a brief description of the main files:

- **ppt+用户手册** - A PowerPoint file for the user manual.
- **Basic function operation steps-1.pdf** - A PDF guide explaining the basic functionalities of the platform.
- **Makefile** - Build automation script for compiling the project.
- **admin.cpp, admin.hpp** - The C++ implementation and header file for the admin-related functionalities.
- **control.cpp, control.hpp** - Files for controlling the program’s operations and handling user interactions.
- **information.cpp, information.hpp** - Handles user information, including personal details and preferences.
- **main** - The compiled executable for running the program.
- **main.cpp** - The main entry point for the platform program.
- **open.cpp, open.hpp** - Handles opening the platform and initializing the program.
- **refresh.cpp, refresh.hpp** - Manages refreshing the platform data.
- **seller.cpp, seller.hpp** - Seller-related functionality, such as managing products.
- **transaction.cpp, transaction.hpp** - Manages transactions between buyers and sellers.
- **.o files** - Object files that are generated after compiling C++ source files.

---

## Basic Function Operation Steps ⚙️

Here is a quick overview of how to run and interact with the platform:

1. **Build the Project** 🛠️:
    - Open the terminal and navigate to the project directory.
    - Run `make` to compile all the source files.

    ```bash
    make
    ```

2. **Run the Program** 🏃‍♂️:
    - After compilation, run the program using the following command:

    ```bash
    ./main
    ```

3. **Login/Registration** 🔑:
    - You can either **register** a new user or **login** with existing credentials.

4. **Product Management (Seller)** 🛍️:
    - Sellers can publish, modify, or remove products.
    - Buyers can browse, search, and purchase products.

5. **Admin Functions** 👨‍💻:
    - Admins can log in to manage users and view all products and transactions.

---

## Example Operations ⚡

Here are a few examples of how the platform operates:

- **Login/Register Example** 🔒:
    - **Input**: Choose to register with username "user1" and password "1".
    - **Output**: Registration successful, followed by an automatic login.

- **Seller Product Management** 🏷️:
    - **Input**: Seller registers product "test1" with price "10".
    - **Output**: Product successfully posted.

- **Buyer Operations** 💳:
    - **Input**: Buyer searches for "test".
    - **Output**: Product "test1" appears in the search results.

---

## Compilation and Cleaning 🧹

- **To compile the program**:
    - Run `make` in the terminal.
  
- **To clean the object files**:
    - Run `make clean` to remove the compiled `.o` files.

    ```bash
    make clean
    ```

---

## Emojis for Fun 😎✨

To make the platform a bit more interactive, we use a variety of emojis in our messages and outputs. From welcoming users to confirming transactions, these little icons add a fun touch to the experience. 🥳🎉

---

## Contribution 🤝

Feel free to contribute to the project! If you have any ideas, bug fixes, or improvements, open an issue or submit a pull request.

---

## License 📜

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

---

Thank you for checking out the **Advanced E-Commerce Platform**! 🎉
