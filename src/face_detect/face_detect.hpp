//
// Created by illidansr on 8/30/19.
//
/*! @file face_detect/face_detect.hpp
 * @details face detect test component component must
 * show the number of persons in the frame, coords face on
 * frame and write it to .json file*/

#ifndef FACE_DETECTION_FACE_DETECT_HPP
#define FACE_DETECTION_FACE_DETECT_HPP

#include <string>
#include <vector>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <opencv2/opencv.hpp>


namespace face_detect {///< @namespace face_detect
    typedef boost::property_tree::ptree Ptree;
    /*!@brief support function to create JSON file
     * @param[in] faces vector detected face
     * @details function get vector of faces and generate JSON file
     * @author IllidanSR
     * @version 1.0
     * @date 30.08.19*/
    void create_json(std::vector<cv::Rect> &faces){
        std::cout << "Face number : " << faces.size() << std::endl;
        Ptree pt;
        for( size_t i = 0; i < faces.size(); i++ ) {

            Ptree children;
            Ptree child1, child2, child3, child4;

            child1.put("", faces[i].x);
            child2.put("", faces[i].y);
            child3.put("", faces[i].x + faces[i].width);
            child4.put("",faces[i].y + faces[i].height);

            children.push_back(std::make_pair("", child1));
            children.push_back(std::make_pair("", child2));
            children.push_back(std::make_pair("", child3));
            children.push_back(std::make_pair("", child4));

            pt.add_child(std::to_string(i), children);
        }
        boost::property_tree::json_parser::write_json("result.json", pt);
    }

    /*!@brief main function to find face on picture
     * @param[in] path path to file
     * @details function get path to file, verf is file can be open
     * @author IllidanSR
     * @version 1.0
     * @date 30.08.19
     * @throw if file can't be open - generate cv::Exception */
    std::vector<cv::Rect> find_face(cv::Mat frame){
        cv::CascadeClassifier cascadeClassifier;
        cv::Mat image;
        try {
            /*!@brief change hard-name to config-loaded name*/
            cascadeClassifier.load("../configs/haarcascade_frontalface_default.xml");
        }catch (cv::Exception &exception){
            std::cerr << "Could not open or find cascade classifier" << std::endl;
        }

//        image = cv::imread(path.c_str(), cv::IMREAD_COLOR);
        if(frame.empty()){
            std::cerr << "No frame" << std::endl;
        }
        std::vector<cv::Rect> faces;
        cascadeClassifier.detectMultiScale(image,
                faces);

        create_json(faces);
        std::cout << "End work with this file : " << std::endl;
        return faces;
    };



}
#endif //FACE_DETECTION_FACE_DETECT_HPP
