#pragma once
#include "AST.hpp"
#include <boost/spirit/home/x3.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::Condition, column, value)
BOOST_FUSION_ADAPT_STRUCT(sql::ast::SelectStatement, columns, table, whereClause)

namespace sql::parser {
    namespace x3 = boost::spirit::x3;

    x3::rule<class identifier, std::string> const identifier = "identifier";
    auto const identifier_def = x3::lexeme[+x3::char_("a-zA-Z0-9_")];

    x3::rule<class column_list, std::vector<std::string>> const column_list = "column_list";
    auto const column_list_def = (x3::lit('*') >> x3::attr(std::vector<std::string>{"*"})) | (identifier % ',');


    x3::rule<class condition, ast::Condition> const condition = "condition";
    auto const condition_def = identifier >> '=' >> identifier;

    x3::rule<class select_stmt, ast::SelectStatement> const select_stmt = "select_stmt";
    auto const select_stmt_def =
        x3::lit("SELECT") >> column_list >>
        x3::lit("FROM") >> identifier >>
        -(x3::lit("WHERE") >> condition);

    BOOST_SPIRIT_DEFINE(identifier, column_list, condition, select_stmt)

    auto const parser = select_stmt;
}
