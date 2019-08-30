//
// Created by illidansr on 8/30/19.
//

#include "image_processing.hpp"

namespace image_processing{

    void ImageProcessing::image_processing(cv::Mat image, std::string pict_name) {
        blur_region(image)
    }

    cv::Mat ImageProcessing::resize_image(cv::Mat frame) {
        cv::Mat output;
        cv::resize(frame, output, cv::Size(frame.cols*0.5, frame.rows*0.5), 0, 0,  CV_INTER_LINEAR);
        cv::imwrite("test.jpg",output);
        return output;
    }

    cv::Mat ImageProcessing::blur_region(cv::Mat frame, cv::Rect region) {
        cv::GaussianBlur(frame(region), frame(region), cv::Size(0, 0), 4);
        return frame;
    }

    bool ImageProcessing::save_file(std::string file_name, cv::Mat &frame) {

        try {
            cv::imwrite(file_name, frame);
            return true;
        }catch (cv::Exception &exception){
            std::cerr<<"File : " << file_name << " was't save" << std::endl;
            return false;
        }


    }
}