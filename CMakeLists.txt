cmake_minimum_required(VERSION 3.10)
project(store)

set(CMAKE_CXX_STANDARD 17)

# Заголовки проекта
include_directories(include)

# Пути к libpqxx (Mingw64)
include_directories(C:/msys64/mingw64/include)
link_directories(C:/msys64/mingw64/lib)

# Все исходные файлы
add_executable(store
    src/main.cpp
    src/User.cpp
    src/Admin.cpp
    src/Manager.cpp
    src/Customer.cpp
    src/Order.cpp
    src/OrderItem.cpp
    src/Product.cpp
    src/Payment.cpp
    src/PaymentStrategy.cpp
)

# Подключение библиотек
target_link_libraries(store pqxx pq)