#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <boost/filesystem.hpp>
#include "../face_detect/face_detect.hpp"
#include "application.hpp"

//using namespace boost::system;
//namespace filesys = boost::filesystem;
//
//std::vector<std::string> getAllFilesInDir(const std::string &dirPath, 	const std::vector<std::string> dirSkipList = { })
//{
//
//    // Create a vector of string
//    std::vector<std::string> listOfFiles;
//    try {
//        // Check if given path exists and points to a directory
//        if (filesys::exists(dirPath) && filesys::is_directory(dirPath))
//        {
//            // Create a Recursive Directory Iterator object and points to the starting of directory
//            filesys::recursive_directory_iterator iter(dirPath);
//
//            // Create a Recursive Directory Iterator object pointing to end.
//            filesys::recursive_directory_iterator end;
//
//            // Iterate till end
//            while (iter != end)
//            {
//                // Check if current entry is a directory and if exists in skip list
//                if (filesys::is_directory(iter->path()) &&
//                    (std::find(dirSkipList.begin(), dirSkipList.end(), iter->path().filename()) != dirSkipList.end()))
//                {
//                    // Skip the iteration of current directory pointed by iterator
//#ifdef USING_BOOST
//                    // Boost Fileystsem  API to skip current directory iteration
//					iter.no_push();
//#else
//                    // c++17 Filesystem API to skip current directory iteration
//                    iter.disable_recursion_pending();
//#endif
//                }
//                else
//                {
//                    // Add the name in vector
//                    listOfFiles.push_back(iter->path().string());
//                }
//
//                error_code ec;
//                // Increment the iterator to point to next entry in recursive iteration
//                iter.increment(ec);
//                if (ec) {
//                    std::cerr << "Error While Accessing : " << iter->path().string() << " :: " << ec.message() << '\n';
//                }
//            }
//        }
//    }
//    catch (std::system_error & e)
//    {
//        std::cerr << "Exception :: " << e.what();
//    }
//    return listOfFiles;
//}

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

    for (auto str : listOfFiles)
        std::cout << str << std::endl;
    return 0;
}