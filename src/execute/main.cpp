#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <thread>
#include "../image_processing/image_processing.hpp"
#include "../application/application.hpp"


int main(int argc, char** argv) {

    app::Application application;
    ///@brief read terminal pars
    std::string dirPath;
    for(int i = 0; i < argc; i++){
        dirPath = argv[i];
    }
    /*!@brief list of files, founded in dir*/
    std::vector<std::string> listOfFiles = application.get_all_file_in_dir(dirPath);

    auto imageProcessing = new image_processing::ImageProcessing();

    for(size_t i = 0; i < listOfFiles.size(); i++){
        boost::filesystem::path filepath = listOfFiles[i];
        if (filepath.extension() == ".jpg"||filepath.extension() == ".png")
        {
            std::cout << "NAME : " << filepath.stem() << std::endl;
            std::cout << "FRAME : " << listOfFiles[i] << std::endl;
            cv::Mat picture = cv::imread(listOfFiles[i]);
            std::thread th(&image_processing::ImageProcessing::image_processing,
                    imageProcessing, picture, filepath.stem().string()
                                              +filepath.extension().string());
            th.join();
        }
        else
        {
            std::cout << listOfFiles[i] << " is not pict" << std::endl;
        }
    }
    delete imageProcessing;
    return 0;
}