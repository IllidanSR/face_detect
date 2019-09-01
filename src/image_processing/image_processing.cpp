//
// Created by illidansr on 8/30/19.
//

#include "image_processing.hpp"

namespace image_processing{

    ImageProcessing::ImageProcessing() {
        this->image_resize_cof_col = 0.5;
        this->image_resize_cof_row = 0.5;
    }

    void ImageProcessing::image_processing(cv::Mat image, std::string pict_name) {
        cv::Mat img = resize_image(image);
        std::vector<cv::Rect> face_coords = face_detect::find_face(image);
        cv::Mat blur_image;
        for(auto i : face_coords){
            blur_image = blur_region(image,i);
        }
        std::cout << "IMAGE NAME : " << pict_name << std::endl;
        save_file(pict_name, blur_image);
        create_json(face_coords,pict_name);
    }

    cv::Mat ImageProcessing::resize_image(cv::Mat frame) {
        cv::Mat output;
        try {
            cv::resize(frame, output, cv::Size(), 0.5, 0.5);
        }catch (cv::Exception &exception){
            std::cerr << "Can't resize" << std::endl;
        }
        return output;
    }

    cv::Mat ImageProcessing::blur_region(cv::Mat frame, cv::Rect region) {
        cv::GaussianBlur(frame(region), frame(region), cv::Size(0, 0), 4);
        return frame;
    }

    bool ImageProcessing::save_file(std::string file_name, cv::Mat frame) {

        try {
            cv::imwrite(file_name, frame);
            return true;
        }catch (cv::Exception &exception){
            std::cerr<<"File : " << file_name << " was't save" << std::endl;
            return false;
        }
    }

    void ImageProcessing::create_json(std::vector<cv::Rect> &faces, std::string file_name) {
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
        boost::property_tree::json_parser::write_json(file_name+".json", pt);
    }
}