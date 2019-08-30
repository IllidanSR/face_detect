//
// Created by illidansr on 8/30/19.
//

#include "application.hpp"

namespace app{
    Application::Application(std::string path) {
        this->path_dir = std::move(path);
    }

    std::vector<std::string> Application::get_all_file_in_dir(const std::string &dirPath,
            const std::vector<std::string> dirSkipList){
        std::vector<std::string> listOfFiles;
        try {
            if (filesys::exists(dirPath) && filesys::is_directory(dirPath))
            {
                filesys::recursive_directory_iterator iter(dirPath);
                filesys::recursive_directory_iterator end;
                while (iter != end)
                {
                    if (filesys::is_directory(iter->path()) &&
                        (std::find(dirSkipList.begin(), dirSkipList.end(), iter->path().filename()) != dirSkipList.end()))
                    {
#ifdef USING_BOOST
					iter.no_push();
#else
                        iter.disable_recursion_pending();
#endif
                    }
                    else
                    {
                        listOfFiles.push_back(iter->path().string());
                    }
                    error_code ec;
                    iter.increment(ec);
                    if (ec) {
                        std::cerr << "Error While Accessing : " << iter->path().string() << " :: " << ec.message() << '\n';
                    }
                }
            }
        }
        catch (std::system_error & e)
        {
            std::cerr << "Exception :: " << e.what();
        }
        return listOfFiles;
    }

    Application::~Application() {

    }
}