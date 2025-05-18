#pragma once
#include "AST.hpp"
#include <string>
#include <optional>

namespace sql {

class SQLParser {
public:
    static std::optional<ast::SelectStatement> parse(const std::string& input);
};

} // namespace sql
