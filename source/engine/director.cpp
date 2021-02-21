#include "director.h"

void clona::director::attach() {

}

void clona::director::detach() {

}

/**
 * 刷新
 * 
 */
void clona::director::update() {
    // 作用物更新状态
    auto actor = actors.begin();
    while (actor != actors.end()) {
        auto now = actor++;
        if (now->second.expired()) {
            actors.erase(now);
        }
    }

    
}