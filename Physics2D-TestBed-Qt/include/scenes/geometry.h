#ifndef PHYSICS2D_SCENES_GEOMETRY_H
#define PHYSICS2D_SCENES_GEOMETRY_H
#include "./include/frame.h"

namespace Physics2D
{
	class GeometryFrame : public Frame
	{
	public:
		GeometryFrame(PhysicsWorld* world, ContactMaintainer* maintainer,
			Tree* tree, DBVH* dbvh, Camera* camera) : Frame("Geometry", world, maintainer, tree, dbvh, camera)
		{

		}
		void load() override
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> dist1(-20.0f, 5.0f);
			std::uniform_real_distribution<> dist2(-5.0f, 20.0f);

			for (int i = 0; i < 500; i++)
				points1.emplace_back(Vector2(dist1(gen), dist1(gen)));

			convex1 = GeometryAlgorithm2D::grahamScan(points1);

			for (int i = 0; i < 500; i++)
				points2.emplace_back(Vector2(dist2(gen), dist2(gen)));

			convex2 = GeometryAlgorithm2D::grahamScan(points2);
			intersectionConvex = GeometryAlgorithm2D::Clipper::sutherlandHodgmentPolygonClipping(convex1, convex2);

		}
		void render(QPainter* painter) override
		{
			QPen cyan(Qt::cyan, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
			QPen magenta(Qt::magenta, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
			QPen green(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
			QPen red(QColor("#F44336"), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
			QPen blue(QColor("#03A9F4"), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
			for (int i = 0; i < convex1.size() - 1; i++)
				RendererQtImpl::renderLine(painter, m_camera, convex1[i], convex1[i + 1], green);


			for (int i = 0; i < convex2.size() - 1; i++)
				RendererQtImpl::renderLine(painter, m_camera, convex2[i], convex2[i + 1], blue);

			for (int i = 0; i < intersectionConvex.size() - 1; i++)
				RendererQtImpl::renderLine(painter, m_camera, intersectionConvex[i], intersectionConvex[i + 1], red);


			RendererQtImpl::renderPoints(painter, m_camera, points1, cyan);
			RendererQtImpl::renderPoints(painter, m_camera, points2, magenta);
		}
	private:
		std::vector<Vector2> points1;
		std::vector<Vector2> points2;
		std::vector<Vector2> convex1;
		std::vector<Vector2> convex2;
		std::vector<Vector2> intersectionConvex;
	};
}
#endif