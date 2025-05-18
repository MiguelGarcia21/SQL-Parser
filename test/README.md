# SQL Parser Unit Tests

This folder contains **GoogleTest** unit tests validating the behavior and robustness of the SQL parser.

---

## 🧪 What is Tested?

### ✅ Valid Queries
Ensures the parser correctly handles well-formed input:
- Basic SELECT:
  - `SELECT id FROM users`
  - `SELECT id, name FROM customers`
- SELECT with WHERE:
  - `SELECT name FROM employees WHERE age=30`
- SELECT with asterisk:
  - `SELECT * FROM inventory WHERE category=electronics`

### ❌ Invalid Queries
Ensures invalid or malformed queries are rejected:
- `SELECT` with no columns
- Missing `FROM`
- Bad WHERE clause format
- Typos or incomplete statements

### ✨ Edge Cases
- Extra spaces/tabs/newlines
- Case sensitivity
- No WHERE clause present
- Identifiers with underscores and numbers

---

## 🧱 File Structure

### 📄 SQLParser_Test.cpp

- Uses `EXPECT_TRUE` / `EXPECT_FALSE` to check parser results
- Extracts and compares AST structure if parsing succeeds

---

🛠️ **How will Test Extend**

- Add support for more operators and verify parsing
- Include negative tests for edge case failures
- Benchmark and fuzz-test larger SQL inputs

---

✅ These tests ensure the parser's reliability and help detect regressions as new grammar features are added.
````