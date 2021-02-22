#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

template<typename T> void printVector(const std::vector<T>&v) {
    for (auto &val: v) {
        std::cout << val << " ";
    }
}

template<typename T>  std::vector<T> readNumbersFromTextFile(const char *filename) {
    std::vector<T> v;
    T val;
    std::cout << "Opening file: " << filename<<std::endl;
    std::ifstream ifile;
    ifile.open(filename);
    if (ifile) {
        std::string line;
        while (getline(ifile, line)) {
            std::stringstream is(line);
            while (is>>val) {
                v.push_back(val);
            }
        }
        ifile.close();
    }
    return v;

}
class FileException{
private:
    std::string _msg;
public:
    FileException(std::string msg): _msg(msg){};
    std::string getMessage(){return _msg;}
};

template<typename T> std::vector<T> readNumbersFromTextFile2(const char* filename){
    std::vector<T> v;
    try {
        std::fstream ifile(filename);
        if (ifile) {
            T val;
            while (ifile >> val) {
                v.push_back(val);
            }
            ifile.close();
        } else {
            throw FileException("File not open!");
        }
    } catch (FileException &e) {
        std::cout << e.getMessage();
    }
    return v;
}

int main() {

    std::vector<int> v;

    v = readNumbersFromTextFile2<int>("Number.txt");

    printVector<int>(v);
    return 0;
}


