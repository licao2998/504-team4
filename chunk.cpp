#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

int regroup(int nParts);

int main(int argc, char * argv[])
{   //variables
    std::ostringstream sStringer;
    ifstream::pos_type nSize;
    ifstream fSource(argv[1], ios_base::ate|ios::binary|ios::in);
    char * sMemBlock;
    nSize = fSource.tellg();
    string sExtension = strstr(argv[1],".");
    int nGetPointer = 0;
    string sChunkSize = argv[2];
    istringstream nIntegerer(sChunkSize);
    int nChunkSize;
    nIntegerer >> nChunkSize;
    int nLastChunkSize = nChunkSize;
    int nPartNumber = 1;
    string sDestinationFile;

    if (fSource.is_open())
    {
        cout << "File input : " << argv[1] << endl;
        cout << "Size : " << nSize << " bytes"<< endl;
        cout << "Extension : " << sExtension << endl <<endl;

        fSource.seekg(0, ios::beg);

        while (fSource)
        {
            fSource.seekg(nGetPointer, ios::beg);

            if (nGetPointer + nChunkSize > nSize)
            {
                while (nGetPointer + nLastChunkSize > nSize)
                {
                    nLastChunkSize--;
                }
                sMemBlock = new char[nLastChunkSize];
                fSource.read(sMemBlock, nLastChunkSize);
            }
            else
            {
                sMemBlock = new char[nChunkSize];
                fSource.read(sMemBlock, nChunkSize);
            }

            sDestinationFile = argv[1];
            sDestinationFile.append(".part");
            sStringer.str("");
            sStringer << nPartNumber;
            sDestinationFile.append(sStringer.str());

            cout << "Destination file : " << sDestinationFile << endl;
            cout << "Chunk Size : " << nLastChunkSize << endl;
            ofstream fDestination(sDestinationFile.c_str());
            fDestination.write(sMemBlock, nLastChunkSize);

            nGetPointer += nChunkSize;
            nPartNumber += 1;
        }
        regroup(nPartNumber-1);
    }
    return 0;
}

int regroup(int nParts)
{
    string sChunkFile;
    std::ostringstream sStringer;
    int nPartNumber = 1;
    char * sMemBlock;
    ifstream::pos_type nSize;

    ofstream fRetour("recup.avi");

    for (nPartNumber = 1; nPartNumber <= nParts; nPartNumber++)
    {
        sChunkFile = "episode.avi";
        sChunkFile.append(".part");
        sStringer.str("");
        sStringer << nPartNumber;
        sChunkFile.append(sStringer.str());
        ifstream fChunk(sChunkFile.c_str(), ios::in|ios::binary|ios::ate);
        nSize = fChunk.tellg();
        sMemBlock = new char[nSize];
        fChunk.seekg(0, ios::beg);
        fChunk.read(sMemBlock, nSize);
        fChunk.close();
        fRetour.write(sMemBlock, nSize);
    }
    fRetour.close();
    return 0;
}