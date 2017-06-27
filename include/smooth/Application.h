//
// Created by permal on 6/24/17.
//

#pragma once

#include <vector>
#include <esp_log.h>
#include <smooth/ipc/Queue.h>
#include <smooth/Task.h>

namespace smooth
{
    class Application
            : public Task
    {
        public:
            Application(const std::string& name, uint32_t stack_depth, UBaseType_t priority);
            virtual ~Application();

            Application(const Application&) = delete;

            void loop();

            void set_system_log_level(esp_log_level_t level) const;
            typedef smooth::ipc::Queue<system_event_t> AppSystemEventQueue;
            AppSystemEventQueue systemQueue;
        private:
            static esp_err_t event_callback(void* ctx, system_event_t* event);
    };

}