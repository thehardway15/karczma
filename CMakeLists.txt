cmake_minimum_required(VERSION 3.23)
project(Karczma)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(views)

configure_file(${CMAKE_SOURCE_DIR}/static/restaurant_menu.json ${CMAKE_CURRENT_BINARY_DIR}/restaurant_menu.json COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/static/restaurant_details.json ${CMAKE_CURRENT_BINARY_DIR}/restaurant_details.json COPYONLY)


add_executable(Karczma
        models/orderItem.h
        views/author.cpp
        views/food_details.cpp
        views/menu.cpp
        views/order.cpp
        views/username.cpp
        views/delivery_address.cpp
        views/delivery_choice.cpp
        views/summary.cpp
        views/table_choice.cpp
        views/restaurant_details.cpp
        views/views.h
        config.h
        i18n.cpp
        main.cpp
        utils.cpp
        utils.h models/restaurantDetails.h)

