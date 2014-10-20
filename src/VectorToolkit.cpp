//=======================================================================
/** @file VectorToolkit.cpp
 *  @brief Useful methods whe working with STL vectors
 *  @author Adam Stark
 *  @copyright Copyright (C) 2014  Adam Stark
 *
 * This file is part of the Vector Toolkit library
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
//=======================================================================

#include "VectorToolkit.h"
#include <math.h>

//============================================================
template <class T>
bool VectorToolkit<T>::isEmpty(std::vector<T> v)
{
    return (v.size() == 0);
}

//============================================================
template <class T>
bool VectorToolkit<T>::containsOnlyZeros(std::vector<T> v)
{
    if (!isEmpty(v))
    {
        for (int i = 0;i < v.size();i++)
        {
            if (v[i] != 0)
            {
                return false;
            }
        }
        
        return true;
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when checking if vector contains only zeros" );
    }
}

//============================================================
template <class T>
bool VectorToolkit<T>::isAllPositive(std::vector<T> v)
{
    if (!isEmpty(v))
    {
        for (int i = 0;i < v.size();i++)
        {
            if (v[i] < 0)
            {
                return false;
            }
        }
        
        return true;
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when checking if vector is all positive" );
    }
}

//============================================================
template <class T>
bool VectorToolkit<T>::isAllNegative(std::vector<T> v)
{
    if (!isEmpty(v))
    {
        for (int i = 0;i < v.size();i++)
        {
            if (v[i] > 0)
            {
                return false;
            }
        }
        
        return true;
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when checking if vector is all negative" );
    }
}

//============================================================
template <class T>
bool VectorToolkit<T>::contains(std::vector<T> v, T element)
{
    for (int i = 0;i < v.size();i++)
    {
        if (v[i] == element)
        {
            return true;
        }
    }
    
    return false;
}


//============================================================
template <class T>
T VectorToolkit<T>::max(std::vector<T> v)
{
    // if the vector isn't empty
    if (!isEmpty(v))
    {
        // set the first element as the max
        T maxVal = v[0];
        
        // then for each subsequent value
        for (int i = 1;i < v.size();i++)
        {
            // if it is larger than the max
            if (v[i] > maxVal)
            {
                // store it as the new max value
                maxVal = v[i];
            }
        }
        
        // return the maxVal
        return maxVal;
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when calculating max" );
    }
}

//============================================================
template <class T>
int VectorToolkit<T>::maxIndex(std::vector<T> v)
{
    // if the vector isn't empty
    if (!isEmpty(v))
    {
        // set the first element as the max
        T maxVal = v[0];
        int maxIndex = 0;
        
        // then for each subsequent value
        for (int i = 1;i < v.size();i++)
        {
            // if it is larger than the max
            if (v[i] > maxVal)
            {
                // store it as the new max value
                maxVal = v[i];
                
                // store the index as the new max index
                maxIndex = i;
            }
        }
        
        // return the max index
        return maxIndex;
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when calculating max index" );
    }
}

//============================================================
template <class T>
T VectorToolkit<T>::min(std::vector<T> v)
{
    // if the vector isn't empty
    if (!isEmpty(v))
    {
        // set the first element as the min
        T minVal = v[0];
        
        // then for each subsequent value
        for (int i = 1;i < v.size();i++)
        {
            // if it is smaller than the min
            if (v[i] < minVal)
            {
                // store it as the new min value
                minVal = v[i];
            }
        }
        
        // return the minVal
        return minVal;
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when calculating min" );
    }
}

//============================================================
template <class T>
int VectorToolkit<T>::minIndex(std::vector<T> v)
{
    // if the vector isn't empty
    if (!isEmpty(v))
    {
        // set the first element as the min
        T minVal = v[0];
        int minIndex = 0;
        
        // then for each subsequent value
        for (int i = 1;i < v.size();i++)
        {
            // if it is smaller than the min
            if (v[i] < minVal)
            {
                // store it as the new min value
                minVal = v[i];
                
                // store the index as the new min index
                minIndex = i;
            }
        }
        
        // return the min index
        return minIndex;
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when calculating minIndex" );
    }
}

//============================================================
template <class T>
void VectorToolkit<T>::printVector(std::vector<T> v)
{
    for (int i = 0;i < v.size();i++)
    {
        std::cout << v[i] << std::endl;
    }
}

//============================================================
template <class T>
T VectorToolkit<T>::getLastElement(std::vector<T> v)
{
    // if vector is not empty
    if (v.size() > 0)
    {
        return v[v.size()-1];
    }
    else
    {
        throw std::invalid_argument( "Attempted to get last element of empty vector" );
    }
}

//============================================================
template <class T>
T VectorToolkit<T>::getFirstElement(std::vector<T> v)
{
    // if vector is not empty
    if (v.size() > 0)
    {
        return v[0];
    }
    else
    {
        throw std::invalid_argument( "Attempted to get first element of empty vector" );
    }
}

//============================================================
template <class T>
void VectorToolkit<T>::fillVectorWith(std::vector<T> &v,T element)
{
    for (int i = 0;i < v.size();i++)
    {
        v[i] = element;
    }
}

//============================================================
template <class T>
int VectorToolkit<T>::countOccurrencesOf(std::vector<T> v,T element)
{
    int count = 0;
    
    for (int i = 0;i < v.size();i++)
    {
        if (v[i] == element)
        {
            count++;
        }
    }
    
    return count;
}

//============================================================
template <class T>
T VectorToolkit<T>::sum(std::vector<T> v)
{
    // create a sum
    T sumVal = 0;
    
    // add up all elements
    for (int i = 0;i < v.size();i++)
    {
        sumVal += v[i];
    }
    
    // return
    return sumVal;
}

//============================================================
template <class T>
double VectorToolkit<T>::product(std::vector<T> v)
{
    if (!isEmpty(v))
    {
        double prod = (double) v[0];
        
        for (int i = 1;i < v.size();i++)
        {
            prod *= ((double) v[i]);
        }
        
        return prod;
    }
    else
    {
        throw std::invalid_argument( "Attempted to calculate the product of an empty vector" );
    }
}

//============================================================
template <class T>
double VectorToolkit<T>::mean(std::vector<T> v)
{
    // if vector is not empty
    if (!isEmpty(v))
    {
        // store the length of the vector as a double
        double L = (double) v.size();
        
        // stor the sum of the vector as a double
        double sumVal = (double) sum(v);
        
        // return the mean
        return sumVal / L;
    }
    else // vector is empty
    {
        throw std::invalid_argument( "Received empty vector when calculating mean" );
    }
}

//============================================================
template <class T>
double VectorToolkit<T>::geometricMean(std::vector<T> v)
{
    // if vector is not empty
    if (!isEmpty(v))
    {
        double sumVal = 0.0;
        double count = 0;
        
        // sum the log of all values
        for (int i = 0;i < v.size();i++)
        {
            // NB: we ignore zero values
            if (v[i] != 0)
            {
                sumVal += log(v[i]);
                count = count + 1;
            }
        }
    
        // return the geometric mean as the exponential of the average of the sum of logs
        return exp(sumVal / count);
    }
    else // vector is empty
    {
        throw std::invalid_argument( "Received empty vector when calculating geometric mean" );
    }
}

//============================================================
template <class T>
double VectorToolkit<T>::median(std::vector<T> v)
{
    // if vector isn't empty
    if (!isEmpty(v))
    {
        double median;
        size_t L = v.size(); // store the size
        
        // sort the vector
        sort(v.begin(), v.end());
        
        // if the length is even
        if (L  % 2 == 0)
        {
            // take the average of the middle two elements
            median = (v[L / 2 - 1] + v[L / 2]) / 2;
        }
        else // if the length is odd
        {
            // take the middle element
            median = v[L / 2];
        }
        
        // return the median
        return median;
    }
    else // vector is empty
    {
        throw std::invalid_argument( "Received empty vector when calculating median" );
    }
}

//============================================================
template <class T>
double VectorToolkit<T>::variance(std::vector<T> v)
{
    if (!isEmpty(v))
    {
        // calculate the mean of the vector
        double mu = mean(v);
        
        double sumVal = 0.0;
        
        // sum the product of all differences from the mean
        for (int i = 0;i < v.size();i++)
        {
            double diff = v[i]-mu;
            sumVal += diff*diff;
        }
        
        // return the average of the squared differences
        return sumVal / ((double)v.size());
    }
    else
    {
        throw std::invalid_argument( "Received empty vector when calculating variance" );
    }
}

//============================================================
template <class T>
double VectorToolkit<T>::standardDeviation(std::vector<T> v)
{
    // if vector is not empty
    if (!isEmpty(v))
    {
        // calculate the variance
        double var = variance(v);
        
        // if variance is non-zero
        if (var > 0)
        {
            // return the square root
            return sqrt(var);
        }
        else
        {
            // all differences are zero, so return 0.0
            return 0.0;
        }
    }
    else // vector is empty
    {
        throw std::invalid_argument( "Received empty vector when calculating standard deviation" );
    }
}

//============================================================
template <class T>
void VectorToolkit<T>::multiplyInPlace(std::vector<T> &v,T scalar)
{
    for (int i = 0;i < v.size();i++)
    {
        v[i] *= scalar;
    }
}

//============================================================
template <class T>
void VectorToolkit<T>::divideInPlace(std::vector<T> &v,T scalar)
{
    if (scalar != 0)
    {
        for (int i = 0;i < v.size();i++)
        {
            v[i] /= scalar;
        }
    }
    else
    {
        throw std::invalid_argument( "Attemted to divide a vector by a zero-valued scalar" );
    }
}

//============================================================
template <class T>
void VectorToolkit<T>::addInPlace(std::vector<T> &v,T value)
{
    for (int i = 0;i < v.size();i++)
    {
        v[i] += value;
    }
}

//============================================================
template <class T>
void VectorToolkit<T>::subtractInPlace(std::vector<T> &v,T value)
{
    for (int i = 0;i < v.size();i++)
    {
        v[i] -= value;
    }
}

//============================================================
template <class T>
void VectorToolkit<T>::absInPlace(std::vector<T> &v)
{
    for (int i = 0;i < v.size();i++)
    {
        if ((v[i] < 0) || (v[i] == -0.0))
        {
            v[i] *= -1;
        }
    }
}


//============================================================
template <class T>
std::vector<T> VectorToolkit<T>::multiply(std::vector<T> v,T scalar)
{
    std::vector<T> result;

    for (int i = 0;i < v.size();i++)
    {
        result.push_back(v[i] * scalar);
    }
    
    return result;
}

//============================================================
template <class T>
std::vector<T> VectorToolkit<T>::divide(std::vector<T> v,T scalar)
{
    if (scalar != 0)
    {
        std::vector<T> result;
        
        for (int i = 0;i < v.size();i++)
        {
            result.push_back(v[i] / scalar);
        }
        
        return result;
    }
    else
    {
        throw std::invalid_argument( "Attemted to divide a vector by a zero-valued scalar" );
    }
}

//============================================================
template <class T>
std::vector<T> VectorToolkit<T>::add(std::vector<T> v,T value)
{
    std::vector<T> result;
    
    for (int i = 0;i < v.size();i++)
    {
        result.push_back(v[i] + value);
    }
    
    return result;
}

//============================================================
template <class T>
std::vector<T> VectorToolkit<T>::subtract(std::vector<T> v,T value)
{
    std::vector<T> result;
    
    for (int i = 0;i < v.size();i++)
    {
        result.push_back(v[i] - value);
    }
    
    return result;
}

//============================================================
template <class T>
std::vector<T> VectorToolkit<T>::abs(std::vector<T> v)
{
    std::vector<T> result;
    
    for (int i = 0;i < v.size();i++)
    {
        if ((v[i] < 0) || (v[i] == -0.0))
        {
            result.push_back(-1*v[i]);
        }
        else
        {
            result.push_back(v[i]);
        }
    }
    
    return result;
}

//=======================================================================
template class VectorToolkit<float>;
template class VectorToolkit<double>;
template class VectorToolkit<int>;
template class VectorToolkit<long>;