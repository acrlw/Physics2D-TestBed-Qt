#ifndef PHYSICS2D_RENDERER_IMPL_QT_H
#define PHYSICS2D_RENDERER_IMPL_QT_H
#include "QPainter"
#include "QPointF"
#include "QPainterPath"
#include "QPen"
#include "QBrush"

#include "camera.h"
namespace Physics2D
{
    class RendererQtImpl
    {
    public:
        static void renderPoint(QPainter* painter, Camera* camera, const Vector2& point, const QPen& pen);
        static void renderLine(QPainter* painter, Camera* camera, const Vector2& p1, const Vector2& p2, const QPen& pen);
        static void renderPoints(QPainter* painter, Camera* camera, const std::vector<Vector2>& points, const QPen& pen);
        static void renderLines(QPainter* painter, Camera* camera, const std::vector<std::pair<Vector2, Vector2>>& lines, const QPen& pen);

        static void renderShape(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderPolygon(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderEdge(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderRectangle(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderCircle(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderCapsule(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderSector(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderEllipse(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderCurve(QPainter* painter, Camera* camera, const ShapePrimitive& shape, const QPen& pen);
        static void renderAngleLine(QPainter* painter, Camera* camera, const ShapePrimitive& shape);

        static void renderAABB(QPainter* painter, Camera* camera, const AABB& aabb, const QPen& pen);

        static void renderJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);
        static void renderRotationJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);
        static void renderDistanceJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);
        static void renderPointJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);


        static void renderOrientationJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);
        static void renderPulleyJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);
        static void renderPrismaticJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);
        static void renderRevoluteJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);
        static void renderWheelJoint(QPainter* painter, Camera* camera, Joint* joint, const QPen& pen);

    };
}
#endif
