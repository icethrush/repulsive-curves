#pragma once

#include <Eigen/Sparse>

namespace LWS {
    class PolyCurveNetwork;

    class ConstraintFunctions {
        public:
        // Differential of barycenter constraint
        static void AddBarycenterTriplets3X(PolyCurveNetwork* curves, std::vector<Eigen::Triplet<double>> &triplets, int rowStart);
        // Differential of total length constraint
        static void AddTotalLengthTriplets(PolyCurveNetwork* curves, std::vector<Eigen::Triplet<double>> &triplets, int rowStart);
        // Differential of edge length constraints
        static void AddEdgeLengthTriplets(PolyCurveNetwork* curves, std::vector<Eigen::Triplet<double>> &triplets, int rowStart);
        // Differential of pinned vertex constraints
        static void AddPinTriplets(PolyCurveNetwork* curves, std::vector<Eigen::Triplet<double>> &triplets, int rowStart);
        // Differential of tangent constraints
        static void AddTangentTriplets(PolyCurveNetwork* curves, std::vector<Eigen::Triplet<double>> &triplets, int rowStart);
        // Differential of implicit surface constraints
        static void AddSurfaceTriplets(PolyCurveNetwork* curves, std::vector<Eigen::Triplet<double>> &triplets, int rowStart);

        static void NegativeBarycenterViolation(PolyCurveNetwork* curves, Eigen::VectorXd &b, Eigen::VectorXd &targets, int rowStart);
        static void NegativeTotalLengthViolation(PolyCurveNetwork* curves, Eigen::VectorXd &b, Eigen::VectorXd &targets, int rowStart);
        static void NegativeEdgeLengthViolation(PolyCurveNetwork* curves, Eigen::VectorXd &b, Eigen::VectorXd &targets, int rowStart);
        static void NegativePinViolation(PolyCurveNetwork* curves, Eigen::VectorXd &b, Eigen::VectorXd &targets, int rowStart);
        static void NegativeTangentViolation(PolyCurveNetwork* curves, Eigen::VectorXd &b, Eigen::VectorXd &targets, int rowStart);
        static void NegativeSurfaceViolation(PolyCurveNetwork* curves, Eigen::VectorXd &b, Eigen::VectorXd &targets, int rowStart);

        static void SetBarycenterTargets(PolyCurveNetwork* curves, Eigen::VectorXd &targets, int rowStart);
        static void SetTotalLengthTargets(PolyCurveNetwork* curves, Eigen::VectorXd &targets, int rowStart);
        static void SetEdgeLengthTargets(PolyCurveNetwork* curves, Eigen::VectorXd &targets, int rowStart);
        static void SetPinTargets(PolyCurveNetwork* curves, Eigen::VectorXd &targets, int rowStart);
        static void SetTangentTargets(PolyCurveNetwork* curves, Eigen::VectorXd &targets, int rowStart);
        static void SetSurfaceTargets(PolyCurveNetwork* curves, Eigen::VectorXd &targets, int rowStart);
    };
}