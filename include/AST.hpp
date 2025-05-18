#pragma once
#include <string>
#include <vector>
#include <optional>

namespace sql::ast {

struct Condition {
    std::string column;
    std::string value;
};

struct SelectStatement {
    std::vector<std::string> columns;
    std::string table;
    std::optional<Condition> whereClause;
};

} // namespace sql::ast
