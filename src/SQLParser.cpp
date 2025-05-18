#include "SQLParser.hpp"
#include "SQLGrammar.hpp"

#include <boost/spirit/home/x3.hpp>

namespace sql {

std::optional<ast::SelectStatement> SQLParser::parse(const std::string& input) {
    ast::SelectStatement stmt;
    auto iter = input.begin();
    auto end = input.end();

    bool r = phrase_parse(iter, end,
                          parser::parser,
                          boost::spirit::x3::ascii::space, stmt);

    if (r && iter == end) {
        return stmt;
    }
    return std::nullopt;
}

} // namespace sql