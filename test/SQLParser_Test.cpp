#include "SQLParser.hpp"
#include <gtest/gtest.h>

using namespace sql;

TEST(SQLParserTest, ValidSelectWithoutWhere) {
    std::string input = "SELECT name, age FROM users";
    auto result = SQLParser::parse(input);
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result->columns.size(), 2);
    EXPECT_EQ(result->columns[0], "name");
    EXPECT_EQ(result->table, "users");
    EXPECT_FALSE(result->whereClause.has_value());
}

TEST(SQLParserTest, ValidSelectWithWhere) {
    std::string input = "SELECT id FROM customers WHERE id=42";
    auto result = SQLParser::parse(input);
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result->columns[0], "id");
    EXPECT_EQ(result->table, "customers");
    ASSERT_TRUE(result->whereClause.has_value());
    EXPECT_EQ(result->whereClause->column, "id");
    EXPECT_EQ(result->whereClause->value, "42");
}

TEST(SQLParserTest, InvalidSQL) {
    std::string input = "DELETE FROM users";
    auto result = SQLParser::parse(input);
    EXPECT_FALSE(result.has_value());
}