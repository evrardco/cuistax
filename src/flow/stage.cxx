#include "stage.hxx"

Stage::Stage(int target_fps, cui_context_t * context, Scene * current) : 
    target_fps(target_fps), 
    current_scene(current)
{
    engine_loop(this, &context->backend_ctx);
}

int Stage::get_target_fps() {
    return this->target_fps;
}

void Stage::set_target_fps(int targetFps) {
    this->target_fps = targetFps;
}

Scene * Stage::get_current_scene() {
    return this->current_scene;
}
