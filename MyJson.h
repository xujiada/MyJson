#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <stdlib.h>
using namespace std;

namespace MyJson{

	enum MyType {
		MySTRING = 0,
		MyNUMBER = 1,
		MyOBJECT = 2,
		MyARRAY = 3,
		MYBOOL = 4,
		MyNULL = 5, 
		UNKOWN = 6
	};

	class value
	{
	public:
		string as_string();
		string to_string();
		
		double get_double_value();
		int get_int_value();
		double get_exponent_value();
		bool get_bool();
		void* get_null();
		value operator[](int);
		value operator[](string);
		MyType get_type();
		void set_type(MyType);
		void set_string(string value_s);
		void add_enement(value v);
		void add_property(string key, value v);
		value(MyType);
		string space(int);

	private:
		string s;
		MyType type;
		vector <value> vec;
		vector <pair < string, value> > object_map;
		map <string, int> m;
		string tostring(int);
	};

	class parse{
	public:
		static value parser(const string &str);

	private:
		enum parse_type { STRING, NUMBER, LEFR_BIG_BRACKET, RIGHT_BIG_BRACKET, LEFR_MID_BRACKET, RIGHT_MID_BRACKET, COMMA, COLON, BOOLEAN, NUL, UNKNOWN};
		
		struct push;
		static vector<push> push_data(string source);
		static value json_parse(vector<push> v, int i, int &r);

		static bool is_whitespace(const char c);
		static int next_whitespace(const string& source, int i);
		static int skip_whitespaces(const string& source, int i);
		
	};

}