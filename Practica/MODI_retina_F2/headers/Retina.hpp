#ifndef RETINA_HPP
#define RETINA_HPP

#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace cv;
using namespace std;

#define SMALLER_RF 3
#define W_RATIO 1
#define S_RATIO 3
#define N_LAYERS 8
#define SPIKES_LIM 0.6

/**
    Models retina-inspired image processing objects    
*/

/**
    @author Oscar Silva
    @date Sep 30, 2016
*/

class Retina
{
    int     smaller_rf;     // number of pixels spanned by the filter in one axis (must be odd)
    double  w_ratio;        // w_s/w_c
    int     s_ratio;        // sigma_outer/sigma_inner
    int     n_layers;       // number of layers
    double  spikes_lim;     // from 0 to 1. If 0, takes all spikes for reconstruction

    public:

    
    ///  @brief Creates an object of type Retina
    Retina();

    /// @brief Destructor
    ~Retina();

    //Mat GetImg(Mat img, int percentage);
    /** 
     *   @brief Processes a given image
     *   @param img Raw input image
     *   @return The image processed by the retina  
     *
     *  
     *   Processes a given image with the retina algorithm.       
    */
    Mat GetImg(Mat img);
//    vector<unsigned char> GetSpikes(Mat img, int percentage);
//    vector<unsigned char> GetSpikesPosition(Mat img, int percentage);
//    vector<unsigned char> GetFirstSpikes(Mat img, int percentage);
//    vector<unsigned char> GetFirstSpikesPosition(Mat img, int percentage);

    /**
        @brief Filters an image in a Ganglion-cells way
        @param img Raw input image
        @param mx Image amount of pixel columns 
        @param my Image amount of pixel rows
        @param fs1 Number of pixels spanned by the filter in one axis (must be odd)
        @param sigma_inner The inner sigma
        @param type Type of cell: it can be "ON" or "OFF"
        @return The image processed by the Ganglion cell-like filter

        ON and OFF centered Difference of Gaussians filter for selected ganglion cells
    */
    Mat DoG(Mat img, int mx, int my, int fs1, double sigma_inner, string type);

    /**
        @brief Transparent filter
        @param img Raw input image
        @param mx Image amount of pixel columns 
        @param my Image amount of pixel rows
        @param fs1 Number of pixels spanned by the filter in one axis (must be odd)
        @param sigma_inner The inner sigma
        @param type Type of cell: it can be "ON" or "OFF"
        @return The input image without proccessing

        For the moment this function is not yet implemented. It returns the same image given as input.
    */
    Mat reconstruct_DoG(Mat img,int Mx, int My, int fs1, double sigma_inner);

    /** 
        @brief Reverses the order of the bytes 
        @param *img_star Pointer to the first byte of an image
        @param img_size Size of the image in bytes

        Interpreting an image as a vector of bytes, it reverses the order of the elements in the range [first,last)
        so they end up with the form (last, first]. It is equivalent to rotate the image in 180°
    */
    void ReverseBytes( unsigned char * img_star, int img_size );

};

#endif
