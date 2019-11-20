#pragma once

#include "gradient_constraints.h"

namespace LWS {
    enum class ConstraintType {
        Barycenter, EdgeLengths, Pins, TangentPins
    };

    class PolyCurveNetwork;
    int NumRowsForConstraint(ConstraintType type, PolyCurveNetwork* curve);

    class VariableConstraintSet : public GradientConstraints<VariableConstraintSet> {
        private:
        PolyCurveNetwork* curves;

        public:
        VariableConstraintSet(PolyCurveNetwork* c) {
            curves = c;
        }

        void AddTriplets(std::vector<Eigen::Triplet<double>> &triplets) const;
        int NumConstraintRows() const;
        int NumExpectedCols() const;
        void SetTargetValues(Eigen::VectorXd &targets) const;
        void NegativeConstraintValues(Eigen::VectorXd &b, Eigen::VectorXd &targets) const;
    };
}