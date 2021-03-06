#pragma once

#include "obstacles/obstacle.h"
#include "geometrycentral/surface/vertex_position_geometry.h"
#include "geometrycentral/surface/halfedge_mesh.h"
#include "spatial/tpe_bvh.h"

namespace LWS {
    using namespace geometrycentral;
    using namespace surface;

    class MeshObstacle : public Obstacle {
        public:
        std::shared_ptr<HalfedgeMesh> mesh;
        std::shared_ptr<VertexPositionGeometry> geometry;

        MeshObstacle(std::shared_ptr<HalfedgeMesh> m, std::shared_ptr<VertexPositionGeometry> geom, double p_exp, double w);
        virtual ~MeshObstacle();
        virtual void AddGradient(PolyCurveNetwork* curves, Eigen::MatrixXd &gradient);
        virtual double ComputeEnergy(PolyCurveNetwork* curves);

        private:
        double p;
        double weight;
        BVHNode3D* bvh;
        double AccumulateEnergy(BVHNode3D* node, Vector3 point);
        Vector3 AccumulateForce(BVHNode3D* node, Vector3 point);
    };
}
