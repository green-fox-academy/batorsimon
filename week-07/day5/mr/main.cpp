#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct temperature_record {
	long timestamp;
	int temperature;
};

temperature_record parseString(string line) {
	int temperature;

	istringstream exampleStream(line);
	tm parsedDateTime;
	exampleStream >> get_time(&parsedDateTime, "%Y.%m.%d %H:%M:%S")
			>> temperature;
	if (exampleStream.fail()) {
		throw "Invalid string format!";
	}


	if (-273 > temperature || 1000 < temperature) {
		throw "Temperature is out of range!";
	}

	long timestamp = mktime(&parsedDateTime);

	temperature_record rec;
	rec.temperature = temperature;
	rec.timestamp = timestamp;
	return rec;
}
;

int main() {
	string date, time;
	int temperature;

	string example = "2017.02.29 12:33:24 40";
	string badExample = "sdfg sdfgsd 0";

	/*
	for (;;) {
		// get line
		string line = "xx";
		try {
			temperature_record rec = parseString(line);
			// handle success
		}
		catch (const char* exception) {
			// ignore bad records
		}

	}*/

	try {
		temperature_record good = parseString(example);
		cout << "good.temperature: " << good.temperature << ", good.timestamp: " << good.timestamp << endl;
		temperature_record bad = parseString(badExample);
		cout << "you won't see me" << endl;
	}
	catch (const char *exception) {
		cout << "Something went wrong: " << exception << endl;
	}


}
