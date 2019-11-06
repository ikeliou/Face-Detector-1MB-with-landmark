
#include "FaceDetector.h"
#ifdef _WIN32
# define EXPORTED  __declspec( dllexport )
#else
# define EXPORTED
#endif
//namespace retinaFace {
extern "C"
{
    EXPORTED void init(const std::string &model_param, const std::string &model_bin);
    EXPORTED void detectFace(const cv::Mat &mat, std::vector<bbox>& boxes);
}

//}
