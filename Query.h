#ifndef QUERY
#define QUERY

//this class is defined in ch 15
#include<string>
#include<iostream>
#include<fstream>
#include<set>
#include<memory>
#include<algorithm>
#include<vector>
#include<map>
#include<iterator>

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::ostream;
using std::ifstream;
using std::set;
using std::set_intersection;
using std::vector;
using std::map;
using std::inserter;

class QueryResult;

class Query {
public:
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);

public:
	Query(const string &s) :q(new WordQuery(s)) {}
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	string rep() const { return q->rep(); }

	begin() { return q -> begin(); }

private:
	Query(shared_ptr<Query_base> query) : q(query) {}
	shared_ptr<Query_base> q;
};

ostream& operator<<(ostream &os, const Query &query)
{
	return os << query.rep();
}

class TextQuery {
public:
	typedef vector<string>::size_type line_no;

	TextQuery(ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> input;
	map<string, shared_ptr<set<line_no>>> result;
};

TextQuery::TextQuery(ifstream &ifile)
{

}

QueryResult TextQuery::query(const string&) const
{

}

class QueryResult {
public:
	typedef vector<string>::size_type line_no;
	friend ostream& operator<<(ostream&, const QueryResult&);
public:
	QueryResult(const string &s, shared_ptr<set<line_no>> set, shared_ptr<vector<string>> v) :word(s), nos(set), input(v) {}

private:
	string word;
	shared_ptr<set<line_no>> nos;
	shared_ptr<vector<string>> input;
};

ostream& operator<<(ostream& os, const QueryResult& q)
{

}

class Query_base{
	public:
		friend class Query;
	protected:
		using line_no = TextQuery::line_no; //for eval
		virtual ~Query_base() = default;
	private:
		//eval returns a QueryResult
		virtual QueryResult eval(const TextQuery&) const = 0;
		//rep represents the string searching
		virtual string rep() const = 0;

};

class WordQuery : public Query_base{
	public:
		friend class Query;
		WordQuery(const string &s):query_word(s){}

private:
		//define the virtual functions
		QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }
		string rep() const override { return query_word; }
		string query_word;

};

class NotQuery : public Query_base{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {}

	string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery &) const ;
	Query query;

};

QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);

	auto ret_lines = make_shared<set<line_no>>();

	auto beg = result.begin(), end = result.end();

	auto sz = result.get_file() -> size();

	for(size_t n = 0; n != sz; ++n){
		if(beg == end || *beg != n)
			ret_lines -> insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

inline Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);

	auto ret_lines = make_shared<set<line_no>>();

	auto beg = result.begin(), end = result.end();

	auto sz = result.get_file()->size();
	for(size_t n = 0; n != sz; ++n){
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

class BinaryQuery : public Query_base{
	protected:
		BinaryQuery(const Query &l, const Query &r, string s):lhs(l),rhs(r),opSym(s) {}
		//no define of eval cause this is an abstract class
		string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

		Query lhs,rhs;
		string opSym;

};

class OrQuery : public BinaryQuery{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery &) const ;

};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
	//the virtual function
	//use eval to return the QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	//copy the result to set
	auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
	ret_lines -> insert(right.begin(), right.end());
	//return a new QueryResult
	return QueryResult(rep(), ret_lines, left.get_file());
}

class AndQuery : public BinaryQuery{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right):BinaryQuery(left, right, "&") {}

	QueryResult eval(const TextQuery&) const ;

};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();

	//use intersection to coordite two set
	set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

#endif
