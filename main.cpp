#include <iostream>
#include <fstream>
#include <chrono>
#include <deque>
#include <thread>
#include <string>

using namespace std;

int main()
{
    const char *path = "sample.txt";

    ifstream in;
    in.open(path, ios::in | ios::binary);

    if (!in)
    {
        std::cerr << "Failed to open: " << path << std::endl;
        return 1;
    }

    in.clear();
    in.seekg(0, ios::end);
    streampos lastPos = in.tellg();

    int found = 0;
    for (int i = 2; lastPos > (streampos)0 && found < 10; i++)
    {
        in.seekg(-i, ios::end);
        int c = in.get();
        if (c == '\n')
            found++;
    }

    while (true)
    {
        in.clear();
        in.seekg(0, ios::end);
        streampos currPos = in.tellg();

        if (currPos > lastPos)
        {
            in.clear();
            in.seekg(lastPos);
            string tempLine;

            while (getline(in, tempLine))
            {
                if (!tempLine.empty())
                    cout << tempLine << endl;
            }

            in.clear();
            in.seekg(0, ios::end);
            lastPos = in.tellg();
        }
        else if (currPos < lastPos)
            lastPos = currPos;

        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return 0;
}