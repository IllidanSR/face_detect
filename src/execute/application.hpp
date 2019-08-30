//
// Created by illidansr on 8/30/19.
//

#ifndef FACE_DETECTION_APPLICATION_HPP
#define FACE_DETECTION_APPLICATION_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>


namespace app {
    using namespace boost::system;
    namespace filesys = boost::filesystem;
    class Application {
    public:
        Application(std::string path);

        std::vector<std::string> get_all_file_in_dir(const std::string &dirPath,
                                                     const std::vector<std::string> dirSkipList = { });
        ~Application();

    private:


        std::string path_dir;

    };
}


#endif //FACE_DETECTION_APPLICATION_HPP
