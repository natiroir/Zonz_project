#*******************************************************************************
# Authors: Herve Chaminaud
#*******************************************************************************

set(EXECUTABLE_NAME splashmem)


add_executable(${EXECUTABLE_NAME} 
    actions.c
    init.c
    main.c
    player.c
    render.c
    world.c
)

target_link_libraries(${EXECUTABLE_NAME} 
    SDL2
)
