#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "../face_detect/face_detect.hpp"
#include "application.hpp"


int main(int argc, char** argv) {

    app::Application application("dss");
    ///@brief read terminal pars
    std::string dirPath;
    for(int i = 0; i < argc; i++){
        dirPath = argv[i];
    }
    std::vector<std::string> listOfFiles = application.get_all_file_in_dir(dirPath);

//    for(size_t i = 0; i < listOfFiles.size(); i++){
//        boost::filesystem::path filepath = listOfFiles[i];
//        if (filepath.extension() == ".jpg"||filepath.extension() == ".png")
//        {
//            face_detect::find_face(listOfFiles[i]);
//        }
//        else
//        {
//            std::cout << listOfFiles[i] << " is not pict" << std::endl;
//        }
//    }
    return 0;
}