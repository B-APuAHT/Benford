#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line;
    ifstream myfile;
    int decada[9];
    int num;
    int lineCount = 0;
    float percent;

    cout << ">> Benfrod's law <<" << endl;
    for (int i = 0; i < 9; i++)
        decada[i] = 0;
    myfile.open("data.txt");
    if (myfile.is_open()){
        cout << "Load data from file... ";
        while ( myfile.good() ){
          getline (myfile,line);
          line = line[0];
          num = atoi(line.c_str());
          decada[num - 1]++;
          lineCount++;
        }
        myfile.close();
        cout << "success" << endl;

        cout << "_____________________________________________" << endl;
        for (int i = 0; i < 9; i++){
            percent = 100.0f * decada[i] / lineCount;
            printf("  %i:  %1.2f%% \n",i + 1, percent);
        }
        cout << "_____________________________________________" << endl;
    }
    else cout << "Unable to open file" << endl;

    cout << "Press any key to exit" << endl;
    getchar();
    return 0;
}
