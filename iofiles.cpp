
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


int main(){


    std::ofstream outfile;
    outfile.open("Hello.txt");

    if (outfile) {
        outfile << "This is first line\n";
        outfile << "This is second line\n";
        std::vector<int> v = {1,2,3};
        for (auto& val: v) {
            outfile << val << " ";
        }

        outfile.close();
    }

    outfile.open("Hello.txt", std::ostream::app);
    if (outfile) {
        outfile << "\nThis last line\n";
        outfile.close();
    }

    {
        std::ifstream ifile("Hello.txt");
        std::string str;
        if (ifile) {
            while (ifile) {
                ifile >> str;
                std::cout << str << " ";
            }
            ifile.close();
        }
    }
    {
        std::cout << "\n======================\n";
        std::ifstream ifile("Hello.txt");
        if (ifile) {
            std::string str;
            while (getline(ifile, str)) {
                std::cout << str << std::endl;
            }
        }
    }


    return 0;
}
