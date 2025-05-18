# Simple SQL Parser (Boost.Spirit)

This project is a minimal, modular, and extensible **SQL parser** built using **Boost.Spirit X3** in C++. It's designed to parse basic SQL `SELECT` statements including optional `WHERE` clauses and demonstrate the use of recursive descent parsers using modern C++ and Boost libraries.

## 🔧 Project Structure

```

.
├── include/           # Header files (AST, Grammar, Parser)
│   ├── AST.hpp
│   ├── SQLGrammar.hpp
|   ├── SQLParser.hpp
│   └── README.md      # Document with implement files explanation
├── src/               # Implementation (.cpp) files
│   └── SQLParser.cpp
├── test/              # GoogleTest-based unit tests
|   ├── README.md      # Document with test file explanation
│   └── SQLParser\_Test.cpp
├── main.cpp           # Demo driver to manually test queries
├── bin/               # Compiled binaries (not tracked but standard for building)
└── README.md          # This file

```

## 📘 What This Project Does

1. **Defines an AST** (Abstract Syntax Tree) for SQL queries.
2. **Implements a parser** using Boost.Spirit to convert raw SQL strings into structured C++ data.
3. **Handles basic SQL SELECT syntax** including:
   - Selecting multiple columns or `*`
   - A single table
   - Optional `WHERE` clause with a simple `column=value` condition
4. **Runs the parsed result through a visual output in `main.cpp`.**
5. **Includes GoogleTest unit tests** to validate parsing behavior and handle edge cases.

## ▶️ Execution

1. User inputs a SQL string (e.g., `"SELECT id FROM users WHERE age=30"`).
2. The parser attempts to match the input to grammar rules defined in Boost.Spirit X3.
3. If successful, the string is converted into a C++ `SelectStatement` object.
4. This structured object is printed or validated through tests.

## 📥 Sample Input and Output

**Input SQL Queries (from `main.cpp`):**
```sql
SELECT name, age FROM users
SELECT id FROM customers WHERE id=42
SELECT * FROM products WHERE price=100
SELECT col1,col2 FROM t WHERE col3=value
SELECT wrong
```
Output:
```cpp
Input: "SELECT name, age FROM users"
Parsed SELECT statement:
  Columns: name age 
  Table: users
  WHERE: (none)
----------------------------------------
Input: "SELECT id FROM customers WHERE id=42"
Parsed SELECT statement:
  Columns: id 
  Table: customers
  WHERE: id = 42
----------------------------------------
Input: "SELECT * FROM products WHERE price=100"
Parsed SELECT statement:
  Columns: * 
  Table: products
  WHERE: price = 100
----------------------------------------
Input: "SELECT col1,col2 FROM t WHERE col3=value"
Parsed SELECT statement:
  Columns: col1 col2 
  Table: t
  WHERE: col3 = value
----------------------------------------
Input: "SELECT wrong"
 Failed to parse SQL.
----------------------------------------
```
## 💡 Why This Project?

- Shows real-world usage of Boost.Spirit for DSL parsing.
- Offers a simple base that can be expanded into a full SQL engine.
