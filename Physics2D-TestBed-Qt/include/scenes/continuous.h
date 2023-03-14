#ifndef PHYSICS2D_SCENES_CONTINUOUS_H
#define PHYSICS2D_SCENES_CONTINUOUS_H
#include "frame.h"

namespace Physics2D
{
    class ContinuousFrame : public Frame
    {
    public:
        ContinuousFrame(PhysicsWorld* world, ContactMaintainer* maintainer,
            Tree* tree, DBVH* dbvh, Camera* camera) : Frame("Geometry", world, maintainer, tree, dbvh, camera)
        {

        }
        void load() override
        {
            edge.set({ -200, 0 }, { 200, 0 });
            rect.set(1.0f, 1.0f);
            circle.setRadius(0.1f);
            stick.set(2.0f, 0.25f);
            wall.set(0.3f, 6.0f);

            Body* ground = m_world->createBody();
            ground->setShape(&edge);
            ground->position().set({ 0, 0 });
            ground->setMass(Constant::Max);
            ground->setType(Body::BodyType::Static);
            m_tree->insert(ground);

            //for (real i = 1.0f; i <= 10.0f; i += 1.1f)
            //{
            //    Body* body = m_world->createBody();
            //    body->setShape(&rect);
            //    body->position().set({ 0, i });
            //    body->setType(Body::BodyType::Dynamic);
            //    body->setMass(2.0f);
            //    m_tree->insert(body);
            //}
            //Body* body = m_world->createBody();
            //body->setShape(&wall);
            //body->position().set(3.0f, 2.5f);
            //body->rotation() = Math::degreeToRadian(-60);
            //body->setType(Body::BodyType::Static);
            //body->setMass(100.0f);
            //body->setFriction(0.9f);
            //m_tree->insert(body);

            Body* body = m_world->createBody();
            body->setShape(&wall);
            body->position().set(-3.0f, 2.5f);
            body->rotation() = Math::degreeToRadian(60);
            body->setType(Body::BodyType::Static);
            body->setMass(100.0f);
            body->setFriction(0.9f);
            m_tree->insert(body);

            Body* bullet = m_world->createBody();
            bullet->setShape(&stick);
            bullet->position().set({ 0, 20 });
            bullet->setType(Body::BodyType::Bullet);
            bullet->setMass(5.0f);
            bullet->velocity().set({ 0, -200.0f });
            bullet->angularVelocity() = -100.0f;
            bullet->setFriction(0.9f);
            m_tree->insert(bullet);

        }
        void render(QPainter* painter) override
        {

        }
    private:
        Edge edge;
        Rectangle rect;
        Rectangle stick;
        Rectangle wall;
        Circle circle;
    };
}
#endif
