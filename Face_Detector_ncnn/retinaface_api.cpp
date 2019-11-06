
#include "retinaface_api.h"

Detector *detector=NULL;

void init(const std::string &model_param, const std::string &model_bin) {
    detector = new Detector(model_param, model_bin);
}

void detectFace(const cv::Mat &img, std::vector<bbox>& boxes) {
    // scale
    const int max_side = 320;
    float long_side = std::max(img.cols, img.rows);
    float scale = max_side/long_side;
    cv::Mat img_scale;
    cv::resize(img, img_scale, cv::Size(img.cols*scale, img.rows*scale));
    detector->Detect(img_scale, boxes);
    for (unsigned int j = 0; j < boxes.size(); ++j) {
        auto &box=boxes[j];
        box.x1/=scale;
        box.y1/=scale;
        box.x2/=scale;
        box.y2/=scale;
        for (int k=0; k<5; ++k) {
            box.point[k]._x/=scale;
            box.point[k]._y/=scale;
        }
    }
}

void release() {
    delete detector;
}
