#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getFileContents (ifstream&);

int main(int argc, char *argv[])
{
    cout << "Hello i am a reader program!" << endl;
    cout << "Type in the file you want to read with it's extension: ";
    string file_name;
    cin >> file_name;

    ifstream Reader (file_name.c_str());   //Open file
    string Art = getFileContents (Reader);   //Get file
    cout << Art << endl;                    //Print it to the screen
    Reader.close ();                       //Close file

    return 0;
}

string getFileContents (ifstream& File)
{
    string Lines = "";   //All lines

    if (File)   //Check if everything is good
    {
        cout << "The requested file:" << endl << endl;
        while (File.good ()) {
	    string TempLine;
	    getline (File, TempLine);
	    TempLine += "\n";       //Add newline character
	    Lines += TempLine;     //Add newline
        }
        return Lines;
    } else {
        return "ERROR File does not exist.";

    }
}
