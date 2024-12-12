#pragma once
#include "scene.hxx"
#include <thread>
#include "../cuistax/cui_engine.hxx"

class Stage {
    public:
        /**
        * Initializes the main stage. 
        * @param target_fps self explanatory, -1 for unlimited fps
        * @param context the cuistax backend. Only supports cui_SDL_context_t as of now
        * @param current the scene to set as the current scene, cannot be NULL
        * 
        **/
        Stage(int target_fps, cui_context_t * context, Scene * current);
        /**
         * @brief Set the current scene to the given parameter
         * @param scene the scene to set
         * @return true if the scene changed
         * @return false the scene could not changes
         */
        bool set_scene(Scene * scene);
        /**
         * @brief Trie²s to set the playing state to playing
         * 
         * @param playing the target playing state
         * @return true if the playing state is valid
         * @return false if the playing state is invalid
         */
        bool set_playing(bool playing);
        /**
         * @brief Returns the playing state of the engine
         * 
         * @return true if the engine is playing
         * @return false otherwise
         */
        bool is_playing();

        //----------------------
        // GETTERS AND SETTERS |
        //----------------------
        int get_target_fps();
        void set_target_fps(int targetFps);
        Scene * get_current_scene();
    protected:
        Scene * current_scene;
        bool playing;
        int target_fps;
    private:

};

void engine_loop(Stage * stage, cui_backend_context_t * back_ctx);
