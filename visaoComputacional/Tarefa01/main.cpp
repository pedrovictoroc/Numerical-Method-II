#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
    Mat inputImage;
    Mat outputImage;
    int rows;
    int columns;
    int option;

    inputImage = imread("cubosCreto.png",CV_LOAD_IMAGE_GRAYSCALE);
    outputImage = Mat::zeros(Size(inputImage.cols,inputImage.rows),CV_8UC1);

    if(!inputImage.data){
        cout << "Tem imagem não cara" << endl;
        return -1;
    }


    //Função nativa no openCV para criar bordas
    //copyMakeBorder(src, output, top, bottom, left, right, Border_Type = Border_Constant, grayScale color)
    copyMakeBorder(inputImage, inputImage, 1,1,1,1, BORDER_CONSTANT,0);
    
    //Armazena número de linhas e colunas após adição da borda
    rows = inputImage.rows;
    columns = inputImage.cols;


    cout << "Para Box Blur digite 1 (Calculo com os pixel imediatamente a esquerda, direita, cima e abaixo)" << "\n";
    cout << "Para filtro gauseano digite 2 (Calculo com todos os pixels ao redor)" << "\n";
    cout << "Para Sharppen Effect, digite 3" << "\n";
    cout << "Para Edge Detection, digite 4" << "\n";
    cout << "Para máscara passada pelo Creto, digite 5" << "\n";
    cout << "Para filtro, digite 6" << "\n";
    cin >> option;

    if(option == 1){
        for(int i = 1; i < rows -1; i++){
            for(int j = 1; j < columns -1; j++){
                outputImage.at<uchar>(i-1,j-1) = abs(((int)inputImage.at<uchar>(i-1,j) + (int)inputImage.at<uchar>(i+1,j) + 
                                        (int)inputImage.at<uchar>(i,j-1) + (int)inputImage.at<uchar>(i,j+1))/4);
            }
        }
    }
    else if(option == 2){
        for(int i = 1; i < rows -1; i++){
            for(int j = 1; j < columns -1; j++){
                outputImage.at<uchar>(i-1,j-1) = abs(((int)inputImage.at<uchar>(i-1,j+1) + ((int)inputImage.at<uchar>(i,j+1)*2) + 
                                        (int)inputImage.at<uchar>(i+1,j+1) + ((int)inputImage.at<uchar>(i-1,j)*2) +
                                        ((int)inputImage.at<uchar>(i,j)*4)+ ((int)inputImage.at<uchar>(i+1,j)*2) + 
                                        (int)inputImage.at<uchar>(i-1,j-1) + ((int)inputImage.at<uchar>(i,j-1)*2)+
                                        (int)inputImage.at<uchar>(i+1,j-1)) / 16);
            }
        }
    }
    //Sharppen Effect
    else if(option == 3){
        for(int i = 1; i < rows-1; i++){
            for(int j = 1; j < columns-1; j++){
                outputImage.at<uchar>(i-1,j-1) = abs(5*(int)inputImage.at<uchar>(i,j) - (int)inputImage.at<uchar>(i-1,j) - 
                                        (int)inputImage.at<uchar>(i+1,j) - (int)inputImage.at<uchar>(i,j-1) -
                                        (int)inputImage.at<uchar>(i,j+1));
            }
        }
    }
    //Edge Detection
    else if(option == 4){
        for(int i = 1; i < rows-1; i++){
            for(int j = 1; j < columns-1; j++){
                outputImage.at<uchar>(i-1,j-1) = abs((int)inputImage.at<uchar>(i-1,j) - (int)inputImage.at<uchar>(i,j-1) +
                                        (int)inputImage.at<uchar>(i,j+1) -(int)inputImage.at<uchar>(i+1,j));
            }
        }
    }
    else if(option == 5){
        for(int i = 1; i < rows - 1; i++){
            for(int j = 1; j < columns - 1; j++){
                outputImage.at<uchar>(i-1,j-1) = (abs((static_cast<int>(inputImage.at<uchar>(i+1,j))/2) - (static_cast<int>(inputImage.at<uchar>(i-1,j))/2) +
                                                abs((static_cast<int>(inputImage.at<uchar>(i,j+1))/2) - (static_cast<int>(inputImage.at<uchar>(i,j-1))/2))));
            }
        }
    }
    else if(option == 6){
        for(int i = 1; i < rows-1; i++){
            for(int j = 1; j < columns-1; j++){
                outputImage.at<uchar>(i-1,j-1) = ((int)inputImage.at<uchar>(i-1,j) - (int)inputImage.at<uchar>(i,j-1) +
                                        (int)inputImage.at<uchar>(i,j+1) -(int)inputImage.at<uchar>(i+1,j));
            }
        }
    }
    else{
        cout << "Opção inexistente, tente de novo!" << "\n";
    }



    //Cria a Janela
    namedWindow("Janela Incrivel", WINDOW_AUTOSIZE);
    imshow("Janela Incrivel", inputImage);

    imshow("Janela Incrivel (alterada)", outputImage);

    waitKey();

    return 0;
}
