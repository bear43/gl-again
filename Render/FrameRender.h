//
// Created by konstantin on 13.12.2020.
//

#ifndef UNTITLED_FRAMERENDER_H
#define UNTITLED_FRAMERENDER_H

#include <vector>
#include <memory>
#include "Renderer.h"
#include "../Utils/Starter.h"

/**
 * Used for only task - render frame after frame in a cycle.
 */
class FrameRender {
private:
    /**
     * Renderer holder.
     */
    static inline std::vector<std::shared_ptr<Renderer>> renderers;
public:
    static void onResizeWindow(GLFWwindow* window, int width, int height);
    /**
     * Making preparations before starting the loop.
     */
    static void init();
    /**
     * Starting the loop.
     */
    static void run();
    /**
     * Adds renderer.
     * @param renderer Target renderer.
     */
    static void addRenderer(const std::shared_ptr<Renderer>& renderer);
    /**
     * Deletes renderer.
     * @param renderer Target renderer.
     */
    static void deleteRenderer(const std::shared_ptr<Renderer>& renderer);
};


#endif //UNTITLED_FRAMERENDER_H
