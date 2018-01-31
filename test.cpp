#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

int main(){
	VideoCapture capture("mitsubishi_768x576.avi"); //로컬에 존재하는 영상을 사용한다. 
	//capture.set(CAP_PROP_FRAME_WIDTH, 480);
	//capture.set(CAP_PROP_FRAME_HEIGHT, 320); 
	//카메라를 사용할 때 비디오 크기 조절하는 부분

	Mat frame;
	Mat gray;
	vector<Rect> found;
	namedWindow("input", 1);

	String fullbody_cascade = "haarcascade_fullbody.xml"; //사용할 학습된 데이터 

	CascadeClassifier fullbody;

	fullbody.load(fullbody_cascade);

	capture >> frame;
	int count = 0;
	while(1)
	{
		capture >> frame;
		
		if(count % 30 == 0){
			cvtColor(frame, gray, CV_BGR2GRAY); // 해당 프레임 이미지의 색을 Gray scale로 변환

			if (frame.empty())
				cout << "hello" << endl;

			fullbody.detectMultiScale(gray, found, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(10,10)); // cascade를 이용해 영상에서 원하는 데이터를 추출

			for(int i=0; i < (int)found.size(); i++){
				rectangle(frame, found[i], Scalar(0,255,0),2); // 추출된 데이터 주변에 사각형을 그림
			}
			imshow("input",frame);
			if (waitKey(1) == 'q')  break;
			count = 1;
		}
		else{
			imshow("input",frame);
			count++;
		}
		
	}
	return 0;
}
