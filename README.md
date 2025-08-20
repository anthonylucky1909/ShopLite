# ShopLite

[![C++][cpp-badge]][cpp-url]
[![License][license-badge]][license-url]

_👀 Lightweight command-line e-commerce system with multiple user roles_

## [Live Demo 💥](#) *(CLI app – run locally)*

## Install / Build

```bash
# Build project
make

# Run application
./main

# Clean build artifacts
make clean
```

## Features

- 🔐 User registration & login  
- 🛍️ Seller: add, modify, delete products  
- 💳 Buyer: browse, search, purchase products  
- 🛠️ Admin: manage users and transactions  

## Example Usage

```bash
# Register new user
> Username: user1
> Password: 1
→ Account created successfully

# Login
> Username: user1
> Password: 1
→ Login successful
```

## Project Structure

| File                     | Description                     |
|--------------------------|---------------------------------|
| `main.cpp`               | Program entry point             |
| `admin.cpp/hpp`          | Admin functionalities           |
| `seller.cpp/hpp`         | Seller operations               |
| `transaction.cpp/hpp`    | Purchase and order logic        |
| `information.cpp/hpp`    | User information management     |
| `control.cpp/hpp`        | Main logic and flow control     |
| `open.cpp / refresh.cpp` | Init & data refresh             |
| `Makefile`               | Compile & clean script          |
| `main`                   | Compiled binary                 |
| `.o files`               | Intermediate object files       |
| `*.pdf / *.ppt`          | User manual and usage guides    |

## Contributing

All contributions are welcome!  
Please review [Issues](#) or submit a [Pull Request](#).

---

[cpp-badge]: https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white
[cpp-url]: https://isocpp.org/
[license-badge]: https://img.shields.io/badge/license-MIT-green
[license-url]: https://opensource.org/licenses/MIT

