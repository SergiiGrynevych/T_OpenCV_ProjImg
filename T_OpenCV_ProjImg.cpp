#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;
using namespace cv;

bool ShowImgSize(string &folderPath) {
    cout << endl << "Work with directory: " << folderPath << endl << "------------" << endl;
    
    try 
    {
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
            cerr << "Directory does not exist or is not a directory." << endl;
            return false;
        }

        for (const auto& entry : fs::directory_iterator(folderPath)) {
            string filePath = entry.path().string();
            string fileName = entry.path().filename().string();

            if (fs::is_directory(entry.path())) {
                cout << "Folder found: " << fileName << ", not work with folders" << endl;
                continue;
            }
            else if (fs::is_regular_file(entry.path())) {
                Mat image = imread(filePath);

                if (image.empty()) {
                    cerr << "Failed to load image: " << fileName << endl;
                    continue;
                }

                int width = image.cols;
                int height = image.rows;

                cout << "Image: " << fileName << ". Size: " << width << "x" << height << endl;
            }
            else {
                cout << "Another type of element: " << fileName << ", check this file" << endl;
                continue;
            }        
        }
        return true;
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Filesystem error: " << e.what() << endl;
        cerr << "Error code: " << e.code().value() << " - " << e.code().message() << endl;
        return false;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}

int main()
{
    bool isShowImgSize = false;
    string folderPath = "";

    while (true) {
        cout << "------------" << endl << "Please enter directory to work with image`s: " << folderPath << endl;

        cin >> folderPath;

        isShowImgSize = ShowImgSize(folderPath);

        folderPath = "";

        if (isShowImgSize) {
            cout << "------------" << endl << "End program. Thanks!" << endl;

            this_thread::sleep_for(chrono::milliseconds(10000));
            return 0;
        }
    }
}
