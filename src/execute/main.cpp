#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <boost/filesystem.hpp>
#include "../face_detect/face_detect.hpp"
#include "application.hpp"


int main() {
//    std::string path;
//    std::cout << "IMPUT PATH TO FILE" << std::endl;
//    std::cin >> path;
//    face_detect::find_face(path);
    app::Application application("dss");
    std::string dirPath = "../resours";

    // Get recursive list of files in given directory and its sub directories
//    std::vector<std::string> listOfFiles = getAllFilesInDir(dirPath);
//
//    // Iterate over the vector and print all files
//    for (auto str : listOfFiles)
//        std::cout << str << std::endl;
//
//    std::cout << "**********************" << std::endl;
//
//    // Get recursive list of files in given directory and skip given folders
    std::vector<std::string> listOfFiles = application.get_all_file_in_dir(dirPath);

    for(size_t i = 0; i < listOfFiles.size(); i++){
        boost::filesystem::path filepath = listOfFiles[i];
        if (filepath.extension() == ".jpg"||filepath.extension() == ".png") // Heed the dot.
        {
            face_detect::find_face(listOfFiles[i]);
        }
        else
        {
            std::cout << listOfFiles[i] << " IS NOT VALID" << std::endl; // Output: e.g. "myFile.cfg is an invalid type"
        }
    }
    return 0;
}