
## Описание
Система интернет-магазина на C++ с PostgreSQL.(я умер пока делал, эта фигня не подключалась)

Сборка(храни вас Бог) - я делал вручную через VSку
mkdir build
cd build
cmake ..
make

БД
products_db
psql products_db < sql/tables.sql
psql products_db < sql/functions.sql
psql products_db < sql/triggers.sql
psql products_db < sql/procedures.sql
psql products_db < sql/sample_data.sql

Где что искать:
- include/ - заголовочные файлы
- src/ - исходный код
- sql/ - скрипты базы данных
- reports/ - отчеты