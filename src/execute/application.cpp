//
// Created by illidansr on 8/30/19.
//

#include "application.hpp"

namespace app{
    Application::Application(std::string path) {
        this->path_dir = std::move(path);
        boost::filesystem::path filepath = "aarr.conf";
        if (filepath.extension() == ".jpg"||filepath.extension() == ".png") // Heed the dot.
        {
            std::cout << filepath.stem() << " is a valid type."; // Output: "myFile is a valid type."
        }
        else
        {
            std::cout << filepath.filename() << " is an invalid type."; // Output: e.g. "myFile.cfg is an invalid type"
        }
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