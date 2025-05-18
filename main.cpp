#include "include/SQLParser.hpp"
#include <iostream>

void printSelectStatement(const sql::ast::SelectStatement& stmt) {
    std::cout << "Parsed SELECT statement:\n";
    std::cout << "  Columns: ";
    for (const auto& col : stmt.columns) {
        std::cout << col << " ";
    }
    std::cout << "\n  Table: " << stmt.table << "\n";

    if (stmt.whereClause.has_value()) {
        std::cout << "  WHERE: " << stmt.whereClause->column << " = " << stmt.whereClause->value << "\n";
    } else {
        std::cout << "  WHERE: (none)\n";
    }
    std::cout << "----------------------------------------\n";
}

int main() {
    std::vector<std::string> test_queries = {
        "SELECT name, age FROM users",
        "SELECT id FROM customers WHERE id=42",
        "SELECT * FROM products WHERE price=100",
        "SELECT col1,col2 FROM t WHERE col3=value",
        "SELECT wrong" // invalid
    };

    for (const auto& query : test_queries) {
        std::cout << "Input: \"" << query << "\"\n";
        auto result = sql::SQLParser::parse(query);
        if (result.has_value()) {
            printSelectStatement(result.value());
        } else {
            std::cout << " Failed to parse SQL.\n";
            std::cout << "----------------------------------------\n";
        }
    }

    return 0;
}
