#include "mod/MyMod.h"

#include "ll/api/mod/RegisterHelper.h"

namespace my_mod {

MyMod& MyMod::getInstance() {
    static MyMod instance;
    return instance;
}

bool MyMod::load() {
    getSelf().getLogger().info("Loading...");
    // Code for loading the mod goes here.
    return true;
}

bool MyMod::enable() {
    getSelf().getLogger().info("Enabling...");
    // Code for enabling the mod goes here.
    return true;
}

bool MyMod::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the mod goes here.
    return true;
}

bool MyMod::unload() {
    getSelf().getLogger().info("卸载");
    return true;
}

} // namespace my_mod

LL_REGISTER_MOD(my_mod::MyMod, my_mod::MyMod::getInstance());
