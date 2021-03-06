////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     BinaryErrorAggregator.h (evaluators)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// stl
#include <string>
#include <vector>

namespace ell
{
namespace evaluators
{
    /// <summary> An evaluation aggregator that computes a binary confusion matrix. </summary>
    class BinaryErrorAggregator
    {
    public:
        /// <summary> Updates this aggregator. </summary>
        ///
        /// <param name="prediction"> The real valued prediction. </param>
        /// <param name="label"> The label. </param>
        /// <param name="weight"> The weight. </param>
        void Update(double prediction, double label, double weight);

        /// <summary> Returns the current value. </summary>
        ///
        /// <returns> The current value. </returns>
        std::vector<double> GetResult() const;

        /// <summary> Resets the aggregator to its initial state. </summary>
        void Reset();

        /// <summary> Gets a header that describes the values of this aggregator. </summary>
        ///
        /// <returns> The header string vector. </returns>
        std::vector<std::string> GetValueNames() const;

    private:
        double _sumTruePositives = 0.0;
        double _sumTrueNegatives = 0.0;
        double _sumFalsePositives = 0.0;
        double _sumFalseNegatives = 0.0;
    };
}
}
