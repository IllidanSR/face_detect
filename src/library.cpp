#include "include/library.h"

#include <iostream>

namespace face_detect {
    typedef boost::property_tree::ptree Ptree;

    void create_json(std::vector<cv::Rect> &faces) {
        std::cout << "Face number : " << faces.size() << std::endl;
        Ptree pt;
        for (size_t i = 0; i < faces.size(); i++) {

            Ptree children;
            Ptree child1, child2, child3, child4;

            child1.put("", faces[i].x);
            child2.put("", faces[i].y);
            child3.put("", faces[i].x + faces[i].width);
            child4.put("", faces[i].y + faces[i].height);

            children.push_back(std::make_pair("", child1));
            children.push_back(std::make_pair("", child2));
            children.push_back(std::make_pair("", child3));
            children.push_back(std::make_pair("", child4));

            pt.add_child(std::to_string(i), children);
        }
        boost::property_tree::json_parser::write_json("result.json", pt);
    }

    void find_face(std::string path) {
        cv::CascadeClassifier cascadeClassifier;
        cv::Mat image;
        try {
            /*!@brief change hardname to configloaded name*/
            cascadeClassifier.load("../configs/haarcascade_frontalface_default.xml");
        } catch (cv::Exception &exception) {
            std::cerr << "Could not open or find cascade classifier" << std::endl;
        }

        image = cv::imread(path.c_str(), cv::IMREAD_COLOR);
        if (image.empty()) {
            std::cerr << "Could not open or find file" << std::endl;
            return;
        }
        std::vector<cv::Rect> faces;
        cascadeClassifier.detectMultiScale(image,
                                           faces);

        create_json(faces);
        std::cout << "End work with this file : " << std::endl;
        std::cout << "PATH : " << path << std::endl;

    };
}