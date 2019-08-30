//
// Created by illidansr on 8/30/19.
//
/*!@file execute/application.hpp
 * @defgroup application component
 * @details search all files in dir and return it
 * */


#ifndef FACE_DETECTION_APPLICATION_HPP
#define FACE_DETECTION_APPLICATION_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>


namespace app {///< @namespace app
    using namespace boost::system;
    namespace filesys = boost::filesystem;

    /*! @class Application
     * @brief Application class
     * @details get path and return vector of paths to every file in this dir
     * @author IllidanSR
     * @version 1.0
     * @date 30.08.19
     * @warning no warning
     * */
    class Application {
    public:
        Application(std::string path);
        /*!@brief generate_masked_image - external method to start image processing
         *
         * @param[in] dirPath dir path
         * @param[in] dirSkipList skip dir name
         * @return std::vector<std::string> vector of path to file*/

        std::vector<std::string> get_all_file_in_dir(const std::string &dirPath,
                                                     const std::vector<std::string> dirSkipList = { });
        ~Application();

    private:


        std::string path_dir;

    };
}


#endif //FACE_DETECTION_APPLICATION_HPP
