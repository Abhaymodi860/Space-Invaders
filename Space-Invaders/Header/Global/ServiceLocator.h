#pragma once
#include "../Event/EventService.h"
#include "../Graphic/GraphicService.h"
#include "../PlayerService.h"
#include "../TimeService.h"
#include "../UI/UIService.h"

#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

namespace Global {

    class ServiceLocator {
    public:
        static ServiceLocator* getInstance();
        void initialize();
        void update();
        void render();

        Graphic::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
        UI::UIService* getUIService();

    private:
        Graphic::GraphicService* graphic_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        Time::TimeService* time_service;
        UI::UIService* ui_service;

        ServiceLocator();
        ~ServiceLocator();
        void createServices();
        void clearAllServices();

        static ServiceLocator* instance;
    };
}

#endif // SERVICELOCATOR_H