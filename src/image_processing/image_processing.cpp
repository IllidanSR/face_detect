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
        save_file("output/"+pict_name, blur_image);

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
}