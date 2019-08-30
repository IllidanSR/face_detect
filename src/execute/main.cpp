#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include "../image_processing/image_processing.hpp"
#include "application.hpp"


int main(int argc, char** argv) {

    app::Application application;
    ///@brief read terminal pars
    std::string dirPath;
    for(int i = 0; i < argc; i++){
        dirPath = argv[i];
    }
    std::vector<std::string> listOfFiles = application.get_all_file_in_dir(dirPath);

    for(size_t i = 0; i < listOfFiles.size(); i++){
        boost::filesystem::path filepath = listOfFiles[i];
        if (filepath.extension() == ".jpg"||filepath.extension() == ".png")
        {
            std::cout << "FRAME : " << listOfFiles[i] << std::endl;
            cv::Mat picture = cv::imread(listOfFiles[i]);
            image_processing::ImageProcessing imageProcessing;
            imageProcessing.image_processing(picture, listOfFiles[i]);
        }
        else
        {
            std::cout << listOfFiles[i] << " is not pict" << std::endl;
        }
    }
    return 0;
}