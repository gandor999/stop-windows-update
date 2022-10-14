#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <array>
#include <algorithm>
#include <bits/stdc++.h>

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

    vector<string> linePhrases = getLinePhrases("config.yaml");

    MapStorage mapStorage = MapStorage();

    // store key value pairs
    for (string linePhrase : linePhrases)
    {
        mapStorage.insertKeyValuePair(getParameter(linePhrase), getArgument(linePhrase));
    }

    string deleteDownloadDir = "rmdir /s " + mapStorage.getValueOfKey("softwareDistributionDownloadPath");
    const char *charDeleteDownloadDir = deleteDownloadDir.c_str();

    // commands to stop windows update and delete Download folder in SoftwareDistribution
    system("net stop wuauserv");
    system("sc config wuauserv start= disabled");

    bool isDeleted = system(charDeleteDownloadDir);

    if (isDeleted)
    {
        cout << "Unable to delete file or file has already been deleted\n";
    }
    else
    {
        cout << "File deleted\n";
    }

    system("pause");
}