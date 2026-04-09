#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include<iostream>

#include "MyVector2.h"
#include "Circle.h"

#include "CollisionManager.h"
#include "CollisionEvent.h"

int main()
{
    const float fixedDt = 1.0f / 60.0f;
    const float width = 800;
    const float height = 800;

    std::vector<PhysicsObject*> physObjs;
    std::vector<CollisionEvent> collisionEvents;

    MyVector2 origin = { 800 / 2, 800 / 2 };

    for (int i = 0; i < 4; i++)
    {
        Circle* c = new Circle( 50.0f, sf::Color::Blue );
       
        //c->SetPosition(origin);
        //c->UpdateRenderPosition();

        physObjs.push_back(c);
    }

    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "I'm Ballin");
    window.setFramerateLimit(60);

    physObjs[0]->SetPosition(100, 400);
    physObjs[0]->UpdateRenderPosition();
    physObjs[1]->SetPosition(origin);
    physObjs[1]->UpdateRenderPosition();

    physObjs[2]->SetPosition(100, 600);
    physObjs[2]->UpdateRenderPosition();

    physObjs[3]->SetPosition(500, 200);
    physObjs[3]->UpdateRenderPosition();
   
    physObjs[0]->SetAcceleration(10000, 1000);
    physObjs[1]->SetAcceleration(20000, 1000);
    physObjs[2]->SetAcceleration(1000, 10000);
    physObjs[3]->SetAcceleration(-10000, 5000);
    //physObjs[4]->SetAcceleration(5000, 5000);


    while (window.isOpen())
    {  
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();

        collisionEvents.clear();


        for (int i = 0; i < physObjs.size(); i++)
        {
            physObjs[i]->ApplyAccelerationAndVelocity(fixedDt);
            

            for (int j = i + 1; j < physObjs.size(); j++)
            {
                CollisionEvent c = { physObjs[i], physObjs[j] };
                collisionEvents.push_back(c);


            }

            NarrowPhase(collisionEvents);

            physObjs[i]->CheckBounds(width, height);

            physObjs[i]->UpdateRenderPosition();
            physObjs[i]->SetAcceleration(0, 0);
            physObjs[i]->Draw(window);
        }
       
        window.display();
    }
}