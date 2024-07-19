#include "../Header/ServiceLocator.h"
#include "../Header/EventService.h"
#include "../Header/Playerservice.h"
#include "../Header/TimeService.h"

// Constructor: Initializes the graphic_service pointer to null and creates services.
ServiceLocator::ServiceLocator() {
	graphic_service = nullptr;
	time_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;

	createServices();
}

// Destructor: Cleans up resources by clearing all services.
ServiceLocator::~ServiceLocator() {
	clearAllServices(); // Call clearAllServices to delete any allocated services	
}

// Creates service instances, specifically the graphic service in this case.
void ServiceLocator::createServices() {
	graphic_service = new GraphicService();
	time_service = new TimeService();
	event_service = new EventService();
	player_service = new PlayerService();
}

// Deletes allocated services to prevent memory leaks, specifically the graphic service.
void ServiceLocator::clearAllServices() {
	delete(graphic_service);
	delete(time_service);
	delete(event_service);
	delete(player_service);
}

// Returns a pointer to ServiceLocator.
ServiceLocator* ServiceLocator::getInstance() {
	static ServiceLocator instance; // we will discuss what 'static' means at a later time.
	return &instance; // Return address of the instance
}

// Calls initialize on the graphic service, readying it for use.
void ServiceLocator::initialize() {
	graphic_service->initialize();
	time_service->initialize();
	event_service->initialize();
	player_service->initialize();
}

// Updates the state of the graphic service.
void ServiceLocator::update() {
	graphic_service->update();
	time_service->update();
	event_service->update();
	player_service->update();
}

// Renders using the graphic service.
void ServiceLocator::render() {
	graphic_service->render(); // Render graphic service
	player_service->render();
}

// Returns a pointer to the currently set graphic service.
GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
EventService* ServiceLocator::getEventService() { return event_service; }
PlayerService* ServiceLocator::getPlayerService() { return player_service; }
TimeService* ServiceLocator::getTimeService() { return time_service; }