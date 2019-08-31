//
// Created by illidansr on 8/30/19.
//

#ifndef FACE_DETECTION_IMAGE_PROCESSING_HPP
#define FACE_DETECTION_IMAGE_PROCESSING_HPP


#include <opencv2/opencv.hpp>
#include <iostream>
#include <library.h>


namespace image_processing {///< @namespace image_processing
    /*!@class ImageProcessing give tools to process with picture(resize,
     * blur, ROI and so on)
     * @brief Image processing tools
     * @author IllidanSR
     * @version 1.0
     * @date 30.08.19
     * @warning no warning
     * */
    class ImageProcessing {
    public:
        /*!@brief default constructor
         * */
        ImageProcessing();
        /*!@brief main image process picture
         * @param[in] image image file in OpenCV format
         * @param[in] pict_name picture name
         * @details function get path to file, verf is file can be open
         * @author IllidanSR
         * @version 1.0
         * @date 30.08.19
         * @throw if file can't be open - generate cv::Exception */
        void image_processing(cv::Mat image, std::string pict_name);
        ~ImageProcessing() = default;
    private:
        double image_resize_cof_col; ///< @name image resize cof
        double image_resize_cof_row; ///< @name image resize cof
        /*!@brief resize picture and save it
         * @param[in] path path to file
         * @details function get path to file, verf is file can be open
         * @author IllidanSR
         * @version 1.0
         * @date 30.08.19
         * @throw if file can't be open - generate cv::Exception */
        cv::Mat resize_image(cv::Mat frame);

        /*!@brief resize picture
         * @param[in] frame picture in OpenCV type cv::Mat
         * @details function blur region with founded face
         * @author IllidanSR
         * @version 1.0
         * @date 30.08.19
         * @throw if file can't be open - generate cv::Exception */
        cv::Mat blur_region(cv::Mat frame, cv::Rect region);

        /*!@brief save frame
         * @param[in] frame picture in OpenCV type cv::Mat
         * @param[in] file_name file name
         * @details save picture
         * @author IllidanSR
         * @version 1.0
         * @date 30.08.19
         * @throw if file can't be open - generate cv::Exception */
        bool save_file(std::string file_name, cv::Mat frame);




    };
}


#endif //FACE_DETECTION_IMAGE_PROCESSING_HPP
