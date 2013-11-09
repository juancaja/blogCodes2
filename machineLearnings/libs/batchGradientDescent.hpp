#ifndef BATCHGRADIENTDESCENT_HPP
#define BATCHGRADIENTDESCENT_HPP

#include <opencv2/core/core.hpp>

/**
 * implement batch gradient descent, not an effecient implementation, but
 * should be easy to read
 **/

/**
 *@brief linear regression
 *@param features input sequence
 *@param labels output sequence
 *@param theta the parameters we want to find
 *@return new theta
 */
template<typename T>
cv::Mat_<T> linear_regression(cv::Mat_<T> const &features, cv::Mat_<T> const &labels, cv::Mat_<T> const &theta)
{
    cv::Mat_<T> result = features.clone(); //m*n
    cv::transpose(result, result); //n*m
    result *= (features * theta - labels); //n*m x (m*n x n*1 - m*1) = n*m x m*1 = n*1

    return result;
}

/**
 *@brief batch gradient descent
 *@param features input sequence
 *@param labels output sequence
 *@param alpha determine the step of each iteration, smaller alpha would cause longer time to iterate but with higher
 * chance to converge;larger a;pha will run faster but with higher chance to divert.
 * Since this function has a fixed iteration time, so alpha only affect accuracy.
 *@param iterate iterate time
 *@return theta, the parameters of batch gradient descent searching
 */
template<typename T>
cv::Mat_<T> batch_gradient_descent(cv::Mat_<T> const &features, cv::Mat_<T> const &labels, T alpha = 0.07, size_t iterate = 1)
{
    cv::Mat_<T> theta = cv::Mat_<T>::zeros(features.cols, 1);
    T const ratio = alpha / features.rows;
    for(size_t i = 0; i != iterate; ++i){
        cv::Mat_<T> const data = ratio * linear_regression(features, labels, theta);
        theta -= data;
    }

    return theta;
}

#endif // BATCHGRADIENTDESCENT_HPP