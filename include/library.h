#ifndef FDETECTLIB_LIBRARY_H
#define FDETECTLIB_LIBRARY_H

#include <string>
#include <vector>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <opencv2/opencv.hpp>

namespace face_detect {///< @namespace face_detect

    /*!@brief main function to find face on picture
     * @param[in] path path to file
     * @details function get path to file, verf is file can be open
     * @author IllidanSR
     * @version 1.0
     * @date 30.08.19
     * @throw if file can't be open - generate cv::Exception */
    std::vector<cv::Rect> find_face(cv::Mat frame);


}
#endif //FDETECTLIB_LIBRARY_H