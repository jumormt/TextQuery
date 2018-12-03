#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "query_base.h"

/**
 * @brief The WordQuery class
 *The only class that actually performs a query on the given TextQuery object.
 *No public members defined in this class. All operation are through the friend
 *class Query.
 */
class WordQuery : public Query_base
{
    //! class Query uses the WordQuery constructor
    friend class Query;
    WordQuery(const std::string& s):
        query_word(s)
    {
        std::cout << "WordQuery::WordQuery(" + s + ")\n";
    }


    //! virtuals:（纯虚函数必须被覆盖，尽管他是基类中的私有变量）
    QueryResult eval(const TextQuery& t) const override
    {   return t.query(query_word); }
    std::string rep() const override
    {
        std::cout << "WodQuery::rep()\n";
        return query_word;
    }


    std::string query_word;
};

#endif // WORDQUERY_H
