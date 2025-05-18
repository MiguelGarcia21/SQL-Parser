# Header Files Overview

The `include/` directory contains all header files that define the structure and logic of the SQL parser.

---

## 📄 AST.hpp

Defines the **Abstract Syntax Tree (AST)**:
- `SelectStatement`: Holds a list of columns, table name, and optional `Condition`.
- `Condition`: Represents a simple `column=value` expression for WHERE clauses.

🔧 **Expandable Features**:
- Support more complex WHERE expressions: `AND`, `OR`, comparison operators (`<`, `>`, etc.)
- Add support for `JOIN`, `ORDER BY`, `GROUP BY`, etc.
- Support INSERT/UPDATE/DELETE queries

---

## 📄 SQLGrammar.hpp

Implements the **Boost.Spirit grammar** for parsing:
- Identifiers (column/table names)
- Column lists
- Simple WHERE condition
- Full SELECT statement rule

🔧 **Expandable Features**:
- Add operator precedence parsing for complex WHERE conditions
- Add support for string literals and numbers
- Support quoted identifiers (e.g., `"user name"`)

---

## 📄 SQLParser.hpp

Public-facing class that exposes:
```cpp
std::optional<ast::SelectStatement> parse(const std::string& input);
````

Handles parsing and returns a valid AST or `nullopt` on failure.

🔧 **Expandable Features**:

* Add detailed error reporting with position info
* Make `SQLParser` a non-static class to allow configuration
* Add more interfaces like `serialize()`, `toSQL()`, etc.

---

🧱 This directory is used as the foundation to extend SQL parsing logic cleanly and modularly.

````