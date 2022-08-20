#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

vector<string> getLinePhrases(string fileName)
{
    string myText;
    vector<string> linePhrases;

    ifstream fileInstance(fileName);

    while (getline(fileInstance, myText))
    {
        linePhrases.push_back(myText);
    }

    return linePhrases;
}

bool isValidParameter(string word)
{
    vector<string> validParameters = {"softwareDistributionDownloadPath", "validParameter"};

    if (find(validParameters.begin(), validParameters.end(), word) != validParameters.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

string getParameter(string linephrase)
{

    string token = "";

    for (int i = 0; i < linephrase.length(); ++i)
    {
        token += linephrase[i];

        if (linephrase[i + 1] == ':' || linephrase[i + 1] == ' ')
        {
            break;
        }
    }

    try
    {
        if (isValidParameter(token) == false)
        {
            throw(token);
        }
        else
        {
            return token;
        }
    }
    catch (string token)
    {
        string errMessage = "error: invalid parameter => " + token;
        cerr << errMessage << '\n';
        throw(token);
    }
}

string getArgument(string linePhrase)
{
    string token = "";

    for (int i = linePhrase.find(':') + 1; i < linePhrase.length(); ++i)
    {
        if (linePhrase[i] != ' ')
        {
            token += linePhrase[i];
        }
    }

    return token;
}

class MapStorage
{
private:
    map<string, string> hashMap;

public:
    MapStorage()
    {
    }

    void insertKeyValuePair(string key, string value)
    {
        this->hashMap.insert({key, value});
    }

    string getValueOfKey(string key)
    {
        return this->hashMap[key];
    }
};

int main()
{

    vector<string> linePhrases = getLinePhrases("hello.yaml");

    MapStorage mapStorage = MapStorage();

    for (string linePhrase : linePhrases)
    {
        cout << getParameter(linePhrase);
        cout << "\n";
        cout << "\n";
        cout << getArgument(linePhrase);

        cout << "\n";
        cout << "\n";
    }

    // cout << isValidParameter("greeting");

    // mapStorage.insertKeyValuePair("greeting", "hello-world");

    // cout << mapStorage.getValueOfKey("greeting");

    // cout << "\n";
    // cout << "\n";

    // cout << getArgument("greeting: hello-world");

    // cout << "\n";
    // cout << "\n";

    // cout << getHashMap()["greeting"];
}