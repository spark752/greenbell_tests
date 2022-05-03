// Minimal Greenbell testing to make sure an application can be built against
// Greenbell and the third party libraries are included. This is mostly a 
// compile test and not intended to be an extensive test of functionality.

#include "gb_glm.h"
#include "gb_fmt.h"
#include "gb_math.h"
#include "window.h"
#include "SDL2/SDL.h"

// Test that SDL has been dynamically linked and basic OpenGL works
void graphics() {    
    Greenbell::WindowInfo win_info;
    Greenbell::Window win{win_info};
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        win.start_frame();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        Greenbell::GL::Clear();
        win.end_frame(Greenbell::LIMITER_200_FPS);
    }
}

// Run tests
int main() {
    // Test that the fmt library is included
    fmt::print(fg(fmt::color::green), "Hello from the fmt library!\n");
   
    // Test that glm is included
    const glm::vec4 v1{2.0f, 2.0f, 2.0f, 2.0f};
    const glm::vec4 v2{1.0f, 2.4f, 3.7f, 4.2f};
    const auto v3 = v1 * v2;
    fmt::print("Vector test {} {} {} {}\n", v3.x, v3.y, v3.z, v3.w);
    
    // Test other things
    graphics();
    
    return 0;
}
