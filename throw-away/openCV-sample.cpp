#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <chrono>

int main(int argc, char *argv[]) {
    std::string pipeline = "v4l2src device=/dev/video6 ! videoconvert ! appsink sync=false";


    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);

    char str[200];
    long int microseconds = 0.0;

    if(!cap.isOpened()) {
        std::cout<<"Failed to open camera."<<std::endl;
        return(-1);
    }

    cv::namedWindow("Example", cv::WINDOW_NORMAL);
    cv::Mat img;

    std::cout << "Hit ESC to exit "<<std::endl;
    while(true){
        auto start = std::chrono::high_resolution_clock::now();
        if (!cap.read(img)) {
		    std::cout<<"Capture read error"<<std::endl;
		    break;
	}
        sprintf(str, "%f elapsed time in microseconds", 1000000.0/microseconds);
        cv::putText(img, str, cv::Point(10, img.rows/2),
                cv::FONT_HERSHEY_DUPLEX,
                1.0,
                CV_RGB(118, 185, 0), 2);
        cv::imshow("CSI Camera",img);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        int keycode = cv::waitKey(30) & 0xff ; 
        if (keycode == 27) break ;
    }
    cap.release();
    cv::destroyAllWindows() ;
    return 0;
}