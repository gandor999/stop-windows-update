#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <array>

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

    return token;
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

bool isValidParameter(string word)
{
    string validParameters[] = {"downloadPath"};
    bool isValid = false;

    for (int i = 0; i < sizeof(validParameters); ++i)
    {
        if (word == validParameters[i])
        {
            isValid = true;
            break;
        }
    }

    return isValid;
}

map<string, string> getHashMap()
{
    map<string, string> hashMap;

    hashMap.insert({"greeting", "hello-world"});

    return hashMap;
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

    mapStorage.insertKeyValuePair("greeting", "hello-world");

    cout << mapStorage.getValueOfKey("greeting");

        // cout << "\n";
    // cout << "\n";

    // cout << getArgument("greeting: hello-world");

    // cout << "\n";
    // cout << "\n";

    // cout << getHashMap()["greeting"];
}