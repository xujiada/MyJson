
#include "MyJson.h"
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("myjson.txt");
	string str = "";
	string tmp;
	while (getline(in, tmp)) str += tmp;
	MyJson::value v = MyJson::parse::parser(str);
	cout << v.to_string() << endl;
	
	cout << endl << v["xujiada"][0]["age"].get_int_value() << endl;
	cout << v["xujiada"][1]["array"].to_string() << endl;
	cout << v["xujiada"][0]["major"].as_string() << endl;

	if (v["xujiada"][1]["bool"].get_bool()){
		cout << v["xujiada"][1][2].get_double_value() << endl;
		cout << v["xujiada"][1][5].to_string() << endl;
	}
	cout << v["xujiada"][2]["add"].as_string() << endl;
	cout << v["xujiada"][2]["add"].to_string() << endl;

	cout << v["xujiada"][3][0].get_exponent_value() << endl;
	cout << v["xujiada"][3][0].get_type() << endl;

	return 0;
}